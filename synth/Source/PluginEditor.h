/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SynthAudioProcessorEditor (SynthAudioProcessor&);
    ~SynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //prepend with osc1 or osc2
    //could be unique pointers? - todo with freeing memory
    juce::Slider gainSlide;
    juce::ComboBox oscSelect;
    juce::Slider attackSlide;
    juce::Slider decaySlide;
    juce::Slider sustainSlide;
    juce::Slider releaseSlide;

    SynthAudioProcessor& audioProcessor;

    using SliderAttatchment = juce::AudioProcessorValueTreeState::SliderAttachment;
    using ComboAttatchment = juce::AudioProcessorValueTreeState::ComboBoxAttachment;

    std::unique_ptr<SliderAttatchment> gainSlideAtt;
    std::unique_ptr<ComboAttatchment> oscSelectAtt;
    std::unique_ptr<SliderAttatchment> attackSlideAtt;
    std::unique_ptr<SliderAttatchment> decaySlideAtt;
    std::unique_ptr<SliderAttatchment> sustainSlideAtt;
    std::unique_ptr<SliderAttatchment> releaseSlideAtt;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthAudioProcessorEditor)
};
