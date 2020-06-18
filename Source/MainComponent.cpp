#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "MainComponent.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include <limits>
#include "WhiteNoise.h"
#include "SineWave.h"
#include "SquareWave.h"
#include "SawtoothWave.h"
#include "TriangleWave.h"
#include "OscillatorWave.h"
#include "WaveformViewComponent.h"

//#include "SpectralViewComponent.h"
//==============================================================================
/*
This component lives inside our window, and this is where you should put all
your controls and content.
*/
class MainContentComponent : public AudioAppComponent {
public:
    //==============================================================================
    MainContentComponent()
    {
        setSize(1368,800 );
        setAudioChannels(0, 2);
        
        sineWaveOsc.setWaveType(new SineWave());
        squareWaveOsc.setWaveType(new SquareWave());
        sawWaveOsc.setWaveType(new SawtoothWave());
        triangleWaveOsc.setWaveType(new TriangleWave());
        smoothCalibrationOsc.setWaveType(new SmoothCalibrationWave());
        CalibrationOsc.setWaveType(new CalibrationWave());

        sineWaveOsc.setTitle("Sine wave");
        squareWaveOsc.setTitle("Square wave");
        sawWaveOsc.setTitle("Saw wave");
        triangleWaveOsc.setTitle("Triangle wave");
        smoothCalibrationOsc.setTitle("Calibration(Smooth)");
        CalibrationOsc.setTitle("Calibration");

        sineWaveOsc.muteOn();
        squareWaveOsc.muteOn();
        sawWaveOsc.muteOn();
        triangleWaveOsc.muteOn();
        smoothCalibrationOsc.muteOn();
        CalibrationOsc.muteOn();

        //sineWaveOsc.setColor(Colour::fromRGB(0x4E, 0x99, 0xFE) );
        sineWaveOsc.setColor(Colour::fromRGB(0, 0, 0));
        squareWaveOsc.setColor(Colour::fromRGB(0, 0, 0));
        sawWaveOsc.setColor(Colour::fromRGB(0, 0, 0));
        triangleWaveOsc.setColor(Colour::fromRGB(0, 0, 0));
        smoothCalibrationOsc.setColor(Colour::fromRGB(0, 0, 0));
        CalibrationOsc.setColor(Colour::fromRGB(0, 0, 0));

        addAndMakeVisible(waveformView);
        //addAndMakeVisible(spectralView);
        addAndMakeVisible(sineWaveOsc);
        addAndMakeVisible(squareWaveOsc);
        addAndMakeVisible(sawWaveOsc);
        addAndMakeVisible(triangleWaveOsc);
        addAndMakeVisible(smoothCalibrationOsc);
        addAndMakeVisible(CalibrationOsc);
        m_isInitialized = true;
    }
    ~MainContentComponent() {
        shutdownAudio();
    }
    //==============================================================================
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override {
        m_time = 0.0;
        m_deltaTime = 1.0 / sampleRate;
        monoBuffer = new float[samplesPerBlockExpected] {0};
    }
    void mixWaves(float* pmonoBuffer, int numSamples) {
        Random random;
        // generate sin wave in mono
        for (int sample = 0; sample < numSamples; ++sample) {

            double sine = sineWaveOsc.nextSample(m_time, numSamples);
            double square = squareWaveOsc.nextSample(m_time, numSamples);
            double saw = sawWaveOsc.nextSample(m_time, numSamples);
            double triangle = triangleWaveOsc.nextSample(m_time, numSamples);
            double calibr = smoothCalibrationOsc.nextSample(m_time, numSamples);
            double calibr_1 = CalibrationOsc.nextSample(m_time, numSamples);
            pmonoBuffer[sample] = sine + square + saw + triangle + calibr_1 + calibr; calibr_1;
            m_time += m_deltaTime;
        }
    }

    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override {
        if (m_time >= std::numeric_limits<float>::max()) {
            m_time = 0.0;
        }
        std::fill(monoBuffer, monoBuffer + bufferToFill.numSamples, 0);
        mixWaves(monoBuffer, bufferToFill.numSamples);

        // iterate over all available output channels
        for (int channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel)
        {
            // Get a pointer to the start sample in the buffer for this audio output channel
            float* const buffer = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample);

            for (int sample = 0; sample < bufferToFill.numSamples; ++sample) {
                buffer[sample] = monoBuffer[sample];
            }
        }

        // update waveform and spectral views
        waveformView.fillBuffer(monoBuffer, bufferToFill.numSamples);
        //spectralView.fillBuffer(monoBuffer, bufferToFill.numSamples);
    }

    void releaseResources() override {
    }

    //==============================================================================
    void paint(Graphics& g) override {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll(Colours::white);
        waveformView.repaint();
        //spectralView.repaint();
    }

    void resized() override {
        Rectangle<int> area(getLocalBounds());
        CalibrationOsc.setBounds(0, 0, CalibrationOsc.getBounds().getWidth(), CalibrationOsc.getBounds().getHeight());
        smoothCalibrationOsc.setBounds(0, 300, smoothCalibrationOsc.getBounds().getWidth(), smoothCalibrationOsc.getBounds().getHeight());
        waveformView.setBounds(440, 0, waveformView.getBounds().getWidth(), waveformView.getBounds().getHeight());

        sineWaveOsc.setBounds(880, 0, sineWaveOsc.getBounds().getWidth(), sineWaveOsc.getBounds().getHeight());
        squareWaveOsc.setBounds(880, 150, squareWaveOsc.getBounds().getWidth(), sineWaveOsc.getBounds().getHeight());
        sawWaveOsc.setBounds(880, 300, sawWaveOsc.getBounds().getWidth(), sineWaveOsc.getBounds().getHeight());
        triangleWaveOsc.setBounds(880, 450, triangleWaveOsc.getBounds().getWidth(), sineWaveOsc.getBounds().getHeight());
        
        // waveform view
        //spectralView.setBounds(440, 300, spectralView.getBounds().getWidth(), spectralView.getBounds().getHeight());
    }

private:
    //==============================================================================
    // oscillators
    OscillatorWave sineWaveOsc;
    OscillatorWave squareWaveOsc;
    OscillatorWave sawWaveOsc;
    OscillatorWave triangleWaveOsc;
    OscillatorWaveSpec smoothCalibrationOsc;
    OscillatorWaveSpec_2 CalibrationOsc;

    WaveformViewComponent waveformView;
    // SpectralViewComponent spectralView;

     // Your private member variables go here...
    double m_time;
    double m_deltaTime;
    float* monoBuffer;

    bool m_isInitialized = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainContentComponent)
};

// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent() { return new MainContentComponent(); }
#endif  // MAINCOMPONENT_H_INCLUDED

