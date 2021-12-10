#pragma once

#include "PanelBase.h"
#include "ParameterComboBox.h"

class TopPanel
:   public PanelBase
{
public:
    
    TopPanel(TacurnaAudioProcessor* inProcessor);
    ~TopPanel();
    
    void paint(Graphics& g) override;
    
    void addFXTypeComboBoxListener(ComboBox::Listener* inListener);
    void removeFXTypeComboBoxListener(ComboBox::Listener* inListener);
    
private:
    
    std::unique_ptr<TacurnaParameterComboBox> mTypeComboBox;
    
};
