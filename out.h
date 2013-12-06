#ifndef OUT_H
#define OUT_H
#include "signal.h"
#include <string>

namespace cspat {

class Out : public Signal
{
public:
    Out(Signal &freq);
    Out(double freq);
    Out(Signal &freq, Signal &mult, Signal &add);
    virtual std::string getOrc(std::vector<std::string> &outtokens);
private:
};

}

#endif // OUT_H
