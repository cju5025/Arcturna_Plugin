#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "InterfaceDefines.h"

class PanelBase
:   public Component
{
public:
    
    PanelBase(TacurnaAudioProcessor* processor);
    ~PanelBase();
    
    void paint(Graphics& g) override;
    
protected:
    TacurnaAudioProcessor* mProcessor;
};
