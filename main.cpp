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
    SinOsc s2(s); // asig2 poscil 1, 500
    SinOsc s3(s);
//    Out out(s3 + s2); // out asig2
    Out out(s); // out asig2
    //SinOsc s(SinOsc(Value(50))+100); // asig poscil 1, 50 --- asig2 poscil 1, asig + 100
    CsEngine e;
    int synthId = e.publishSynth(out);
    e.play();
    e.synth(synthId, 2);
    e.synth(synthId, 2, 3);
    while (e.status() == 0) {

    };
    return 0;
}

