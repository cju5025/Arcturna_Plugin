#pragma once

#include "PanelBase.h"
#include "TopPanel.h"
#include "GainPanel.h"
#include "CenterPanel.h"

class MainPanel
:   public PanelBase
{
public:
    
    MainPanel(TacurnaAudioProcessor* processor);
    ~MainPanel();
    
private:
    
    std::unique_ptr<TopPanel> mTopPanel;
    std::unique_ptr<GainPanel> mInputGainPanel;
    std::unique_ptr<GainPanel> mOutputGainPanel;
    std::unique_ptr<CenterPanel> mCenterPanel;
    
};
