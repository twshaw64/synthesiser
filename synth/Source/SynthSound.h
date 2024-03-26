/*
  ==============================================================================

    SynthSound.h
    Created: 5 Mar 2024 9:34:47pm
    Author:  Tom

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote(int midiNoteNumber) override { return true; }
    bool appliesToChannel(int midiChannel) override { return true; }
};