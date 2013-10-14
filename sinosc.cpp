#include "sinosc.h"

SinOsc::SinOsc(Signal freq, Signal mult, Signal add) :
    Signal("poscil", 1)
{
    m_mult = &mult;
    m_add = &add;
    priv->m_inSigs.resize(1);
    priv->m_inSigs[0] = freq;
}

