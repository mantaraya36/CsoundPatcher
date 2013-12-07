#ifndef CSENGINE_H
#define CSENGINE_H

#include <string>
#include <vector>

#include <csound.hpp>
#include <csPerfThread.hpp>

#include "signal.h"

namespace cspat {

class CsEngine
{
public:
    CsEngine();

    std::vector<std::string> listInputDevices();
    std::vector<std::string> listOutputDevices();
    std::vector<std::string> listMidiInputDevices();
    std::vector<std::string> listMidiOutputDevices();

    int initialize(int sr = 44100, int ksmps = 128, bool rt = true, int numchnls = 2);

    void play();
    int status();
    void stop();

    int publishSynth(Signal &s, int instrNum = 0);

    void synth(int instrNum, double dur, double offset = 0.0, std::vector<double> parameters = std::vector<double>());

private:
    int m_sr;
    int m_ksmps;
    int m_numchnls;
    bool m_rt;
    std::string inDevice;  // Device for rt mode or filename for non-rt
    std::string outDevice;
    Csound m_csound;
    CsoundPerformanceThread *m_perfThread;
    bool m_csoundRunning;
    int m_instrCount;
};

}

#endif // CSENGINE_H
