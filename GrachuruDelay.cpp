#include "GrachuruDelay.h"
#include "JuceHeader.h"

GrachuruDelay::GrachuruDelay()
:   mSampleRate(-1),
    mFeedbackSample(0.0f),
    mTimeSmoothed(0.0f),
    mDelayIndex(0)
{
    
}

GrachuruDelay::~GrachuruDelay()
{
    
}

void GrachuruDelay::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void GrachuruDelay::reset()
{
    mTimeSmoothed = 0.0f;
    
    zeromem(mBuffer, (sizeof(double) * maxBufferSize));
}

void GrachuruDelay::process(float* inAudio,
                        float inTime,
                        float inFeedback,
                        float inWetDry,
                        float inType,
                        float* inModulationBuffer,
                        float* outAudio,
                        int inNumSamplesToRender)
{
    const float wet = inWetDry;
    const float dry = 1.0f - wet;
    const float feedbackMapped = jmap(inFeedback, 0.0f, 1.0f, 0.0f, 0.98f);
    
    for (int i = 0; i < inNumSamplesToRender; i++)
    {
        
        if ((int)inType == kGrachuruType_Delay)
        {
            mTimeSmoothed -= smoothingCoefficient_Fine * (mTimeSmoothed - inTime);

        } else {
            const double delayTimeModulation = (0.003 + (0.002f * inModulationBuffer[i]));
            mTimeSmoothed -= smoothingCoefficient_Fine * (mTimeSmoothed - delayTimeModulation);
        }
        
        
        const double delayTimeInSamples = (mTimeSmoothed * mSampleRate);
        const double sample = getInterpolatedSample(delayTimeInSamples);
        
        mBuffer[mDelayIndex] = inAudio[i] + (mFeedbackSample * feedbackMapped);
        
        mFeedbackSample = sample;
        
        outAudio[i] = (inAudio[i] * dry + sample * wet);
        
        mDelayIndex += returnRandomNumber(inNumSamplesToRender);
        
        if (mDelayIndex > maxBufferSize)
        {
            mDelayIndex -= maxBufferSize;
        }
    }
}

double GrachuruDelay::getInterpolatedSample(float inDelayTimeInSamples)
{
    double readPosition = (double)mDelayIndex - inDelayTimeInSamples;
    
    if(readPosition < 0.0f)
    {
        readPosition += maxBufferSize;
    }
    
    int index_y0 = (int)readPosition - 1;
    if (index_y0 < 0)
    {
        index_y0 += maxBufferSize;
    }
    
    int index_y1 = readPosition;
    if (index_y1 > maxBufferSize)
    {
        index_y1 -= maxBufferSize;
    }
    
    const float sample_y0 = mBuffer[index_y0];
    const float sample_y1 = mBuffer[index_y1];
    const float t = readPosition - (int)readPosition;
    
    double outSample = linearInterpolation(sample_y0, sample_y1, t);
    
    return outSample;
}

int GrachuruDelay::returnRandomNumber (int maxNumber)
{
    //return a random number, bounds are changed by parameter (so not so random)
    return 1;
}

