struct InputSettings : SettingsLayout {
  Label title;
  HorizontalLayout focusLayout;
    Label focusLabel;
    CheckBox focusPause;
    CheckBox focusAllow;
  HorizontalLayout selectionLayout;
    ComboBox systemList;
    ComboBox portList;
    ComboBox deviceList;
  ListView inputList;
  HorizontalLayout controlLayout;
    Button assign[5];
    Widget spacer;
    Button resetButton;
    Button eraseButton;

  void synchronize();

  Emulator::Interface& activeSystem();
  Emulator::Interface::Port& activePort();
  Emulator::Interface::Device& activeDevice();

  void systemChanged();
  void portChanged();
  void deviceChanged();
  void inputChanged();
  void resetInput();
  void eraseInput();
  void assignInput();
  void assignMouseInput(unsigned n);
  void inputEvent(unsigned scancode, int16_t value, bool allowMouseInput = false);
  InputSettings();

private:
  AbstractInput *activeInput;
};

extern InputSettings *inputSettings;
