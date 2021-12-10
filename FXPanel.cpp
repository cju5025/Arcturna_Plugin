#include "FXPanel.h"
#include "Parameters.h"
#include "GuiHelpers.h"

FXPanel::FXPanel(TacurnaAudioProcessor* processor)
:   PanelBase(processor)
{
    setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
}

FXPanel::~FXPanel()
{
    
}

void FXPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
    if (mDriveSlider)
    {
        paintComponentLabel(g, mDriveSlider.get());
    }
    if (mRangeSlider)
    {
        paintComponentLabel(g, mRangeSlider.get());
    }
    if (mBlendSlider)
    {
        paintComponentLabel(g, mBlendSlider.get());
    }
    if (mVolumeSlider)
    {
        paintComponentLabel(g, mVolumeSlider.get());
    }
}

void FXPanel::addSliders()
{
        const int slider_size = 60;
        int x = 125;
        int y = (getHeight() * 0.5) - (slider_size * 0.5);
    
        mDriveSlider = std::make_unique<ParameterSlider>(mProcessor->parameters, ParameterID[parameter_Drive]);
        mDriveSlider->setBounds(x, y, slider_size, slider_size);
        addAndMakeVisible(*mDriveSlider);
        x += slider_size * 2;
    
        mRangeSlider = std::make_unique<ParameterSlider>(mProcessor->parameters, ParameterID[parameter_Range]);
        mRangeSlider->setBounds(x, y, slider_size, slider_size);
        addAndMakeVisible(*mRangeSlider);
        x += slider_size * 2;
    
        mBlendSlider = std::make_unique<ParameterSlider>(mProcessor->parameters, ParameterID[parameter_Blend]);
        mBlendSlider->setBounds(x, y, slider_size, slider_size);
        addAndMakeVisible(*mBlendSlider);
        x += slider_size * 2;
    
}

