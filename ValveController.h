#ifndef VALVE_CONTROLLER_H
#define VALVE_CONTROLLER_H

class ValveController {
public:
  void begin();
  void update();
  void openValve();
  void closeValve();
private:
  bool valveState = false;
};

#endif
