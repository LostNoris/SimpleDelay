/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleDelayAudioProcessorEditor::SimpleDelayAudioProcessorEditor (SimpleDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

SimpleDelayAudioProcessorEditor::~SimpleDelayAudioProcessorEditor()
{
}

//==============================================================================
void SimpleDelayAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.fillAll(juce::Colours::black);

    g.setColour(juce::Colours::darkseagreen);
    juce::Rectangle<float> backgroundRect = getLocalBounds().toFloat();
    int numBackgroundRects = 60;
    juce::Point<float> offset = backgroundRect.getBottomRight() / numBackgroundRects;

    for (int i = 0; i < numBackgroundRects; ++i)
    {
        g.drawRect(backgroundRect);
        backgroundRect += offset;
    }

    g.setColour(juce::Colours::cornflowerblue);
    g.fillRect(20, 20, 100, 100);

    g.setColour(juce::Colours::darkred);
    g.fillRect(120, 20, 100, 100);

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawText(" This Square Is Blue ", juce::Rectangle(20, 20, 300, 100), juce::Justification::verticallyCentred, 1); 
    //g.drawFittedText ("Hallo Wurld", getLocalBounds(), juce::Justification::centred, 1);
}

void SimpleDelayAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
