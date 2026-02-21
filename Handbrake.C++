#include "UnoJoy.h"

const int POT_PIN = A0;
const bool INVERT = true;

const int RAW_MIN = 0;     // handbrake fully down
const int RAW_MAX = 1023;  // handbrake fully pulled

void setup() {
  setupUnoJoy();
}

void loop() {
  dataForController_t controllerData = getBlankDataForController();

  int raw = analogRead(POT_PIN);
  if (INVERT) raw = 1023 - raw;

  // Clamp
  if (raw < RAW_MIN) raw = RAW_MIN;
  if (raw > RAW_MAX) raw = RAW_MAX;

  int axis = map(raw, RAW_MIN, RAW_MAX, 0, 127);

  // Use a stick axis, but keep it positive
  controllerData.leftStickX = axis;

  setControllerData(controllerData);
  delay(5);
  axis = map(raw, RAW_MIN, RAW_MAX, 0, 127);
  axis = (axis * axis) / 127; // curve
}