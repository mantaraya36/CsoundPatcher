#ifndef SIGNAL_H
#define SIGNAL_H

#include <vector>
#include <string>
#include <iostream>


enum operands { 
    ADD, 
    SUBTRACT, 
    MULTIPLY, 
    DIVIDE };

class Signal_Priv;
class Compoud_Signal;

// TODO: check which passing of variables can be turned to references, to improve peroformance while keeping compatibility with python and other interfaces
class Signal
{
    friend class CsEngine;
public:
    Signal();
    Signal(const Signal &sig);
    Signal(std::string opcode, int numOutSigs = 1);
    ~Signal();

    Signal &operator+(const Signal &right);
    Signal &operator-(const Signal &right);
    Signal &operator*(const Signal &right);
    Signal &operator/(const Signal &right);
    Signal operator=(const Signal &value);

    Signal operator+(double addedValue);

protected:
    void setError(int error) {m_error = error;}
    int getNumOutTokens() {return m_numOutTokens;}
    std::string getOrc(std::vector<std::string> outtokens);

    int signalNumber;
    void setSignalNum(int _sigNum){signalNumber = _sigNum;};
    int getSignalNum(){return signalNumber;};

    int m_error;
    int m_numOutTokens;
    std::string m_opcode;
    Signal_Priv *priv;
    Signal *m_mult, *m_add;
};

//class Add: public Signal
//{
//public:
////    Add();
//    Add(Signal left, Signal right) {
////        Add();
////        priv->m_inSigs.resize(2);
//    }
//};

class Compound_Signal: public Signal
{
public:
    Compound_Signal(Signal &_signalA, Signal &_signalB, int _operand);

private:
Signal *signalA;
Signal *signalB;
int operand;
};


class Signal_Priv
{
public:
    Signal_Priv(){m_refCounter = 1;};

    void reference(){m_refCounter++;};
    int dereference(){
      m_refCounter--;
      return m_refCounter;
    };

    std::vector<Signal> m_inSigs;
//    std::vector<Signal> m_outSigs;

private:
    int m_error;
    int m_refCounter;
};



class Value: public Signal
{
public:
    Value(double value);

private:
    double m_value;
};

#endif // SIGNAL_H
