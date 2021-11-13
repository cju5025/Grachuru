#include "GrachuruCenterPanelMenuBar.h"
#include "GrachuruParameters.h"

GrachuruCenterPanelMenuBar::GrachuruCenterPanelMenuBar(GrachuruAudioProcessor* inProcessor)
:   GrachuruPanelBase(inProcessor)
{
    setSize(CENTER_PANEL_MENU_BAR_WIDTH, CENTER_PANEL_MENU_BAR_HEIGHT);
    
    const int comboBoxWidth = 100;
    const int componentWidth = CENTER_PANEL_MENU_BAR_WIDTH;
    const int componentHeight = CENTER_PANEL_MENU_BAR_HEIGHT;
    
    int typeIndex = *inProcessor->parameters.getRawParameterValue(GrachuruParameterID[kGrachuruParameter_DelayType]);
    
    mFXTypeComboBox =
    std::make_unique<GrachuruParameterComboBox>(mProcessor->parameters, GrachuruParameterID[kGrachuruParameter_DelayType]);
    mFXTypeComboBox->setBounds(componentWidth - comboBoxWidth, 0, comboBoxWidth, componentHeight);
    mFXTypeComboBox->addItem("DELAY", 1);
    mFXTypeComboBox->addItem("CHORUS", 2);
    mFXTypeComboBox->setSelectedItemIndex(typeIndex, dontSendNotification);
    addAndMakeVisible(mFXTypeComboBox.get());
}

GrachuruCenterPanelMenuBar::~GrachuruCenterPanelMenuBar()
{
    
}

void GrachuruCenterPanelMenuBar::addFXTypeComboBoxListener(ComboBox::Listener* inListener)
{
    mFXTypeComboBox->addListener(inListener);
}

void GrachuruCenterPanelMenuBar::removeFXTypeComboBoxListener(ComboBox::Listener* inListener)
{
    mFXTypeComboBox->removeListener(inListener);
}
