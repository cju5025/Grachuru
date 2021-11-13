#include "GrachuruCenterPanel.h"
#include "GrachuruParameters.h"

GrachuruCenterPanel::GrachuruCenterPanel(GrachuruAudioProcessor* inProcessor)
:   GrachuruPanelBase(inProcessor)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    
    mCenterPanelMenuBar = std::make_unique<GrachuruCenterPanelMenuBar>(inProcessor);
    mCenterPanelMenuBar->setTopLeftPosition(0, 0);
    mCenterPanelMenuBar->addFXTypeComboBoxListener(this);
    addAndMakeVisible(mCenterPanelMenuBar.get());
    
    mDelayPanel = std::make_unique<GrachuruFXPanel>(inProcessor);
    mDelayPanel->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    mDelayPanel->setFXPanelStyle(kGrachuruFXPanelStyle_Delay);
    addChildComponent(mDelayPanel.get());
    
    mChorusPanel = std::make_unique<GrachuruFXPanel>(inProcessor);
    mChorusPanel->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    mChorusPanel->setFXPanelStyle(kGrachuruFXPanelStyle_Chorus);
    addChildComponent(mChorusPanel.get());
    
    AudioProcessorValueTreeState& tree = mProcessor->parameters;
    
    const float panelToShow =
    *tree.getRawParameterValue(GrachuruParameterID[kGrachuruParameter_DelayType]);
    showPanel((int)panelToShow);
    
}

GrachuruCenterPanel::~GrachuruCenterPanel()
{
    mCenterPanelMenuBar->removeFXTypeComboBoxListener(this);
}

void GrachuruCenterPanel::showPanel(int inPanelID)
{
    switch(inPanelID)
    {
        case(kGrachuruFXPanelStyle_Delay):
        {
            mDelayPanel->setVisible(true);
            mChorusPanel->setVisible(false);
        } break;
            
        case(kGrachuruFXPanelStyle_Chorus):
        {
            mDelayPanel->setVisible(false);
            mChorusPanel->setVisible(true);
        } break;
    }
}

void GrachuruCenterPanel::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{
    showPanel(comboBoxThatHasChanged->getSelectedItemIndex());
}
