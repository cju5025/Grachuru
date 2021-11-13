#include "GrachuruLFO.h"
#include "JuceHeader.h"

GrachuruLFO::GrachuruLFO()
{
    reset();
}

GrachuruLFO::~GrachuruLFO()
{
    
}

void GrachuruLFO::reset()
{
    mPhase = 0.0f;
    zeromem(mBuffer, sizeof(float) * maxBufferSize);
}

void GrachuruLFO::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void GrachuruLFO::process(float inRate, float inDepth, int inNumSamples)
{
    const float rate = jmap(inRate, 0.0f, 1.0f, 0.01f, 10.0f);
    
    for (int i = 0; i < inNumSamples; i++)
    {
        mPhase += (rate / mSampleRate);
        
        if (mPhase > 1)
        {
            mPhase -= 1.0f;
        }
        
        const float LFOPosition = sinf(mPhase * TWO_PI) * inDepth;
        
        mBuffer[i] = LFOPosition;
    }
}

float* GrachuruLFO::getBuffer()
{
    return mBuffer;
}
