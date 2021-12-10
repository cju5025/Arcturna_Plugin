#include "TacurnaGain.h"
#include "JuceHeader.h"

TacurnaGain::TacurnaGain()
{
    
}

TacurnaGain::~TacurnaGain()
{
    
}

void TacurnaGain::process(float* inAudio, float inGain, float* outAudio, int numSamplesToRender)
{
    float gainMapped = jmap(inGain, 0.f, 1.f, -24.f, 24.f);
    gainMapped = Decibels::decibelsToGain(gainMapped, -24.f);
    
    for (int i = 0; i < numSamplesToRender; i++)
    {
        mGainSmoothed -= 0.0004 * (mGainSmoothed - gainMapped);
        outAudio[i] = inAudio[i] * mGainSmoothed;
    };
}
