#ifndef CSENGINE_H
#define CSENGINE_H

#include <string>
#include <vector>
#include "csound.hpp"

#include "signal.h"

class CsEngine
{
public:
    CsEngine();

    std::vector<std::string> listInputDevices();
    std::vector<std::string> listOutputDevices();
    std::vector<std::string> listMidiInputDevices();
    std::vector<std::string> listMidiOutputDevices();

    void start();
    void stop();

    void publishSynth(Signal s);

private:
    int sr;
    int ksmps;
    bool rt;
    std::string inDevice;  // Device for rt mode or filename for non-rt
    std::string outDevice;
};

#endif // CSENGINE_H
