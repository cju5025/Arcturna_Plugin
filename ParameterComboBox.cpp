#include "ParameterComboBox.h"

TacurnaParameterComboBox::TacurnaParameterComboBox(AudioProcessorValueTreeState& stateToControl,
                      const String& parameterID)
:   ComboBox(parameterID)
{
    mAttachment =
    std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(stateToControl, parameterID, *this);
}

TacurnaParameterComboBox::~TacurnaParameterComboBox()
{
    
}