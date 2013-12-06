#include "sinosc.h"
#include <iostream>

namespace cspat {

SinOsc::SinOsc(Signal &freq, Signal &mult, Signal &add) :
    Signal("poscil")
{
    m_add = &add;
    priv->m_inSigs.clear();
    priv->m_inSigs.push_back(mult);
    priv->m_inSigs.push_back(freq);
}

SinOsc::SinOsc(SinOsc &freq) :
    Signal("poscil")
{
    priv->m_inSigs.clear();
    priv->m_inSigs.push_back(Value(1));
    priv->m_inSigs.push_back(freq);
}

SinOsc::SinOsc(Signal freq) :
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


}
