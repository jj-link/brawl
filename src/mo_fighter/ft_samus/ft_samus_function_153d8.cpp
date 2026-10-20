#include <types.h>
#pragma force_active on

class acCmdInterpreterStackData;

template <class T, int N>
class soArrayVector {
public:
    ~soArrayVector();
};

extern "C" {
void __dl__FPv(void*);
}

extern "C" soArrayVector<acCmdInterpreterStackData, 1>* fn_94_153D8(soArrayVector<acCmdInterpreterStackData, 1>* p, s16 flag) {
    if (p != 0) {
        p->~soArrayVector();
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
