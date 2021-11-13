#pragma once
#include "JuceHeader.h"

class GrachuruParameterComboBox
:   public ComboBox
{
public:
    
    GrachuruParameterComboBox(AudioProcessorValueTreeState& stateToControl,
                          const String& parameterID);
    ~GrachuruParameterComboBox();
    
private:
    
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GrachuruParameterComboBox);
};

