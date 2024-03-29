/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthAudioProcessorEditor::SynthAudioProcessorEditor (SynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    using SliderAttatchment = juce::AudioProcessorValueTreeState::SliderAttachment;
    using ComboAttatchment = juce::AudioProcessorValueTreeState::ComboBoxAttachment;

    gainSlideAtt = std::make_unique<SliderAttatchment>(audioProcessor.apvts, "GAIN", gainSlide);
    oscSelectAtt = std::make_unique<ComboAttatchment>(audioProcessor.apvts, "OSC", oscSelect);
    attackSlideAtt = std::make_unique<SliderAttatchment>(audioProcessor.apvts, "ATTACK", attackSlide);
    decaySlideAtt = std::make_unique<SliderAttatchment>(audioProcessor.apvts, "DECAY", decaySlide);
    sustainSlideAtt = std::make_unique<SliderAttatchment>(audioProcessor.apvts, "SUSTAIN", sustainSlide);
    releaseSlideAtt = std::make_unique<SliderAttatchment>(audioProcessor.apvts, "RELEASE", releaseSlide);
}

SynthAudioProcessorEditor::~SynthAudioProcessorEditor()
{
}

//==============================================================================
void SynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void SynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
