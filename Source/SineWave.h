#pragma once
#include "IWave.h"
#include "../JuceLibraryCode/JuceHeader.h"

class SineWave : public IWave
{
public:
    SineWave() {};
    ~SineWave() {};
    double sample(double t, int len) override {
        return level * sin(2 * double_Pi * frequency * t + phase);
    };
};

class SmoothCalibrationWave : public IWave
{
public:

    SmoothCalibrationWave() {};
    ~SmoothCalibrationWave() {};

    double getFrequencyHigh() { return this->freq_high; }
    double getFrequencyDown() { return this->freq_down; }
    void setFrequencyHigh(double value) { this->freq_high = value; };
    void setFrequencyDown(double value) { this->freq_down = value; };
    double sample(double t, int len) override {
        frequency += 1;
        if (frequency > freq_high) {
            frequency = freq_down;
        }
        return level * sin(2 * double_Pi * frequency * t + phase);
    };
private:
    double freq_high =4000;
    double freq_down = 300;
};


class CalibrationWave : public IWave
{
public:
    CalibrationWave(){};
    ~CalibrationWave(){};

    double getFrequencyHigh() { return this->freq_high;}
    double getFrequencyDown() { return this->freq_down;}
    double getFrequencyStep() { return this->freq_step;}
    double getSignalOn() { return this->signal_on; }
    double getSignalOff() { return this->signal_off;}
    double getFrequencyChangeTime() { return this->freq_c_t; }

    void setFrequencyHigh(double value) { this->freq_high = value;}
    void setFrequencyDown(double value) { this->freq_down = value;}
    void setFrequencyStep(double value) { this->freq_step = value;}
    void setFrequencyChangeTime(double value) { this->freq_c_t = value; }
    void setSignalOn(double value) {this->signal_on = value;}
    void setSingalOff(double value) { this->signal_off = value;}

    double sample(double t, int len) override {  
        i++;
        k++;
        if (k <= freq_c_t) {
            frequency += freq_step;
        }
        else {
            k = 0;
        }
        if (frequency > freq_high) {
            frequency = freq_down;
        }

        if (i>= (signal_on + signal_off)) {
            i = 0;
        }
        if (i <=signal_on) {
            return level * sin(2 * double_Pi * frequency * t + phase);
        }else{
            return 0;
        }
    };

private:
    int signal_on = 0;
    int signal_off = 0;
    int freq_c_t =5;
    int i = 0;
    int k = 0;
    double freq_high = 4000;
    double freq_down = 300;
    double freq_step = 1;
};

