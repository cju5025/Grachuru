#pragma once
#include "GrachuruPanelBase.h"
#include "GrachuruComboBox.h"

class GrachuruCenterPanelMenuBar
:   public GrachuruPanelBase
{
public:
    
    GrachuruCenterPanelMenuBar(GrachuruAudioProcessor* inProcessor);
    ~GrachuruCenterPanelMenuBar();
    
    void addFXTypeComboBoxListener(ComboBox::Listener* inListener);
    void removeFXTypeComboBoxListener(ComboBox::Listener* inListener);
    
private:
    
    std::unique_ptr<GrachuruParameterComboBox> mFXTypeComboBox;
    
};
