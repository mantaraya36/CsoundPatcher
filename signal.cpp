#include <iostream>
#include <sstream>
#include "signal.h"


namespace cspat {

//Signal::Signal()
//{
//}

//Signal::Signal(const Signal &sig)
//{
//    std::cout << "Signal Copy constructor----" << std::endl;
//    priv = sig.priv;
//    priv->reference();
//    m_numOutTokens = 0;
//}

Signal::Signal(std::string opcode, int numOutSigs) :
    m_opcode(opcode), m_numOutTokens(numOutSigs)
{
    priv = new Signal_Priv;
    m_used = false;
    std::cout << opcode << " created." << std::endl;
//    m_inSigs = inSigs;
}

Signal::~Signal()
{
    int refs = priv->dereference();
    if (refs == 0) {
        delete priv;
    }
}

std::string Signal::getOrc(std::vector<std::string> &outtokens)
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

    if (orc.size() > 0 && orc.at(orc.size() - 1) == ',') {
        orc = orc.substr(0, orc.size()-1);
        orc += " ";
    }
    orc += m_opcode + " ";
    for (int i = 0; i < parentOutTokens.size(); i++) {
        orc += parentOutTokens[i] + ",";
    }
    if (parentOutTokens.size() > 0) {
        orc = orc.substr(0, orc.size()-1);
    }
    orc += "\n";
    m_used = true;
    return orc;
}

Signal& Signal::operator+(const Signal &right)
{
    // TODO: check for feedback in all operators (and implement properly or give an error)
    std::cout << "Signal::operator+" << std::endl;

    //Signal out();
    return *this;
}

Signal& Signal::operator-(const Signal &right)
{

}

Signal& Signal::operator*(const Signal &right)
{

}

Signal& Signal::operator/(const Signal &right)
{

}

//Signal& Signal::operator+=(const Signal &right)
//{

//}

//Signal& Signal::operator-=(const Signal &right)
//{

//}

//Signal& Signal::operator*=(const Signal &right)
//{

//}

//Signal& Signal::operator/=(const Signal &right)
//{

//}

Signal &Signal::operator =(const Signal &value)
{
    //Signal outsig = value; // use copy constructor
    //return outsig;
}

int Signal::getParentTokenNumber()
{
    int totalTokens = 0;
    for (int i = 0; i < priv->m_inSigs.size(); i++) {
        totalTokens +=  priv->m_inSigs[i].getParentTokenNumber();
    }
    totalTokens += m_numOutTokens;
    return totalTokens;
}


Value::Value(double value) :
    Signal("", 0)
{
    std::cout << "Value created: " << value << std::endl;
    std::ostringstream ss;
    ss << value;
    m_outTokens.push_back(ss.str());
}

//Add::Add()
//{
//    m_opcode = "+";
//}


Signal_Priv::Signal_Priv()
{
    m_refCounter = 1;
}

void Signal_Priv::reference()
{
    m_refCounter++;
}

int Signal_Priv::dereference()
{
    m_refCounter--;
    return m_refCounter;
}

}
