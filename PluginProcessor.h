#pragma once

#include "JuceHeader.h"
#include "TacurnaGain.h"
#include "TacurnaDistortion.h"
#include "TacurnaPresetManager.h"

class TacurnaAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    TacurnaAudioProcessor();
    ~TacurnaAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    TacurnaPresetManager* getPresetManager();
    
    AudioProcessorValueTreeState parameters;

private:
    
    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    
    void initializeDSP();
    
    std::unique_ptr<TacurnaPresetManager> mPresetManager;
    
    std::unique_ptr<TacurnaGain> mInputGain [2];
    std::unique_ptr<TacurnaGain> mOutputGain [2];
    std::unique_ptr<TacurnaDistortion> mDistortion [2];
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TacurnaAudioProcessor)
};
