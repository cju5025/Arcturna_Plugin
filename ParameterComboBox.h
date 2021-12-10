#pragma once
#include "JuceHeader.h"

class TacurnaParameterComboBox
:   public ComboBox
{
public:
    
    TacurnaParameterComboBox(AudioProcessorValueTreeState& stateToControl,
                          const String& parameterID);
    ~TacurnaParameterComboBox();
    
private:
    
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TacurnaParameterComboBox);

};