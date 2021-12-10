#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Parameters.h"

//==============================================================================
TacurnaAudioProcessor::TacurnaAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
                    parameters(*this, nullptr, Identifier("Arcturna"), createParameterLayout())
#endif
{
    initializeDSP();
    mPresetManager = std::make_unique<TacurnaPresetManager>(this);
}

TacurnaAudioProcessor::~TacurnaAudioProcessor()
{
}

//==============================================================================
const juce::String TacurnaAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TacurnaAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TacurnaAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TacurnaAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double TacurnaAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TacurnaAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TacurnaAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TacurnaAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String TacurnaAudioProcessor::getProgramName (int index)
{
    return {};
}

void TacurnaAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void TacurnaAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{

}

void TacurnaAudioProcessor::releaseResources()
{
    
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TacurnaAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void TacurnaAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        float inputGain = *parameters.getRawParameterValue(ParameterID[parameter_InputGain]);
        mInputGain[channel]->process(channelData,
                                     inputGain,
                                     channelData,
                                     buffer.getNumSamples());
        
        float drive = *parameters.getRawParameterValue(ParameterID[parameter_Drive]);
        float range = *parameters.getRawParameterValue(ParameterID[parameter_Range]);
        float blend = *parameters.getRawParameterValue(ParameterID[parameter_Blend]);
        int type = (int)*parameters.getRawParameterValue(ParameterID[parameter_Type]);
        mDistortion[channel]->process(channelData,
                                      type,
                                      drive,
                                      range,
                                      blend,
                                      buffer.getNumSamples());

        channelData = buffer.getWritePointer (channel);
        
        float outputGain = *parameters.getRawParameterValue(ParameterID[parameter_OutputGain]);
        mOutputGain[channel]->process(channelData,
                                      outputGain,
                                      channelData,
                                      buffer.getNumSamples());
    }
}

//==============================================================================
bool TacurnaAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* TacurnaAudioProcessor::createEditor()
{
    return new TacurnaAudioProcessorEditor (*this);
}

//==============================================================================
void TacurnaAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    XmlElement preset("State_Info");
    XmlElement* presetBody = new XmlElement("Preset");
    
    mPresetManager->getXmlForPreset(presetBody);
    
    preset.addChildElement(presetBody);
    copyXmlToBinary(preset, destData);
}

void TacurnaAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    const auto xmlState = getXmlFromBinary(data, sizeInBytes);
    
    jassert (xmlState.get() != nullptr);
    
    for (auto* subChild : xmlState->getChildIterator())
    {
        mPresetManager->loadXmlForPreset(subChild);
    }
    
}

TacurnaPresetManager* TacurnaAudioProcessor::getPresetManager()
{
    return mPresetManager.get();
}

void TacurnaAudioProcessor::initializeDSP()
{
    for (int i = 0; i < 2; i++)
    {
        mInputGain[i] = std::make_unique<TacurnaGain>();
        mOutputGain[i] = std::make_unique<TacurnaGain>();
        mDistortion[i] = std::make_unique<TacurnaDistortion>();
    }
}

AudioProcessorValueTreeState::ParameterLayout TacurnaAudioProcessor::createParameterLayout()
{
    std::vector<std::unique_ptr<AudioParameterFloat>> params;
    
    for (int i = 0; i < parameter_TotalNumParameters - 1; i++)
    {
        params.push_back(std::make_unique<AudioParameterFloat>(ParameterID[i],
                                                               ParameterID[i],
                                                               NormalisableRange<float>(0.001f, 1.0f),
                                                               0.5f));
        
    }
    
    params.push_back(std::make_unique<AudioParameterFloat>(ParameterID[parameter_Type],
                                                           ParameterID[parameter_Type],
                                                           NormalisableRange<float>(0, 3),
                                                           0));
    return { params.begin(), params.end() };
}

//==============================================================================
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TacurnaAudioProcessor();
}
