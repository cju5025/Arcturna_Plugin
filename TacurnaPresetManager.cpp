#include "TacurnaPresetManager.h"

TacurnaPresetManager::TacurnaPresetManager(AudioProcessor* inProcessor)
:   mProcessor(inProcessor)
{
    
}
TacurnaPresetManager::~TacurnaPresetManager()
{
    
}

void TacurnaPresetManager::getXmlForPreset(XmlElement* inElement)
{
    auto& parameters = mProcessor->getParameters();
    
    for (int i = 0; i < parameters.size(); i++)
    {
        AudioProcessorParameterWithID* parameter =
        (AudioProcessorParameterWithID*)parameters.getUnchecked(i);
        
        inElement->setAttribute(parameter->paramID, parameter->getValue());
    }
}

void TacurnaPresetManager::loadXmlForPreset(XmlElement* inElement)
{
    mCurrentPresetXml = inElement;
    
    auto& parameters = mProcessor->getParameters();
    
    for (int i = 0; i < mCurrentPresetXml->getNumAttributes(); i++)
    {
        const String paramID = mCurrentPresetXml->getAttributeName(i);
        const float value = mCurrentPresetXml->getDoubleAttribute(paramID);
        
        for (int j = 0; i < parameters.size(); j++)
        {
            AudioProcessorParameterWithID* parameter =
            (AudioProcessorParameterWithID*)parameters.getUnchecked(i);
            
            if (paramID == parameter->paramID){
                parameter->setValueNotifyingHost(value);
            }
        }
    }

}
