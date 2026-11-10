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
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9(int, int);
};

struct Outer {
    char pad0[8];
    Object_vptr_0* inner;
    char padC[4];
    int value10;
    int value14;
    char pad18[4];
    int value1C;
    int value20;
};

extern "C" void fn_80281304(Outer* a, int x, int y) {
    a->value1C = -1;
    a->value20 = -1;
    a->value10 = 0;
    a->value14 = 0;
    a->inner->slot9(x, y);
}
