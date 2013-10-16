#include "sinosc.h"

SinOsc::SinOsc(Signal freq, Signal mult, Signal add) :
    Signal("poscil", 1)
{
    m_mult = &mult;
    m_add = &add;
    priv->m_inSigs.clear();
    priv->m_inSigs.push_back(freq);
}

