#include <types.h>
#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int slot6(void*);
    virtual void slot7();
    virtual void slot8();
    virtual unsigned int slot9(int);
    virtual unsigned int slot10(int);
};
struct Mods {
    char pad0[0x3c];
    Object_vptr_0* a;
    char pad1[0x14];
    Object_vptr_0* b;
};
struct Mid {
    char pad[0xd8];
    Mods* mods;
};
struct Outer {
    char pad[0x10];
    Mid* mid;
};
extern "C" int fn_27_661D4(Outer* self) {
    if (self->mid->mods->a->slot6(self->mid) == 0) {
        if (self->mid->mods->b->slot10(0) == 1U) {
            return 1;
        }
        if (self->mid->mods->b->slot9(0) == 1U) {
            return 1;
        }
    }
    return 0;
}