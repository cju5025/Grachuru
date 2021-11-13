#include "GrachuruPanelBase.h"

GrachuruPanelBase::GrachuruPanelBase(GrachuruAudioProcessor* inProcessor)
:   mProcessor(inProcessor)
{
    
}

GrachuruPanelBase::~GrachuruPanelBase()
{
    
}

void GrachuruPanelBase::paint (Graphics& g)
{
    g.setColour(Colours::black);
    g.fillAll();
    g.drawRect(0, 0, getWidth(), getHeight());
}
