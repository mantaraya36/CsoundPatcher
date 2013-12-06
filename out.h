#ifndef OUT_H
#define OUT_H
#include "signal.h"
#include <string>

namespace cspat {

class Out : public Signal
{
public:
    Out(Signal &out);
    Out(Signal &out, Signal &mult, Signal &add);
private:
};

}

#endif // OUT_H
