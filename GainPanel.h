#pragma once

#include "PanelBase.h"
#include "ParameterSlider.h"

class GainPanel
:   public PanelBase
{
public:
    
    GainPanel(TacurnaAudioProcessor* processor);
    ~GainPanel();
    
    void paint(Graphics& g) override;
    void setParameterID(int inParameterID);
    
private:
    
    std::unique_ptr<ParameterSlider> mSlider;
    
};
