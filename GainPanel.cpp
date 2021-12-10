#include "GainPanel.h"
#include "Parameters.h"
#include "GuiHelpers.h"

GainPanel::GainPanel(TacurnaAudioProcessor* processor)
:   PanelBase(processor)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
}

GainPanel::~GainPanel()
{
    
}

void GainPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
    
    if (mSlider)
    {
        paintComponentLabel(g, mSlider.get());
    }
}
    
void GainPanel::setParameterID(int inParameterID)
{
    mSlider = std::make_unique<ParameterSlider>(mProcessor->parameters, ParameterID[inParameterID]);
    
    const int slider_size = 60;
        
    mSlider->setBounds((getWidth() * 0.5) - (slider_size * 0.5),
                       (getHeight() * 0.5) - (slider_size * 0.5),
                       slider_size,
                       slider_size);
    
    addAndMakeVisible(*mSlider);
}
