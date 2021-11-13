#pragma once
#include "GrachuruPanelBase.h"
#include "GrachuruGainPanel.h"
#include "GrachuruCenterPanel.h"

class GrachuruMainPanel
:   public GrachuruPanelBase
{
public:
    
    GrachuruMainPanel(GrachuruAudioProcessor* inProcessor);
    ~GrachuruMainPanel();
    
private:
    
    std::unique_ptr<GrachuruGainPanel> mInputGainPanel;
    std::unique_ptr<GrachuruGainPanel> mOutputGainPanel;
    std::unique_ptr<GrachuruCenterPanel> mCenterPanel;
};
