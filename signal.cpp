#include "signal.h"

Signal::Signal()
{
}

Signal::Signal(const Signal &sig)
{
    //std::cout << "Copy constructor----" << std::endl;
    priv = sig.priv;
    priv->reference();
}

Signal::Signal(std::string opcode, int numOutSigs) :
    m_opcode(opcode), m_numOutTokens(numOutSigs)
{
    priv = new Signal_Priv;
    //std::cout << opcode << " created." << std::endl;
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

//We should just template this for all added types
Signal Signal::operator+(double addedValue)
{
    //this will totally memory leak
    //needs to be a scoped pointer
    Value* newValue = new Value(addedValue);
    return Compound_Signal(*this, *newValue);
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
    //std::string sigNumStr = std::to_string(signalNumber);
    //orc += "asig" + sigNumStr + " ";
    orc += "asig ";
    for (int i = 0; i < outtokens.size(); i++) {
        orc += outtokens[i] + " ";
    }
    orc += m_opcode + " ";
    for (int i = 0; i < priv->m_inSigs.size(); i++) {
        int numOutTokens =  priv->m_inSigs[i].getNumOutTokens();
        std::vector<std::string> tokens;
        orc += "a1, ";
    }
    return orc;
}


Compound_Signal::Compound_Signal(Signal &_signalA, Signal &_signalB)
{
    std::cout << "Compound Signal created." << std::endl;

    signalA = &_signalA;
    signalB = &_signalB;
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
