#ifndef SINOSC_H
#define SINOSC_H

#include "signal.h"

class SinOsc : public Signal
{
public:
    SinOsc(Signal freq, Signal mult = Value(1.0), Signal add = Value(0.0));

private:
};

#endif // SINOSC_H
