#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "GrachuruMainPanel.h"
#include "GrachuruLookAndFeel.h"

class GrachuruAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    GrachuruAudioProcessorEditor (GrachuruAudioProcessor&);
    ~GrachuruAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    GrachuruAudioProcessor& audioProcessor;
    
    std::unique_ptr<GrachuruMainPanel> mMainPanel;
    std::unique_ptr<GrachuruLookAndFeel> mLookAndFeel;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GrachuruAudioProcessorEditor)
};
