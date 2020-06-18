/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_2D9398E205760276__
#define __JUCE_HEADER_2D9398E205760276__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "IWave.h"
#include "SineWave.h"
//[/Headers]

//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class OscillatorWave  : public Component,
    public Slider::Listener,
    public Button::Listener
{
public:
    //==============================================================================
    OscillatorWave ();
    ~OscillatorWave();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setWaveType(IWave *iwave) { this->wave = iwave; }

    double getVolume() { return wave->getAmplitude(); }
    double getPhase() { return wave->getPhase(); }
    double getFrequency() { return wave->getFrequency(); }

    double nextSample(double t, int len) { return wave->nextSample(t, len); }

    void muteOn() { this->mute->setToggleState(true, dontSendNotification); wave->muteOn(); };
    void muteOff() { this->mute->setToggleState(false, dontSendNotification); wave->muteOff(); }

    void setTitle(String t) { title->setText(t, dontSendNotification); }
    void setColor(Colour color) { this->m_color = color; }

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    IWave* wave;

    Colour m_color;
    double dbToLinear(double value) { return pow(10.0, value / 20.0); }
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> volumeSlider;
    ScopedPointer<Label> label;
    ScopedPointer<Slider> phaseSlider;
    ScopedPointer<Label> label2;
    ScopedPointer<Slider> freqSlider;
    ScopedPointer<Label> label3;
    ScopedPointer<Label> title;
    ScopedPointer<ToggleButton> mute;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorWave)
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class OscillatorWaveSpec : public Component,
    public Slider::Listener,
    public Button::Listener
{
public:
    //==============================================================================
    
    OscillatorWaveSpec();
    ~OscillatorWaveSpec();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setWaveType(SmoothCalibrationWave* iwave) { this->wave = iwave; }
    double getVolume() { return wave->getAmplitude(); }
    double getPhase() { return wave->getPhase(); }

    double getFrequencyHigh() { return wave->getFrequencyHigh(); }
    double getFrequencyDown() { return wave->getFrequencyDown(); }

    double nextSample(double t, int len) { return wave->nextSample(t, len); }

    void muteOn() { this->mute->setToggleState(true, dontSendNotification); wave->muteOn(); };
    void muteOff() { this->mute->setToggleState(false, dontSendNotification); wave->muteOff(); }

    void setTitle(String t) { title->setText(t, dontSendNotification); }
    void setColor(Colour color) { this->m_color = color; }

    //[/UserMethods]

    void paint(Graphics& g) override;
    void resized() override;
    void sliderValueChanged(Slider* sliderThatWasMoved) override;
    void buttonClicked(Button* buttonThatWasClicked) override;

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    SmoothCalibrationWave* wave;

    Colour m_color;
    double dbToLinear(double value) { return pow(10.0, value / 20.0); }
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> volumeSlider;
    ScopedPointer<Label> label;

    ScopedPointer<Slider> phaseSlider;
    ScopedPointer<Label> label2;

    ScopedPointer<Slider> freqSlider;
    ScopedPointer<Label> label3;

    ScopedPointer<Slider> freqSlider_1;
    ScopedPointer<Label> label4;

    ScopedPointer<Label> title;
    ScopedPointer<ToggleButton> mute;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OscillatorWaveSpec)
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class OscillatorWaveSpec_2 : public Component,
    public Slider::Listener,
    public Button::Listener
{
public:
    //==============================================================================
    OscillatorWaveSpec_2();
    ~OscillatorWaveSpec_2();
    //===============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setWaveType(CalibrationWave* iwave) { this->wave = iwave; }
    double getVolume() { return wave->getAmplitude(); }
    double getPhase() { return wave->getPhase(); }
    double getFrequencyHigh() { return wave->getFrequencyHigh(); }
    double getFrequencyDown() { return wave->getFrequencyDown(); }
    double getFrequencyStep() { return wave->getFrequencyStep(); }
    double getFrequencyChangeTime() { return wave->getFrequencyChangeTime();}
    double getSignalOn() { return wave->getSignalOn(); }
    double getSignalOff() { return wave->getSignalOff();}

    double nextSample(double t, int len) { return wave->nextSample(t, len); }
    void muteOn() { this->mute->setToggleState(true, dontSendNotification); wave->muteOn(); };
    void muteOff() { this->mute->setToggleState(false, dontSendNotification); wave->muteOff(); }
    void setTitle(String t) { title->setText(t, dontSendNotification); }
    void setColor(Colour color) { this->m_color = color; }
    //[/UserMethods]
    void paint(Graphics& g) override;
    void resized() override;
    void sliderValueChanged(Slider* sliderThatWasMoved) override;
    void buttonClicked(Button* buttonThatWasClicked) override;

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    CalibrationWave* wave;

    Colour m_color;
    double dbToLinear(double value) { return pow(10.0, value / 20.0); }
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> volumeSlider;
    ScopedPointer<Label> label;

    ScopedPointer<Slider> phaseSlider;
    ScopedPointer<Label> label2;

    ScopedPointer<Slider> freqSlider;
    ScopedPointer<Label> label3;

    ScopedPointer<Slider> freqSlider_1;
    ScopedPointer<Label> label4;

    ScopedPointer<Slider> freqSlider_2;
    ScopedPointer<Label> label5;

    ScopedPointer<Slider> freqSlider_3;
    ScopedPointer<Label> label5_1;

    ScopedPointer<Slider> sigonSlider;
    ScopedPointer<Label> label6;

    ScopedPointer<Slider> sigoffSlider;
    ScopedPointer<Label> label7;


    ScopedPointer<Label> title;
    ScopedPointer<ToggleButton> mute;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OscillatorWaveSpec_2)
};
#endif   // __JUCE_HEADER_2D9398E205760276__
