#include "TacurnaDistortion.h"
#include "JuceHeader.h"

TacurnaDistortion::TacurnaDistortion()
{
    
}

TacurnaDistortion::~TacurnaDistortion()
{
    
}

void TacurnaDistortion::process(float* inAudio,
                                int inType,
                                float inDrive,
                                float inRange,
                                float inBlend,
                                int numSamplesToRender)
{
    float rangeAmount;
    
    switch(inType) {
      case 0:
            rangeAmount = 11.1f;
        break;
      case 1:
            rangeAmount = 111.1f;
        break;
      case 2:
            rangeAmount = 1111.1f;
            break;
      case 3:
            rangeAmount = 6666.6f;
            break;
      default:
            rangeAmount = 11.1f;
    }
    float rangeMapped = jmap(inRange, 0.f, 1.f, 0.f, rangeAmount);

    for (int sample = 0; sample < numSamplesToRender; sample++)
        {
            float cleanSignal = *inAudio;

            *inAudio *= inDrive * rangeMapped;

            *inAudio = ((((2.0f / float_Pi * atan(*inAudio) * inBlend)) +
                             (cleanSignal * (1.0f - inBlend))) / 2);

            inAudio++;
        }

}

