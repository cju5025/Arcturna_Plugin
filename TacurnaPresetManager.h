#pragma once
#include "JuceHeader.h"

class TacurnaPresetManager
{
public:
    TacurnaPresetManager(AudioProcessor* inProcessor);
    ~TacurnaPresetManager();
    
    void getXmlForPreset(XmlElement* inElement);
    void loadXmlForPreset(XmlElement* inElement);
    
private:
    AudioProcessor* mProcessor;
    XmlElement* mCurrentPresetXml;
};
