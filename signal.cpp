#include <iostream>
#include "signal.h"

Signal::Signal()
{
}

Signal::Signal(const Signal &sig)
{
    std::cout << "Copy constructor----" << std::endl;
    priv = sig.priv;
    priv->reference();
}

Signal::Signal(std::string opcode, int numOutSigs) :
    m_opcode(opcode), m_numOutTokens(numOutSigs)
{
    priv = new Signal_Priv;
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

Signal& Signal::operator+(const Signal &right)
{
    // TODO: check for feedback in all operators (and implement properly or give an error)

    Signal out();

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

Signal Signal::operator =(const Signal &value)
{
    Signal outsig = value; // use copy constructor
    return outsig;
}


std::string Signal::getOrc(std::vector<std::string> outtokens)
{
    std::string orc;
    orc += m_opcode;
    return orc;
}


Value::Value(double value) :
    Signal("", 1)
{
    std::cout << "Value created: " << value << std::endl;
    m_value = value;
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
