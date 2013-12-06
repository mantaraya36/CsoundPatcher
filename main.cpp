#include <iostream>
#include "csengine.h"
#include "sinosc.h"
#include "out.h"

using namespace std;
using namespace cspat;

int main()
{
//    Signal s;
//    Signal s2;
//    Signal s3 = s2;
//    s2 = s;
//    s3.setError(4);
    SinOsc s(1000); // asig poscil 1, 1000
    // SinOsc s2(500); // asig2 poscil 1, 500
    Out out(s); // out asig
    //SinOsc s(SinOsc(Value(50))+100); // asig poscil 1, 50 --- asig2 poscil 1, asig + 100
    CsEngine e;
    e.publishSynth(out);
    return 0;
}

