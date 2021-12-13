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

void TacurnaParameterComboBox::paint(Graphics& g)
{
    g.setColour(Colours::black);
    g.drawRoundedRectangle(0, 0, getWidth(), getHeight(), 5, 5);
    
    g.setColour(Colour(67, 76, 80));
    
}
