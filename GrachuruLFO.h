#pragma once
#include "GrachuruAudioHelpers.h"

class GrachuruLFO
{
public:
    GrachuruLFO();
    ~GrachuruLFO();
    
    void reset();
    
    void setSampleRate(double inSampleRate);
    
    void process(float inRate, float inDepth, int inNumSamples);
    
    float* getBuffer();
    
private:
    
    double mSampleRate;
    
    float mPhase;
    
    float mBuffer[maxBufferSize];
};
