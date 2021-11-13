#include "GrachuruTopPanel.h"

GrachuruTopPanel::GrachuruTopPanel(GrachuruAudioProcessor* inProcessor)
:   GrachuruPanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    
    int button_x = 15;
    int button_y = 10;
    int button_w = 55;
    int button_h = 25;

GrachuruTopPanel::~GrachuruTopPanel()
{
    
}

void GrachuruTopPanel::paint(Graphics& g)
{
    GrachuruPanelBase::paint(g);
    
    g.drawFittedText("Family Time Delay / Chorus", 0, 0, getWidth() - 10, getHeight(), Justification::centredRight, 1);
}

void GrachuruTopPanel::displaySaveAsPopup()
{
    
    GrachuruPresetManager* presetManager = mProcessor->getPresetManager();

    String currentPresetName = presetManager->getCurrentPresetName();
    
    if (presetManager->isCurrentPresetSaved())
    {
        currentPresetName = currentPresetName + "_1";
    }
#if JUCE_MODAL_LOOPS_PERMITTED
    AlertWindow window ("Save As", "Enter Preset Name", AlertWindow::NoIcon);
    window.centreAroundComponent(this, getWidth(), getHeight());
    window.addTextEditor("presetName", currentPresetName, "preset name: ");
    window.addButton("Confirm", 1);
    window.addButton("Cancel", 0);

    if (window.runModalLoop() != 0)
    {
        DBG("deeper hit");
        String presetName = window.getTextEditor("presetName")->getText();
        presetManager->saveAsPreset(presetName);

        updatePresetComboBox();
    }
#endif
    
}

void GrachuruTopPanel::updatePresetComboBox()
{
    GrachuruPresetManager* presetManager = mProcessor->getPresetManager();
    String presetName = presetManager->getCurrentPresetName();
    
    mPresetDisplay->clear(dontSendNotification);
    
    const int numberOfPresets = presetManager->getNumberOfPresets();
    
    for (int i = 0; i < numberOfPresets; i++)
    {
        mPresetDisplay->addItem(presetManager->getPresetName(i), (i + 1));
    }
    mPresetDisplay->setText(presetManager->getCurrentPresetName());
}
