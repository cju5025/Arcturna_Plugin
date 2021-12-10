#pragma once
#include "JuceHeader.h"

class TacurnaDial : public LookAndFeel_V4
{
    
public:
    
    void drawRotarySlider (Graphics &g,
                           int x,
                           int y,
                           int width,
                           int height,
                           float sliderPos,
                           float rotaryStartAngle,
                           float rotaryEndAngle,
                           Slider &slider)
    {
        float diameter = jmin(width, height);
        float radius = diameter / 2;
        float centreX = x + width / 2;
        float centreY = y + height / 2;
        float rx = centreX - radius;
        float ry = centreY - radius;
        float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));
        
        Rectangle<float> dialArea (rx, ry, diameter, diameter);
        
        g.setColour(Colours::black);
        g.fillEllipse(dialArea);
        
        g.setColour(Colour(219, 158, 54));
        
        Path dialTick;
        dialTick.addRectangle(-2.0f, -radius, 5.0f, radius * 0.75f);
        
        g.fillPath(dialTick, AffineTransform::rotation(angle).translated(centreX, centreY));
    }
    
};
