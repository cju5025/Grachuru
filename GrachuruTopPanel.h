#pragma once
#include "GrachuruPanelBase.h"


class GrachuruTopPanel
:   public GrachuruPanelBase
{
public:
    
    GrachuruTopPanel(GrachuruAudioProcessor* inProcessor);
    ~GrachuruTopPanel();
    
    void paint(Graphics& g) override;
    
private:
    
    void displaySaveAsPopup();
    void updatePresetComboBox();
    
    std::unique_ptr<ComboBox> mPresetDisplay;
    
    std::unique_ptr<TextButton> mNewPresetButton;
    std::unique_ptr<TextButton> mSavePresetButton;
    std::unique_ptr<TextButton> mSaveAsPresetButton;
    
};
