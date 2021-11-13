#pragma once
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "GrachuruInterfaceDefines.h"

class GrachuruPanelBase
:   public Component
{
public:
    
    GrachuruPanelBase(GrachuruAudioProcessor* inProcessor);
    ~GrachuruPanelBase();
    
    void paint (Graphics& g) override;
    
protected:
    
    GrachuruAudioProcessor* mProcessor;
    
};
