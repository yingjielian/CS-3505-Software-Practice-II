#ifndef CARDEF// Means "if not defined"
#define CARDEF
// No implements in header file e.g initializes
class Car {
  double speed;

public:
  Car(double);
  void drive();

  void slow();

  void speedUp();
};
#endif
