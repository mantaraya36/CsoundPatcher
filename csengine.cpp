#include "csengine.h"

#include <iostream>
#include <sstream>


namespace cspat {

CsEngine::CsEngine()
{
    m_csoundRunning = false;
    m_instrCount = 0;
    initialize();
}

int CsEngine::initialize(int sr, int ksmps, bool rt, int numchnls)
{
    if (!m_csoundRunning) {
        m_sr = sr;
        m_ksmps = ksmps;
        m_rt = rt;
        m_numchnls = numchnls;
        m_csound.Reset();
        std::ostringstream orc;
        orc << "sr = " << m_sr << std::endl << "ksmps = " << m_ksmps << std::endl;
        orc << "0dbfs =  1.0" << std::endl << "nchnls = " << m_numchnls << std::endl;
        m_csound.CompileOrc(orc.str().c_str());
        m_csound.SetOption("-odac");
        m_csound.SetOption("-iadc");
        return 0;
    } else {
        std::cout << "Warning: CsEngine running, call to initialize() ignored." << std::endl;
        return -1;
    }
}

void CsEngine::play()
{
    m_csoundRunning = true;
//    CSOUND_PARAMS *params;
//    m_csound.GetParams(params);
//    params->daemon = 1;
//    m_csound.SetParams(params);
    m_csound.CreateMessageBuffer(1);
    m_csound.Start();
    m_perfThread = new CsoundPerformanceThread(m_csound.GetCsound());
    m_perfThread->Play();
}

int CsEngine::status()
{
    // FIXME: protect with lock
    if (m_csoundRunning && m_perfThread->GetStatus() == 0) {
        return 0;
    } else {
        return 1;
    }
}

void CsEngine::stop()
{
    m_perfThread->Stop();
    m_perfThread->Join();
    delete m_perfThread;
    m_csound.Reset();
    m_csoundRunning = false;
}


int CsEngine::publishSynth(Signal &s, int instrNum)
{
    int numParentTokens = s.getParentTokenNumber();
    std::vector<std::string> tokens;
    while (numParentTokens--) {
        std::ostringstream ss;
        ss << "a" << numParentTokens;
        tokens.push_back(ss.str());
    }

    std::ostringstream orc;
    if (instrNum < 1) {
        instrNum = ++m_instrCount;
    }
    orc << "instr " << instrNum << std::endl << s.getOrc(tokens) << std::endl << "endin" << std::endl ;

    std::cout << orc.str();
    m_csound.CompileOrc(orc.str().c_str());
    return instrNum;
}

void CsEngine::synth(int instrNum, double dur, double offset, std::vector<double> parameters)
{
    if (m_csoundRunning) {
        parameters.insert(parameters.begin(), dur);
        parameters.insert(parameters.begin(), offset);
        parameters.insert(parameters.begin(), instrNum);
        m_perfThread->ScoreEvent(0, 'i', parameters.size(), parameters.data());
    } else {
        std::cout << "Warning: cannot instantiate synth. Csound not running." << std::endl;
    }
}

}
