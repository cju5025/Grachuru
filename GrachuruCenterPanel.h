#pragma once
#include "JuceHeader.h"
#include "GrachuruPanelBase.h"
#include "GrachuruCenterPanelMenuBar.h"
#include "GrachuruFXPanel.h"

class GrachuruCenterPanel
:   public GrachuruPanelBase,
    public ComboBox::Listener
{
public:
    
    GrachuruCenterPanel(GrachuruAudioProcessor* inProcessor);
    ~GrachuruCenterPanel();
    
private:
    
    void showPanel(int inPanelID);
    void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;
    
    std::unique_ptr<GrachuruCenterPanelMenuBar> mCenterPanelMenuBar;
    std::unique_ptr<GrachuruFXPanel> mDelayPanel;
    std::unique_ptr<GrachuruFXPanel> mChorusPanel;
};
