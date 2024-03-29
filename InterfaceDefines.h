#pragma once

#define MAIN_PANEL_WIDTH             750
#define MAIN_PANEL_HEIGHT            300

#define TOP_PANEL_WIDTH              MAIN_PANEL_WIDTH
#define TOP_PANEL_HEIGHT             45

#define GAIN_PANEL_WIDTH             100
#define GAIN_PANEL_HEIGHT            MAIN_PANEL_HEIGHT - TOP_PANEL_HEIGHT

#define CENTER_PANEL_WIDTH           MAIN_PANEL_WIDTH - (GAIN_PANEL_WIDTH * 2)
#define CENTER_PANEL_HEIGHT          GAIN_PANEL_HEIGHT

#define FX_PANEL_WIDTH               CENTER_PANEL_WIDTH
#define FX_PANEL_HEIGHT              CENTER_PANEL_HEIGHT

const Font font_1 ( "Helvetica Neue", 21.00f, Font::bold);
const Font font_2 ( "Helvetica Neue", 12.00f, Font::plain);
const Font font_3 ( "Helvetica Neue", 9.00f, Font::plain);
