#ifndef SIGNAL_H
#define SIGNAL_H

#include <vector>
#include <string>

class Signal_Priv;

// TODO: check which passing of variables can be turned to references, to improve peroformance while keeping compatibility with python and other interfaces
class Signal
{
    friend class CsEngine;
public:
    //Signal();
    //Signal(const Signal &sig);
    Signal(std::string opcode, int numOutSigs = 1);
    ~Signal();

    Signal &operator+(const Signal &right);
    Signal &operator-(const Signal &right);
    Signal &operator*(const Signal &right);
    Signal &operator/(const Signal &right);
    Signal &operator=(const Signal &value);

    std::vector<std::string> getOutputTokens() {return m_outTokens;}
    virtual std::string getOrc(std::vector<std::string> &outtokens) { return "";}

protected:
    void setError(int error) {m_error = error;}
    int getParentTokenNumber();

    int m_error;
    int m_numOutTokens;
    std::vector<std::string> m_outTokens;
    std::string m_opcode;
    Signal_Priv *priv;
    Signal *m_mult, *m_add;
};

class Signal_Priv
{
public:
    Signal_Priv();

    void reference();
    int dereference();

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
protected:
    std::string getOrc(std::vector<std::string> &outtokens);
private:
    double m_value;
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


#endif // SIGNAL_H
