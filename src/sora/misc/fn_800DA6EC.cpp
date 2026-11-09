#include <mu/mu_object.h>
#pragma force_active on

extern "C" int fn_800DA81C(void* self, int value, int digits, int skipZeros, int base, int idx);

class Obj {
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12(int) = 0;
    char pad[0xE0];
    int count;
};

struct Self {
    char _000[0x40];
    MuObject* f40;
    char _044[0x54 - 0x44];
    Obj* f54;
    char _058[0x60 - 0x58];
    int f60;
    int f64;
};

extern "C" void fn_800DA6EC(Self* self, int arg1, int arg2) {
    Obj* o;
    int n;
    float f;

    o = self->f54;
    while (n = o->count) {
        if (n == 0) continue;
        o->slot12(n - 1);
    }
    if (self->f64 == 0) {
        fn_800DA81C(self, arg1, self->f60, 1, 0, 1);
        f = (float)(self->f60 - 1);
    } else {
        fn_800DA81C(self, arg2, 2, 0, 0, 1);
        fn_800DA81C(self, arg1, 2, 1, 2, 3);
        f = (float)(self->f60 + 2);
    }
    self->f40->setFrameNode(f);
}
