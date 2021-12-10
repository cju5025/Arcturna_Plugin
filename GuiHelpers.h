#pragma once

#include "JuceHeader.h"

inline void paintComponentLabel(Graphics& g, Component* component)
{
    const int x = component->getX() - component->getWidth() * 0.25f;
    const int y = component->getY() + component->getHeight();
    const int w = component->getWidth() * 1.5f;
    const int h = 20;
    const String label = component->getName();
    
    g.setColour(Colour(219, 158, 54));
    g.drawFittedText(label, x, y, w, h, Justification::centred, 1);
}
