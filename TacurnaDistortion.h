#pragma once

class TacurnaDistortion
{
public:
    TacurnaDistortion();
    ~TacurnaDistortion();

    void process(float* inAudio,
                 int inType,
                 float inDrive,
                 float inRange,
                 float inBlend,
                 int numSamplesToRender);

private:
    
};
