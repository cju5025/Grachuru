#pragma once
#include "GrachuruPanelBase.h"
#include "GrachuruSlider.h"

enum GrachuruFXPanelStyle
{
    kGrachuruFXPanelStyle_Delay,
    kGrachuruFXPanelStyle_Chorus,
    kGrachuruFXPanelStyle_TotalNumStyles,
};

class GrachuruFXPanel
:   public GrachuruPanelBase
{
public:
    
    GrachuruFXPanel(GrachuruAudioProcessor* inProcessor);
    ~GrachuruFXPanel();
    
    void paint(Graphics& g) override;
    void setFXPanelStyle(GrachuruFXPanelStyle inStyle);
    
private:
    GrachuruFXPanelStyle mStyle;
    
    String mLabel;
    
    OwnedArray<GrachuruParameterSlider> mFXSliders;
    
};

