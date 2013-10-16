#include <iostream>
#include "csengine.h"
#include "sinosc.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
//    Signal s;
//    Signal s2;
//    Signal s3 = s2;
//    s2 = s;
//    s3.setError(4);
    SinOsc s(Value(1000)); // asig poscil 1, 1000
    CsEngine e;
    e.publishSynth(s);
    return 0;
}

