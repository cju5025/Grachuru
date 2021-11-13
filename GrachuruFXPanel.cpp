#include "GrachuruFXPanel.h"
#include "GrachuruParameters.h"
#include "GrachuruGuiHelpers.h"

GrachuruFXPanel::GrachuruFXPanel(GrachuruAudioProcessor* inProcessor)
:   GrachuruPanelBase(inProcessor)
{
    setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
    
}

GrachuruFXPanel::~GrachuruFXPanel()
{
    mFXSliders.clear();
}

void GrachuruFXPanel::paint(Graphics& g)
{
    GrachuruPanelBase::paint(g);
    
    g.setColour(Colours::ghostwhite);
    g.drawText(mLabel, 0, 0, getWidth(), 80, Justification::centred, false);
    
    for (int i = 0; i < mFXSliders.size(); i++)
    {
        paintComponentLabel(g, mFXSliders[i]);
    }
}

void GrachuruFXPanel::setFXPanelStyle(GrachuruFXPanelStyle inStyle)
{
    mStyle = inStyle;
    
    mFXSliders.clear();
    
    const int sliderSize = 75;
    int x = 130;
    int y = (getHeight() * 0.5) - (sliderSize * 0.5);
    
    switch (mStyle)
    {
        case (kGrachuruFXPanelStyle_Delay):
        {
            GrachuruParameterSlider* time =
            new GrachuruParameterSlider(mProcessor->parameters, GrachuruParameterID[kGrachuruParameter_DelayTime]);
            time->setBounds(x, y, sliderSize, sliderSize);
            addAndMakeVisible(time);
            mFXSliders.add(time);
            x += sliderSize * 2;
            
            GrachuruParameterSlider* feedback =
            new GrachuruParameterSlider(mProcessor->parameters, GrachuruParameterID[kGrachuruParameter_DelayFeedback]);
            feedback->setBounds(x, y, sliderSize, sliderSize);
            addAndMakeVisible(feedback);
            mFXSliders.add(feedback);
            x += sliderSize * 2;
            
            GrachuruParameterSlider* wetdry =
            new GrachuruParameterSlider(mProcessor->parameters, GrachuruParameterID[kGrachuruParameter_DelayWetDry]);
            wetdry->setBounds(x, y, sliderSize, sliderSize);
            addAndMakeVisible(wetdry);
            mFXSliders.add(wetdry);
            
            mLabel = "DELAY";
            
        } break;
            
        case (kGrachuruFXPanelStyle_Chorus):
        {
            GrachuruParameterSlider* rate =
            new GrachuruParameterSlider(mProcessor->parameters, GrachuruParameterID[kGrachuruParameter_ModulationRate]);
            rate->setBounds(x, y, sliderSize, sliderSize);
            addAndMakeVisible(rate);
            mFXSliders.add(rate);
            x += sliderSize * 2;
            
            GrachuruParameterSlider* depth =
            new GrachuruParameterSlider(mProcessor->parameters, GrachuruParameterID[kGrachuruParameter_ModulationDepth]);
            depth->setBounds(x, y, sliderSize, sliderSize);
            addAndMakeVisible(depth);
            mFXSliders.add(depth);
            x += sliderSize * 2;
            
            GrachuruParameterSlider* wetdry =
            new GrachuruParameterSlider(mProcessor->parameters, GrachuruParameterID[kGrachuruParameter_DelayWetDry]);
            wetdry->setBounds(x, y, sliderSize, sliderSize);
            addAndMakeVisible(wetdry);
            mFXSliders.add(wetdry);
            
            mLabel = "CHORUS";
            
        } break;
            
        case (kGrachuruFXPanelStyle_TotalNumStyles):
        {
            
            jassertfalse;
            
        } break;
    }
}
