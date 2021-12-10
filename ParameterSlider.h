#pragma once

#include "JuceHeader.h"
#include "TacurnaDial.h"

class ParameterSlider
:   public Slider
{
public:
    
    ParameterSlider(AudioProcessorValueTreeState& stateToControl, const String& parameterID);
    ~ParameterSlider();
    
private:
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    TacurnaDial mDialLookAndFeel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParameterSlider);
};

