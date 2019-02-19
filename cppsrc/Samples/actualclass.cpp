#include "actualclass.h"

ActualClass::ActualClass(double value) { this->value = value; }
double ActualClass::getValue() { return this->value; }
double ActualClass::add(double toAdd) { return this->value += toAdd }
