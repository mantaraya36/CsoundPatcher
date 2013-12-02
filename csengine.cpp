#include "csengine.h"

#include <iostream>
#include <sstream>


CsEngine::CsEngine()
{
}


void CsEngine::publishSynth(Signal &s, int instrNum)
{
    int numParentTokens = s.getParentTokenNumber();
    std::vector<std::string> tokens;
    for (int i = 0; i < numParentTokens; i++) {
        std::ostringstream ss;
        ss << "a" << i;
        tokens.push_back(ss.str());
    }
    std::cout << s.getOrc(tokens) << std::endl;
}
