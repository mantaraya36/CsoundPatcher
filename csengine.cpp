#include "csengine.h"

#include <iostream>
#include <sstream>


namespace cspat {

CsEngine::CsEngine()
{
}


void CsEngine::publishSynth(Signal &s, int instrNum)
{
    int numParentTokens = s.getParentTokenNumber();
    std::vector<std::string> tokens;
    while (numParentTokens--) {
        std::ostringstream ss;
        ss << "a" << numParentTokens;
        tokens.push_back(ss.str());
    }
    std::cout << s.getOrc(tokens) << std::endl;
}

}
