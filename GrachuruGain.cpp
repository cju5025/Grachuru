#include "GrachuruGain.h"
#include "JuceHeader.h"

GrachuruGain::GrachuruGain()
:   mGainSmoothed(0.0f)
{
    
}

GrachuruGain::~GrachuruGain()
{
    
}

void GrachuruGain::process(float* inAudio,
                       float inGain,
                       float* outAudio,
                       int inNumSamplesToRender)
{
    float gainMapped = jmap(inGain, 0.0f, 1.0f, -24.0f, 24.0f);
    gainMapped = Decibels::decibelsToGain(gainMapped, -24.0f);
        
    for (int i = 0; i < inNumSamplesToRender; i++)
    {
        mGainSmoothed -= 0.0004 * (mGainSmoothed - gainMapped);
        outAudio[i] = inAudio[i] * mGainSmoothed;
    };
}
