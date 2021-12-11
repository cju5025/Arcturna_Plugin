#pragma once

enum Parameters
{
    parameter_InputGain = 0,
    parameter_Drive = 1,
    parameter_Range = 2,
    parameter_Blend = 3,
    parameter_OutputGain = 4,
    parameter_Type = 5,
    parameter_TotalNumParameters = 6,
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
