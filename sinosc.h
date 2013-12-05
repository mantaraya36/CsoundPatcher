#ifndef SINOSC_H
#define SINOSC_H

#include "signal.h"
#include <string>

class SinOsc : public Signal
{
public:
    SinOsc(Signal &freq);
    SinOsc(double freq);
    SinOsc(Signal &freq, Signal &mult, Signal &add);
    virtual std::string getOrc(std::vector<std::string> &outtokens);
private:
};

#endif // SINOSC_H
