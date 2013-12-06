#ifndef SINOSC_H
#define SINOSC_H

#include "signal.h"
#include <string>

namespace cspat {

class SinOsc : public Signal
{
public:
    SinOsc(SinOsc &freq);
    SinOsc(Signal freq);
    SinOsc(double freq);
    SinOsc(Signal &freq, Signal &mult, Signal &add);
private:
};
}

#endif // SINOSC_H
