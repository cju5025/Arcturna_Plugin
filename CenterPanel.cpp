#include "CenterPanel.h"

CenterPanel::CenterPanel(TacurnaAudioProcessor* processor)
:   PanelBase(processor)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    mFXPanel = std::make_unique<FXPanel>(processor);
    mFXPanel->setTopLeftPosition(0, 0);
    mFXPanel->addSliders();
    addAndMakeVisible(mFXPanel.get());
}

CenterPanel::~CenterPanel()
{
    
}
