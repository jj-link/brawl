#include <types.h>
#pragma force_active on

class soHelper {
public:
    virtual void vf0();
    virtual void* vf1();
};

struct Ret {
    s32 a;
    s32 b;
};

struct Outer {
    u8 pad[0x10];
    soHelper helper;
};

extern "C" {
s32 fn_27_1C220C(Outer* p) {
    return ((Ret*)p->helper.vf1())->b;
}
}
