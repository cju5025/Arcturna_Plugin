#include "MainPanel.h"
#include "Parameters.h"

MainPanel::MainPanel(TacurnaAudioProcessor* processor)
:   PanelBase(processor)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mTopPanel = std::make_unique<TopPanel>(processor);
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(mTopPanel.get());
    
    mInputGainPanel = std::make_unique<GainPanel>(processor);
    mInputGainPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    mInputGainPanel->setParameterID(parameter_InputGain);
    addAndMakeVisible(mInputGainPanel.get());
    
    mOutputGainPanel = std::make_unique<GainPanel>(processor);
    mOutputGainPanel->setTopLeftPosition(MAIN_PANEL_WIDTH - GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    mOutputGainPanel->setParameterID(parameter_OutputGain);
    addAndMakeVisible(mOutputGainPanel.get());
    
    mCenterPanel = std::make_unique<CenterPanel>(processor);
    mCenterPanel->setTopLeftPosition(GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mCenterPanel.get());
}

MainPanel::~MainPanel()
{
    
}
