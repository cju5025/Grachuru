#pragma once
#include "GrachuruAudioHelpers.h"

enum GrachuruType
{
    kGrachuruType_Delay = 0,
    kGrachuruType_Chorus
};

class GrachuruDelay
{
public:
    GrachuruDelay();
    ~GrachuruDelay();
    
    void setSampleRate(double inSampleRate);
    
    void reset();
    
    void process(float* inAudio,
                 float inTime,
                 float inFeedback,
                 float inWetDry,
                 float inType,
                 float* inModulationBuffer,
                 float* outAudio,
                 int inNumSamplesToRender);
    
private:
    
    double getInterpolatedSample(float inDelayTimeInSamples);
    int returnRandomNumber();
    
    double mSampleRate;
    double mBuffer[maxBufferSize];
    double mFeedbackSample;
    
    float mTimeSmoothed;
    
    int mDelayIndex;
};
