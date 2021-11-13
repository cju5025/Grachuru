#include "GrachuruComboBox.h"

GrachuruParameterComboBox::GrachuruParameterComboBox(AudioProcessorValueTreeState& stateToControl,
                      const String& parameterID)
:   ComboBox(parameterID)
{
    mAttachment =
    std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(stateToControl, parameterID, *this);
}

GrachuruParameterComboBox::~GrachuruParameterComboBox()
{
    
}

