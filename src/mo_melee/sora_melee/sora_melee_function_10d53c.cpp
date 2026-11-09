#include <types.h>
#pragma force_active on

extern "C" {

void fn_27_1179BC(void* obj, s32 arg, float f);

class Class_90D8 {
public:
    virtual void fn_27_7B274();       // vtable 0x8
    virtual void** fn_27_7AC18(s32 idx);  // vtable 0xc
    virtual void fn_27_7AC28();       // vtable 0x10
    virtual s32 fn_27_7AB50();        // vtable 0x14
};

struct Outer {
    u8 pad[8];
    Class_90D8 inner;
};

struct Holder {
    u8 pad[0x154];
    Outer* outer;
};

void fn_27_10D53C(Holder* self, s32 arg1, float farg) {
    s32 count = self->outer->inner.fn_27_7AB50();
    for (s32 i = 0; i < count; i++) {
        fn_27_1179BC(*self->outer->inner.fn_27_7AC18(i), arg1, farg);
    }
}

}
