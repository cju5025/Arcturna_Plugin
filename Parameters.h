#pragma once

enum Parameters
{
    parameter_InputGain = 0,
    parameter_Drive,
    parameter_Range,
    parameter_Blend,
    parameter_OutputGain,
    parameter_Type,
    parameter_TotalNumParameters,
};

static String ParameterID [parameter_TotalNumParameters] =
{
    "InputGain",
    "Drive",
    "Range",
    "Blend",
    "OutputGain",
    "Type"
};

//TODO: add default values and labels
