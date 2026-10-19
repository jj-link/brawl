#include <types.h>
#pragma force_active on

class soBaseWork {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual u32 f3();
    virtual void f4();
    virtual u32 f5();
};

extern "C" {
bool fn_27_106BB4(soBaseWork* p) {
    return !p->f3();
}
}
