#include <types.h>
#pragma force_active on

class Thing {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual u32 call2(u32, u32);
    virtual u32 call1(u32);
};

extern "C" u32 fn_27_156940(Thing* a, u32 b, u32 c) {
    if (a->call1(c) == 1) {
        if (a->call2(b, c) == 1) {
            return (u32)-1;
        }
    }
    return b;
}
