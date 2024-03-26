/*
  ==============================================================================

    SynthVoice.h
    Created: 5 Mar 2024 9:34:25pm
    Author:  Tom

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);
    void renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples) override;

private:
    juce::ADSR adsr;
    juce::ADSR::Parameters adsrParams;
    juce::AudioBuffer<float> synthBuffer; // secondary buffer, where audio from audioBlock is manipulated
    // synthBuffer not actually needed, clicking issue is due to disparity between 0 and the startSample

    //juce::dsp::Oscillator<float> osc { [](float x) { return std::sin (x); }, 200};    //sine
    juce::dsp::Oscillator<float> osc{ [](float x) { return x / juce::MathConstants<float>::pi; }, 200 };    //saw
    //juce::dsp::Oscillator<float> osc{ [](float x) { return x * 2 * abs(round(x / 30) - (x / 30)); }, 200 };    //triangle
    //juce::dsp::Oscillator<float> osc{ [](float x) { return x < 0.0f ? -1.0f : 1.0f; }, 200};    //square

    bool isPrepared{ false };

    juce::dsp::Gain<float> gain;
};