#pragma once

class GrachuruGain
{
public:
    
    GrachuruGain();
    ~GrachuruGain();
    
    void process(float* inAudio,
                  float inGain,
                  float* outAudio,
                  int inNumSamplesToRender);
    
private:
    float mGainSmoothed;
};
