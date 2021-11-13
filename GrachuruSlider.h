#pragma once
#include "JuceHeader.h"

class GrachuruParameterSlider
:   public Slider
{
public:
    
    GrachuruParameterSlider(AudioProcessorValueTreeState& stateToControl,
                        const String& parameterID);
    
    ~GrachuruParameterSlider();
        
private:
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GrachuruParameterSlider);
};
