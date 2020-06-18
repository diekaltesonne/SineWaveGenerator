
#include "OscillatorWave.h"
//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]
OscillatorWave::OscillatorWave ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]
    setName ("OscillatorWave");
    addAndMakeVisible (volumeSlider = new Slider ("volumeSlider"));
    volumeSlider->setRange (-96, 6, 0);
    volumeSlider->setSliderStyle (Slider::LinearHorizontal);
    volumeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    volumeSlider->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Volume")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    addAndMakeVisible (phaseSlider = new Slider ("phaseSlider"));
    phaseSlider->setRange (0, 1, 0);
    phaseSlider->setSliderStyle (Slider::LinearHorizontal);
    phaseSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    phaseSlider->addListener (this);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Phase")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (freqSlider = new Slider ("freqSlider"));
    freqSlider->setRange (20, 22000, 0);
    freqSlider->setSliderStyle (Slider::LinearHorizontal);
    freqSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    freqSlider->addListener (this);

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Freq")));
    label3->setFont (Font (15.00f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (title = new Label ("title",
                                          TRANS("Sine Wave\n")));
    title->setFont (Font (15.00f, Font::plain));
    title->setJustificationType (Justification::centredLeft);
    title->setEditable (false, false, false);
    title->setColour (TextEditor::textColourId, Colours::black);
    title->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (mute = new ToggleButton ("mute"));
    mute->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (440, 150);


    //[Constructor] You can add your own custom stuff here..
    volumeSlider->setTextValueSuffix(" db");
    volumeSlider->setValue(-24);
    volumeSlider->setSkewFactorFromMidPoint(-36);

    phaseSlider->setTextValueSuffix(" ~");
    phaseSlider->setValue(0.0);

    freqSlider->setTextValueSuffix(" Hz");
    freqSlider->setValue(300);
    freqSlider->setSkewFactorFromMidPoint(500.0);
    //[/Constructor]
}
OscillatorWave::~OscillatorWave()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    volumeSlider = nullptr;
    label = nullptr;
    phaseSlider = nullptr;
    label2 = nullptr;
    freqSlider = nullptr;
    label3 = nullptr;
    title = nullptr;
    mute = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}
void OscillatorWave::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xfffeb800));

    //[UserPaint] Add your own custom painting code here..
    g.fillAll(m_color);
    //[/UserPaint]
}
void OscillatorWave::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    volumeSlider->setBounds (100, 44 - (24 / 2), 300, 24);
    label->setBounds (100 + -70, (44 - (24 / 2)) + 0, 60, 24);
    phaseSlider->setBounds (100, 82 - (24 / 2), 300, 24);
    label2->setBounds (100 + -70, (44 - (24 / 2)) + 38, 60, 24);
    freqSlider->setBounds (100, 119 - (24 / 2), 300, 24);
    label3->setBounds (100 + -70, (44 - (24 / 2)) + 75, 60, 24);
    title->setBounds (32, 8, 150, 24);
    mute->setBounds (336, 8, 56, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}
void OscillatorWave::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == volumeSlider)
    {
        //[UserSliderCode_volumeSlider] -- add your slider handling code here..
        wave->setAmplitude(dbToLinear(volumeSlider->getValue()));
        //[/UserSliderCode_volumeSlider]
    }
    else if (sliderThatWasMoved == phaseSlider)
    {
        //[UserSliderCode_phaseSlider] -- add your slider handling code here..
        wave->setPhase(phaseSlider->getValue());
        //[/UserSliderCode_phaseSlider]
    }
    else if (sliderThatWasMoved == freqSlider)
    {
        //[UserSliderCode_freqSlider] -- add your slider handling code here..
        wave->setFrequency(freqSlider->getValue());
        //[/UserSliderCode_freqSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}
void OscillatorWave::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == mute)
    {
        //[UserButtonCode_mute] -- add your button handler code here..
        if (!wave->isMuted()) { 
            wave->muteOn(); 
        } else { 
            wave->muteOff();
        }
        //[/UserButtonCode_mute]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

OscillatorWaveSpec::OscillatorWaveSpec(){
    setName("OscillatorWave");
    addAndMakeVisible(volumeSlider = new Slider("volumeSlider"));
    volumeSlider->setRange(-96, 6, 0);
    volumeSlider->setSliderStyle(Slider::LinearHorizontal);
    volumeSlider->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    volumeSlider->addListener(this);

    addAndMakeVisible(label = new Label("new label",
        TRANS("Volume")));
    label->setFont(Font(15.00f, Font::plain));
    label->setJustificationType(Justification::centredLeft);
    label->setEditable(false, false, false);
    label->setColour(TextEditor::textColourId, Colours::black);
    label->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    addAndMakeVisible(phaseSlider = new Slider("phaseSlider"));
    phaseSlider->setRange(0, 1, 0);
    phaseSlider->setSliderStyle(Slider::LinearHorizontal);
    phaseSlider->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    phaseSlider->addListener(this);

    addAndMakeVisible(label2 = new Label("new label",
        TRANS("Phase")));
    label2->setFont(Font(15.00f, Font::plain));
    label2->setJustificationType(Justification::centredLeft);
    label2->setEditable(false, false, false);
    label2->setColour(TextEditor::textColourId, Colours::black);
    label2->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    addAndMakeVisible(freqSlider = new Slider("freqSliderHigh"));
    freqSlider->setRange(20, 22000, 0);
    freqSlider->setSliderStyle(Slider::LinearHorizontal);
    freqSlider->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    freqSlider->addListener(this);

    addAndMakeVisible(label3 = new Label("new label",
        TRANS("FreqHigh")));
    label3->setFont(Font(15.00f, Font::plain));
    label3->setJustificationType(Justification::centredLeft);
    label3->setEditable(false, false, false);
    label3->setColour(TextEditor::textColourId, Colours::black);
    label3->setColour(TextEditor::backgroundColourId, Colour(0x00000000));


    addAndMakeVisible(freqSlider_1 = new Slider("freqSliderDown"));
    freqSlider_1->setRange(20, 22000, 0);
    freqSlider_1->setSliderStyle(Slider::LinearHorizontal);
    freqSlider_1->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    freqSlider_1->addListener(this);

    addAndMakeVisible(label4 = new Label("new label",
        TRANS("FreqDown")));
    label4->setFont(Font(15.00f, Font::plain));
    label4->setJustificationType(Justification::centredLeft);
    label4->setEditable(false, false, false);
    label4->setColour(TextEditor::textColourId, Colours::black);
    label4->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    addAndMakeVisible(title = new Label("title",
        TRANS("Sine Wave\n")));
    title->setFont(Font(15.00f, Font::plain));
    title->setJustificationType(Justification::centredLeft);
    title->setEditable(false, false, false);
    title->setColour(TextEditor::textColourId, Colours::black);
    title->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    addAndMakeVisible(mute = new ToggleButton("mute"));
    mute->addListener(this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize(440, 250);


    //[Constructor] You can add your own custom stuff here..
    volumeSlider->setTextValueSuffix(" db");
    volumeSlider->setValue(-24);
    volumeSlider->setSkewFactorFromMidPoint(-36);

    phaseSlider->setTextValueSuffix(" ~");
    phaseSlider->setValue(0.0);

    freqSlider->setTextValueSuffix(" Hz");
    freqSlider->setValue(4000);
   //freqSlider->setSkewFactorFromMidPoint(100.0);

    freqSlider_1->setTextValueSuffix(" Hz");
    freqSlider_1->setValue(200);
    //freqSlider_1->setSkewFactorFromMidPoint(100.0);

    //[/Constructor]
}
OscillatorWaveSpec::~OscillatorWaveSpec()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    volumeSlider = nullptr;
    label = nullptr;
    phaseSlider = nullptr;
    label2 = nullptr;
    freqSlider = nullptr;
    label3 = nullptr;
    freqSlider_1 = nullptr;
    label4 = nullptr;
    title = nullptr;
    mute = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}
void OscillatorWaveSpec::paint(Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll(Colour(0xfffeb800));

    //[UserPaint] Add your own custom painting code here..
    g.fillAll(m_color);
    //[/UserPaint]
}
void OscillatorWaveSpec::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    volumeSlider->setBounds(100, 44 - (24 / 2), 300, 24);
    label->setBounds(100 + -70, (44 - (24 / 2)) + 0, 60, 24);
    phaseSlider->setBounds(100, 82 - (24 / 2), 300, 24);
    label2->setBounds(100 + -70, (44 - (24 / 2)) + 38, 60, 24);
    freqSlider->setBounds(100, 119 - (24 / 2), 300, 24);
    label3->setBounds(100 + -70, (44 - (24 / 2)) + 75, 60, 24);
    freqSlider_1->setBounds(100, 156 - (24 / 2), 300, 24);
    label4->setBounds(100 + -70, (44 - (24 / 2)) + 112, 60, 24);
    title->setBounds(32, 8, 200, 24);
    mute->setBounds(336, 8, 56, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}
void OscillatorWaveSpec::sliderValueChanged(Slider* sliderThatWasMoved){
  
    if (sliderThatWasMoved == volumeSlider){
        //[UserSliderCode_volumeSlider] -- add your slider handling code here..
        wave->setAmplitude(dbToLinear(volumeSlider->getValue()));
        //[/UserSliderCode_volumeSlider]
    }
    else if (sliderThatWasMoved == phaseSlider){
        //[UserSliderCode_phaseSlider] -- add your slider handling code here..
        wave->setPhase(phaseSlider->getValue());
        //[/UserSliderCode_phaseSlider]
    }
    else if (sliderThatWasMoved == freqSlider){
        //[UserSliderCode_freqSlider] -- add your slider handling code here..
        wave->setFrequencyHigh(freqSlider->getValue());
        //[/UserSliderCode_freqSlider]
    }
    else if (sliderThatWasMoved == freqSlider_1){
        //[UserSliderCode_freqSlider] -- add your slider handling code here..
        wave->setFrequencyDown(freqSlider_1->getValue());
        //[/UserSliderCode_freqSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}
void OscillatorWaveSpec::buttonClicked(Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == mute){
        //[UserButtonCode_mute] -- add your button handler code here..
        if (!wave->isMuted()) {
            wave->muteOn();
        }
        else {
            wave->muteOff();
        }
        //[/UserButtonCode_mute]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
OscillatorWaveSpec_2::OscillatorWaveSpec_2() {
    setName("OscillatorWave");
    addAndMakeVisible(volumeSlider = new Slider("volumeSlider"));
    volumeSlider->setRange(-96, 6, 0);
    volumeSlider->setSliderStyle(Slider::LinearHorizontal);
    volumeSlider->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    volumeSlider->addListener(this);
    addAndMakeVisible(label = new Label("new label",
        TRANS("Volume")));
    label->setFont(Font(15.00f, Font::plain));
    label->setJustificationType(Justification::centredLeft);
    label->setEditable(false, false, false);
    label->setColour(TextEditor::textColourId, Colours::black);
    label->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    addAndMakeVisible(phaseSlider = new Slider("phaseSlider"));
    phaseSlider->setRange(0, 1, 0);
    phaseSlider->setSliderStyle(Slider::LinearHorizontal);
    phaseSlider->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    phaseSlider->addListener(this);

    addAndMakeVisible(label2 = new Label("new label",
        TRANS("Phase")));
    label2->setFont(Font(15.00f, Font::plain));
    label2->setJustificationType(Justification::centredLeft);
    label2->setEditable(false, false, false);
    label2->setColour(TextEditor::textColourId, Colours::black);
    label2->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    addAndMakeVisible(freqSlider = new Slider("freqSliderHigh"));
    freqSlider->setRange(20, 22000, 0);
    freqSlider->setSliderStyle(Slider::LinearHorizontal);
    freqSlider->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    freqSlider->addListener(this);
    addAndMakeVisible(label3 = new Label("new label",
        TRANS("FreqHigh")));
    label3->setFont(Font(15.00f, Font::plain));
    label3->setJustificationType(Justification::centredLeft);
    label3->setEditable(false, false, false);
    label3->setColour(TextEditor::textColourId, Colours::black);
    label3->setColour(TextEditor::backgroundColourId, Colour(0x00000000));


    addAndMakeVisible(freqSlider_1 = new Slider("freqSliderDown"));
    freqSlider_1->setRange(20, 22000, 0);
    freqSlider_1->setSliderStyle(Slider::LinearHorizontal);
    freqSlider_1->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    freqSlider_1->addListener(this);
    addAndMakeVisible(label4 = new Label("new label",
        TRANS("FreqDown")));
    label4->setFont(Font(15.00f, Font::plain));
    label4->setJustificationType(Justification::centredLeft);
    label4->setEditable(false, false, false);
    label4->setColour(TextEditor::textColourId, Colours::black);
    label4->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    addAndMakeVisible(freqSlider_2 = new Slider("freqSliderStep"));
    freqSlider_2->setRange(1, 1000, 0);
    freqSlider_2->setSliderStyle(Slider::LinearHorizontal);
    freqSlider_2->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    freqSlider_2->addListener(this);
    addAndMakeVisible(label5 = new Label("new label",
        TRANS("FreqStep")));
    label5->setFont(Font(15.00f, Font::plain));
    label5->setJustificationType(Justification::centredLeft);
    label5->setEditable(false, false, false);
    label5->setColour(TextEditor::textColourId, Colours::black);
    label5->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    addAndMakeVisible(freqSlider_3 = new Slider("freqSliderStep"));
    freqSlider_3->setRange(0, 1000, 0);
    freqSlider_3->setSliderStyle(Slider::LinearHorizontal);
    freqSlider_3->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    freqSlider_3->addListener(this);
    addAndMakeVisible(label5_1 = new Label("new label",
        TRANS("FCT")));
    label5_1->setFont(Font(15.00f, Font::plain));
    label5_1->setJustificationType(Justification::centredLeft);
    label5_1->setEditable(false, false, false);
    label5_1->setColour(TextEditor::textColourId, Colours::black);
    label5_1->setColour(TextEditor::backgroundColourId, Colour(0x00000000));



    addAndMakeVisible(sigonSlider = new Slider("SignalOnSliderStep"));
    sigonSlider->setRange(0, 1000, 0);
    sigonSlider->setSliderStyle(Slider::LinearHorizontal);
    sigonSlider->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    sigonSlider->addListener(this);
    addAndMakeVisible(label6 = new Label("new label",
        TRANS("Sig dur")));
    label6->setFont(Font(15.00f, Font::plain));
    label6->setJustificationType(Justification::centredLeft);
    label6->setEditable(false, false, false);
    label6->setColour(TextEditor::textColourId, Colours::black);
    label6->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    addAndMakeVisible(sigoffSlider = new Slider("SigofOffSliderStep"));
    sigoffSlider->setRange(0, 1000, 0);
    sigoffSlider->setSliderStyle(Slider::LinearHorizontal);
    sigoffSlider->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    sigoffSlider->addListener(this);
    addAndMakeVisible(label7 = new Label("new label",
        TRANS("Sig del")));
    label7->setFont(Font(15.00f, Font::plain));
    label7->setJustificationType(Justification::centredLeft);
    label7->setEditable(false, false, false);
    label7->setColour(TextEditor::textColourId, Colours::black);
    label7->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    addAndMakeVisible(title = new Label("title",
        TRANS("Sine Wave\n")));
    title->setFont(Font(15.00f, Font::plain));
    title->setJustificationType(Justification::centredLeft);
    title->setEditable(false, false, false);
    title->setColour(TextEditor::textColourId, Colours::black);
    title->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    addAndMakeVisible(mute = new ToggleButton("mute"));
    mute->addListener(this);
    setSize(440, 300);


    //[Constructor] You can add your own custom stuff here..
    volumeSlider->setTextValueSuffix("db");
    volumeSlider->setValue(-24);
    volumeSlider->setSkewFactorFromMidPoint(-36);

    phaseSlider->setTextValueSuffix("~");
    phaseSlider->setValue(0.0);

    freqSlider->setTextValueSuffix("Hz");
    freqSlider->setValue(4000);
    //freqSlider->setSkewFactorFromMidPoint(100.0);

    freqSlider_1->setTextValueSuffix(" Hz");
    freqSlider_1->setValue(3000);
    freqSlider_2->setTextValueSuffix(" Hz");
    freqSlider_2->setValue(1.0);
    freqSlider_3->setTextValueSuffix("SMP");
    freqSlider_3->setValue(10.0);
    sigonSlider->setTextValueSuffix("SMP");
    sigonSlider->setValue(100);
    sigoffSlider->setTextValueSuffix("SMP");
    sigoffSlider->setValue(50);
    
    //freqSlider_1->setSkewFactorFromMidPoint(100.0);
    //[/Constructor]
}
OscillatorWaveSpec_2::~OscillatorWaveSpec_2() {
    volumeSlider = nullptr;
    label = nullptr;
    phaseSlider = nullptr;
    label2 = nullptr;
    freqSlider = nullptr;
    label3 = nullptr;
    freqSlider_1 = nullptr;
    label4 = nullptr;
    freqSlider_2 = nullptr;
    label5 = nullptr;
    freqSlider_3 = nullptr;
    label5_1 = nullptr;
    sigonSlider = nullptr;
    label6 = nullptr;
    sigoffSlider = nullptr;
    label7 = nullptr;
    title = nullptr;
    mute = nullptr;
}
void OscillatorWaveSpec_2::paint(Graphics& g) {
    g.fillAll(Colour(0xfffeb800));

    //[UserPaint] Add your own custom painting code here..
    g.fillAll(m_color);
    //[/UserPaint]
}
void OscillatorWaveSpec_2::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    volumeSlider->setBounds(100, 44 - (24 / 2), 300, 24);
    label->setBounds(100 + -70, (44 - (24 / 2)) + 0, 60, 24);
    
    phaseSlider->setBounds(100, 82 - (24 / 2), 300, 24);
    label2->setBounds(100 + -70, (44 - (24 / 2)) + 38, 60, 24);
    
    freqSlider->setBounds(100, 119 - (24 / 2), 300, 24);
    label3->setBounds(100 + -70, (44 - (24 / 2)) + 75, 60, 24);
    
    freqSlider_1->setBounds(100, 156 - (24 / 2), 300, 24);
    label4->setBounds(100 + -70, (44 - (24 / 2)) + 112, 60, 24);
    
    freqSlider_2->setBounds(100, 183 - (24 / 2), 300, 24);
    label5->setBounds(100 + -70, (44 - (24 / 2)) + 139, 60, 24);
    
    freqSlider_3->setBounds(100, 210 - (24 / 2), 300, 24);
    label5_1->setBounds(100 + -70, (44 - (24 / 2)) + 161, 60, 24);
    
    sigonSlider->setBounds(100, 237 - (24 / 2), 300, 24);
    label6->setBounds(100 + -70, (44 - (24 / 2)) + 188, 60, 24);
    
    sigoffSlider->setBounds(100, 264 - (24 / 2), 300, 24);
    label7->setBounds(100 + -70, (44 - (24 / 2)) + 215, 60, 24);
    
    title->setBounds(32, 8, 200, 24);
    mute->setBounds(336, 8, 56, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}
void OscillatorWaveSpec_2::sliderValueChanged(Slider* sliderThatWasMoved)
{
    if (sliderThatWasMoved == volumeSlider){
        //[UserSliderCode_volumeSlider] -- add your slider handling code here..
        wave->setAmplitude(dbToLinear(volumeSlider->getValue()));
        //[/UserSliderCode_volumeSlider]
    }
    else if (sliderThatWasMoved == phaseSlider){
        //[UserSliderCode_phaseSlider] -- add your slider handling code here..
        wave->setPhase(phaseSlider->getValue());
        //[/UserSliderCode_phaseSlider]
    }
    else if (sliderThatWasMoved == freqSlider){
        //[UserSliderCode_freqSlider] -- add your slider handling code here..
        wave->setFrequencyHigh(freqSlider->getValue());
        //[/UserSliderCode_freqSlider]
    }
    else if (sliderThatWasMoved == freqSlider_1){
        //[UserSliderCode_freqSlider] -- add your slider handling code here..
        wave->setFrequencyDown(freqSlider_1 -> getValue());
        //[/UserSliderCode_freqSlider]
    }
    else if (sliderThatWasMoved == freqSlider_2){
        //[UserSliderCode_freqSlider] -- add your slider handling code here..
        wave->setFrequencyStep(freqSlider_2 -> getValue());
        //[/UserSliderCode_freqSlider]
    }
    else if (sliderThatWasMoved == freqSlider_3) {
        //[UserSliderCode_freqSlider] -- add your slider handling code here..
        wave->setFrequencyChangeTime(freqSlider_3->getValue());
        //[/UserSliderCode_freqSlider]
    }
    else if (sliderThatWasMoved == sigonSlider) {
        //[UserSliderCode_freqSlider] -- add your slider handling code here..
        wave->setSignalOn(sigonSlider -> getValue());
        //[/UserSliderCode_freqSlider]
    }
    else if (sliderThatWasMoved == sigoffSlider) {
        //[UserSliderCode_freqSlider] -- add your slider handling code here..
        wave->setSingalOff(sigoffSlider -> getValue());
        //[/UserSliderCode_freqSlider]
    }
    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}
void OscillatorWaveSpec_2::buttonClicked(Button* buttonThatWasClicked)
{
    if (buttonThatWasClicked == mute)
    {
        //[UserButtonCode_mute] -- add your button handler code here..
        if (!wave->isMuted()) {
            wave->muteOn();
        }
        else {
            wave->muteOff();
        }
        //[/UserButtonCode_mute]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OscillatorWave" componentName="OscillatorWave"
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="440" initialHeight="150">
  <BACKGROUND backgroundColour="fffeb800"/>
  <SLIDER name="volumeSlider" id="e9e0cf65aa868f37" memberName="volumeSlider"
          virtualName="" explicitFocusOrder="0" pos="100 44c 300 24" min="-96"
          max="6" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="684a664f9257df77" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="-70 0 60 24" posRelativeX="e9e0cf65aa868f37"
         posRelativeY="e9e0cf65aa868f37" edTextCol="ff000000" edBkgCol="0"
         labelText="Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="phaseSlider" id="eefdd53757b432cb" memberName="phaseSlider"
          virtualName="" explicitFocusOrder="0" pos="100 82c 300 24" min="0"
          max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="83473cd32c2b4d56" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="-70 38 60 24" posRelativeX="e9e0cf65aa868f37"
         posRelativeY="e9e0cf65aa868f37" edTextCol="ff000000" edBkgCol="0"
         labelText="Phase" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="freqSlider" id="7ea32f8768f5b911" memberName="freqSlider"
          virtualName="" explicitFocusOrder="0" pos="100 119c 300 24" min="20"
          max="22000" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="7e70410fcb5fa73e" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="-70 75 60 24" posRelativeX="e9e0cf65aa868f37"
         posRelativeY="e9e0cf65aa868f37" edTextCol="ff000000" edBkgCol="0"
         labelText="Freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="title" id="4519e88c87a60eec" memberName="title" virtualName=""
         explicitFocusOrder="0" pos="32 8 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sine Wave&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="mute" id="59064d43df4fe3dc" memberName="mute" virtualName=""
                explicitFocusOrder="0" pos="336 8 56 24" buttonText="mute" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
