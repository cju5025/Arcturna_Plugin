#pragma once
#include "JuceHeader.h"
#include "InterfaceDefines.h"

class TacurnaParameterComboBox
:   public ComboBox
{
public:
    
    TacurnaParameterComboBox(AudioProcessorValueTreeState& stateToControl,
                          const String& parameterID);
    ~TacurnaParameterComboBox();
    
    void paint(Graphics& g) override;
    
private:
    
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TacurnaParameterComboBox);

};
