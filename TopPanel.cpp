#include "TopPanel.h"
#include "Parameters.h"

TopPanel::TopPanel(TacurnaAudioProcessor* processor)
:   PanelBase(processor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    
     const int comboBoxWidth = 100;
     const int componentWidth = TOP_PANEL_WIDTH;
     const int componentHeight = TOP_PANEL_HEIGHT;
     
     int typeIndex = *processor->parameters.getRawParameterValue(ParameterID[parameter_Type]);
     
     mTypeComboBox =
     std::make_unique<TacurnaParameterComboBox>(mProcessor->parameters, ParameterID[parameter_Type]);
     mTypeComboBox->setBounds(componentWidth - comboBoxWidth, 0, comboBoxWidth, componentHeight);
     mTypeComboBox->addItem("Mild", 1);
     mTypeComboBox->addItem("Medium", 2);
     mTypeComboBox->addItem("Hot", 3);
     mTypeComboBox->addItem("Xtreme", 4);
     mTypeComboBox->setSelectedItemIndex(typeIndex, dontSendNotification);
     addAndMakeVisible(mTypeComboBox.get());
}

TopPanel::~TopPanel()
{
    
}

void TopPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
    
    g.drawFittedText("Arcturna", 0, 0, getWidth() - 10, getHeight(), Justification::centred, 1);
}

void TopPanel::addFXTypeComboBoxListener(ComboBox::Listener* inListener)
{
    mTypeComboBox->addListener(inListener);
}

void TopPanel::removeFXTypeComboBoxListener(ComboBox::Listener* inListener)
{
    mTypeComboBox->removeListener(inListener);
}
