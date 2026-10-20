#include <types.h>
#pragma force_active on

struct SoCallArg {
    s32 value;
    u8 flag;
};

struct SoVirtObj {
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void call(s32 a, SoCallArg* arg, s32 b) = 0;
};

extern "C" {
void fn_27_23CC0(u8* self, f32 value) {
    *(f32*)(self + 0x40) = value;

    SoCallArg arg;
    arg.value = 5;
    arg.flag = 0;

    u8* obj = *(u8**)(self + 0x8);
    obj = *(u8**)(obj + 0xD8);
    obj = *(u8**)(obj + 0x54);

    ((SoVirtObj*)obj)->call(-1, &arg, 0x200);
}
}
