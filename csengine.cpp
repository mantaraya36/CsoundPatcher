#include "csengine.h"

#include <iostream>

CsEngine::CsEngine()
{
}


void CsEngine::publishSynth(Signal &s, int instrNum)
{
    int numOutTokens = s.getNumOutTokens();
    std::vector<std::string> tokens;
    for (int i = 0; i < numOutTokens; i++) {
        tokens.push_back("a1");
    }
    std::cout << s.getOrc(tokens) << std::endl;
}
