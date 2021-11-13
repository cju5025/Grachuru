#include "PluginProcessor.h"
#include "PluginEditor.h"

GrachuruAudioProcessorEditor::GrachuruAudioProcessorEditor (GrachuruAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    mMainPanel = std::make_unique<GrachuruMainPanel>(&audioProcessor);
    addAndMakeVisible(mMainPanel.get());
       
    mLookAndFeel = std::make_unique<GrachuruLookAndFeel>();
    setLookAndFeel(mLookAndFeel.get());
    juce::LookAndFeel::setDefaultLookAndFeel(mLookAndFeel.get());

}

GrachuruAudioProcessorEditor::~GrachuruAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

void GrachuruAudioProcessorEditor::paint (juce::Graphics& g)
{
   
}

void GrachuruAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
