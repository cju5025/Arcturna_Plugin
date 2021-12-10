#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "MainPanel.h"

class TacurnaAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    TacurnaAudioProcessorEditor (TacurnaAudioProcessor&);
    ~TacurnaAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    std::unique_ptr<MainPanel> mMainPanel;
    
    TacurnaAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TacurnaAudioProcessorEditor)
};
