#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "GrachuruParameters.h"

AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
{
    std::vector<std::unique_ptr<AudioParameterFloat>> params;
    
    for (int i = 0; i < kGrachuruParameter_TotalNumParameters; i++)
    {
        params.push_back(std::make_unique<AudioParameterFloat>(GrachuruParameterID[i],
                                                               GrachuruParameterLabel[i],
                                                               NormalisableRange<float> (0.0f, 1.0f, 0.001f),
                                                               GrachuruParameterDefaultValue[i]));
    }
    return { params.begin(), params.end() };
}

GrachuruAudioProcessor::GrachuruAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
                        parameters(*this,
                                   nullptr,
                                   Identifier("Grachuru"),
                                   createParameterLayout())
#endif
{
    initializeDSP();
}

GrachuruAudioProcessor::~GrachuruAudioProcessor()
{
}

const juce::String GrachuruAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool GrachuruAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool GrachuruAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool GrachuruAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double GrachuruAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int GrachuruAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int GrachuruAudioProcessor::getCurrentProgram()
{
    return 0;
}

void GrachuruAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String GrachuruAudioProcessor::getProgramName (int index)
{
    return {};
}

void GrachuruAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

void GrachuruAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    for (int i = 0; i < getTotalNumInputChannels(); i++)
    {
        mDelay[i]->setSampleRate(sampleRate);
        mLFO[i]->setSampleRate(sampleRate);
    }
}

void GrachuruAudioProcessor::releaseResources()
{
    for (int i = 0; i < getTotalNumInputChannels(); i++)
    {
        mDelay[i]->reset();
        mLFO[i]->reset();
    }
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool GrachuruAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void GrachuruAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        
        mInputGain[channel]->process(channelData,
                                     *parameters.getRawParameterValue(GrachuruParameterID[kGrachuruParameter_InputGain]),
                                     channelData,
                                     buffer.getNumSamples());
        
        float rate = 0;
        
        if (channel == 1)
        {
            rate = *parameters.getRawParameterValue(GrachuruParameterID[kGrachuruParameter_ModulationRate]);
        }
        
        mLFO[channel]->process(rate,
                               *parameters.getRawParameterValue(GrachuruParameterID[kGrachuruParameter_ModulationDepth]),
                               buffer.getNumSamples());
        
        mDelay[channel]->process(channelData,
                                 *parameters.getRawParameterValue(GrachuruParameterID[kGrachuruParameter_DelayTime]),
                                 *parameters.getRawParameterValue(GrachuruParameterID[kGrachuruParameter_DelayFeedback]),
                                 *parameters.getRawParameterValue(GrachuruParameterID[kGrachuruParameter_DelayWetDry]),
                                 *parameters.getRawParameterValue(GrachuruParameterID[kGrachuruParameter_DelayType]),
                                 mLFO[channel]->getBuffer(),
                                 channelData,
                                 buffer.getNumSamples());
        
        mOutputGain[channel]->process(channelData,
                                      *parameters.getRawParameterValue(GrachuruParameterID[kGrachuruParameter_OutputGain]),
                                      channelData,
                                      buffer.getNumSamples());

    }
}

bool GrachuruAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* GrachuruAudioProcessor::createEditor()
{
    return new GrachuruAudioProcessorEditor (*this);
}

void GrachuruAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{

}

void GrachuruAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{

}

void GrachuruAudioProcessor::initializeDSP()
{
    for (int i = 0; i < getTotalNumInputChannels(); i++)
    {
        mDelay[i] = std::make_unique<GrachuruDelay>();
        mLFO[i] = std::make_unique<GrachuruLFO>();
        mInputGain[i] = std::make_unique<GrachuruGain>();
        mOutputGain[i] = std::make_unique<GrachuruGain>();
    }
}


juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new GrachuruAudioProcessor();
}
