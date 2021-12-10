#include "PanelBase.h"

PanelBase::PanelBase(TacurnaAudioProcessor* processor)
:   mProcessor(processor)
{
    
}

PanelBase::~PanelBase()
{
    
}

void PanelBase::paint(Graphics& g)
{
    g.setColour(Colour(67, 76, 80));
    g.fillAll();
    
    g.setColour(Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight());
}
