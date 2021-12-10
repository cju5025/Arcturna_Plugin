#pragma once

class TacurnaGain
{
public:
    TacurnaGain();
    ~TacurnaGain();
    
    void process(float* inAudio, float inGain, float* outAudio, int numSamplesToRender);
    
private:
    
    float mGainSmoothed;
    
};
