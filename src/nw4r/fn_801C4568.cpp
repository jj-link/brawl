#include <types.h>
#pragma force_active on

extern "C" void fn_801C3540(void* p, s32 a, s32 b);
extern "C" void fn_801C380C(void* p, s32 x, s32 count);

struct Obj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(s32);

    unsigned char pad0[0xD8 - 4];
    unsigned char pad1[0x1FC - 0xD8];
    s32 w1FC;
    s32 w200;
    s32 w204;
    unsigned char b208;
    unsigned char b209;
};

extern "C" void fn_801C4568(s32 arg0, s32 unused, Obj* self) {
    self->b208 = 0;
    if (arg0 == 0) {
        self->slot4(0);
        return;
    }
    fn_801C3540((char*)self + 0xD8, unused, self->w1FC);
    s32 count = self->w204;
    if (count > 0) {
        fn_801C380C(self->pad1, self->w200, count);
    }
    self->b209 = 1;
}
