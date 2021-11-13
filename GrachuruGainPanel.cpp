#include "GrachuruGainPanel.h"
#include "GrachuruParameters.h"
#include "GrachuruGUIHelpers.h"

GrachuruGainPanel::GrachuruGainPanel(GrachuruAudioProcessor* inProcessor)
:   GrachuruPanelBase(inProcessor)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
}

GrachuruGainPanel::~GrachuruGainPanel()
{
    
}

void GrachuruGainPanel::paint(Graphics& g)
{
    GrachuruPanelBase::paint(g);
    
    if (mGainSlider)
    {
        paintComponentLabel(g, mGainSlider.get());
    }
}

void GrachuruGainPanel::setParameterID(int inParameterID)
{
    mGainSlider = std::make_unique<GrachuruParameterSlider>(mProcessor->parameters,
                                                    GrachuruParameterID[inParameterID]);

    const int sliderSize = 75;
    mGainSlider->setBounds((getWidth() * 0.5) - (sliderSize * 0.5),
                       (getHeight() * 0.5) - (sliderSize * 0.5),
                       sliderSize,
                       sliderSize);

    addAndMakeVisible(mGainSlider.get());
}
