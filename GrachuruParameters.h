#pragma once

enum GrachuruParameter
{
    kGrachuruParameter_InputGain = 0,
    kGrachuruParameter_DelayTime,
    kGrachuruParameter_DelayFeedback,
    kGrachuruParameter_DelayWetDry,
    kGrachuruParameter_DelayType,
    kGrachuruParameter_OutputGain,
    kGrachuruParameter_ModulationRate,
    kGrachuruParameter_ModulationDepth,
    kGrachuruParameter_TotalNumParameters
};

static String GrachuruParameterID [ kGrachuruParameter_TotalNumParameters ] =
{
    "InputGain",
    "Time",
    "Feedback",
    "WetDry",
    "Type",
    "OutputGain",
    "ModulationRate",
    "ModulationDepth"
};

static String GrachuruParameterLabel [ kGrachuruParameter_TotalNumParameters ] =
{
    "Input Gain",
    "Time",
    "Feedback",
    "Wet/Dry",
    "Type",
    "Output Gain",
    "Modulation Rate",
    "Modulation Depth"
};

static float GrachuruParameterDefaultValue [ kGrachuruParameter_TotalNumParameters ] =
{
    0.5f,
    0.25f,
    0.5f,
    0.5f,
    0.0f,
    0.5f,
    0.25f,
    0.5f
};
