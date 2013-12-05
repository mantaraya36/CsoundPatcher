#include "sinosc.h"
#include <iostream>

SinOsc::SinOsc(Signal &freq, Signal &mult, Signal &add) :
    Signal("poscil")
{
    m_add = &add;
    priv->m_inSigs.clear();
    priv->m_inSigs.push_back(mult);
    priv->m_inSigs.push_back(freq);
}

SinOsc::SinOsc(Signal &freq) :
    Signal("poscil")
{
    priv->m_inSigs.clear();
    priv->m_inSigs.push_back(Value(1));
    priv->m_inSigs.push_back(freq);
}

SinOsc::SinOsc(double freq) :
    Signal("poscil")
{
    priv->m_inSigs.push_back(Value(1));
    priv->m_inSigs.push_back(Value(freq));
}


std::string SinOsc::getOrc(std::vector<std::string> &outtokens)
{
    std::string orc;
    std::vector<std::string> parentOutTokens;
    for (int i = 0; i < priv->m_inSigs.size(); i++) {
        orc += priv->m_inSigs[i].getOrc(outtokens);
        std::vector<std::string> tokens = priv->m_inSigs[i].getOutputTokens();
        std::cout << "tokens " << tokens.size() << std::endl;
        for (int j = 0; j < tokens.size(); j++) {
            parentOutTokens.push_back(tokens[j]);
            std::cout << tokens[j] << "---" << std::endl;
        }
    }
    for (int i = 0; i < m_numOutTokens; i++) {
        orc += outtokens.back() + ",";
        m_outTokens.push_back(outtokens.back());
        outtokens.pop_back();
    }
    if (orc.size() > 0) {
        orc = orc.substr(0, orc.size()-1);
    }
    orc += " " + m_opcode + " ";
    for (int i = 0; i < parentOutTokens.size(); i++) {
        orc += parentOutTokens[i] + ",";
    }
    if (parentOutTokens.size() > 0) {
        orc = orc.substr(0, orc.size()-1);
    }
    orc += "\n";
    return orc;
}
