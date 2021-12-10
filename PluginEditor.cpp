#include "PluginProcessor.h"
#include "PluginEditor.h"

TacurnaAudioProcessorEditor::TacurnaAudioProcessorEditor (TacurnaAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mMainPanel = std::make_unique<MainPanel>(&audioProcessor);
    addAndMakeVisible(mMainPanel.get());
}

TacurnaAudioProcessorEditor::~TacurnaAudioProcessorEditor()
{
    
}

void TacurnaAudioProcessorEditor::paint (juce::Graphics& g)
{

}

void TacurnaAudioProcessorEditor::resized()
{
    
}
