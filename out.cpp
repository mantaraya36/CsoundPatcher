#include "out.h"
#include <iostream>

namespace cspat {

Out::Out(Signal &out, Signal &mult, Signal &add) :
    Signal("out", 0)
{
    m_add = &add;
    priv->m_inSigs.clear();
    priv->m_inSigs.push_back(out);
}

Out::Out(Signal &out) :
    Signal("out", 0)
{
    priv->m_inSigs.clear();
    priv->m_inSigs.push_back(out);
}

}
