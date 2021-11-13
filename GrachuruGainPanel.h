#pragma once
#include "GrachuruPanelBase.h"
#include "GrachuruSlider.h"

class GrachuruGainPanel
:   public GrachuruPanelBase
{
public:
    
    GrachuruGainPanel(GrachuruAudioProcessor* inProcessor);
    ~GrachuruGainPanel();
    
    void paint(Graphics& g) override;
    void setParameterID(int inParameterID);

private:
    
    std::unique_ptr<GrachuruParameterSlider> mGainSlider;
    
};
