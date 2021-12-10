#pragma once

#include "PanelBase.h"
#include "ParameterSlider.h"

class FXPanel
:   public PanelBase
{
public:
    
    FXPanel(TacurnaAudioProcessor* inProcessor);
    ~FXPanel();
    
    void paint(Graphics& g) override;
    void addSliders();
    
private:
    
    std::unique_ptr<ParameterSlider> mDriveSlider;
    std::unique_ptr<ParameterSlider> mRangeSlider;
    std::unique_ptr<ParameterSlider> mBlendSlider;
    std::unique_ptr<ParameterSlider> mVolumeSlider;
    
};
