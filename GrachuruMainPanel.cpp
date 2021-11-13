#include "GrachuruMainPanel.h"
#include "GrachuruParameters.h"

GrachuruMainPanel::GrachuruMainPanel(GrachuruAudioProcessor* inProcessor)
:   GrachuruPanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mInputGainPanel = std::make_unique<GrachuruGainPanel>(inProcessor);
    mInputGainPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    mInputGainPanel->setParameterID(kGrachuruParameter_InputGain);
    addAndMakeVisible(mInputGainPanel.get());
    
    mCenterPanel = std::make_unique<GrachuruCenterPanel>(inProcessor);
    mCenterPanel->setTopLeftPosition(GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mCenterPanel.get());
    
    mOutputGainPanel = std::make_unique<GrachuruGainPanel>(inProcessor);
    mOutputGainPanel->setTopLeftPosition(MAIN_PANEL_WIDTH - GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    mOutputGainPanel->setParameterID(kGrachuruParameter_OutputGain);
    addAndMakeVisible(mOutputGainPanel.get());
}

GrachuruMainPanel::~GrachuruMainPanel()
{
    
}
