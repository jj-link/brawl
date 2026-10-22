#include <types.h>
#pragma force_active on

extern "C" void fn_27_A6DEC(int, int, int);

class Item {
public:
    u8 pad[0x1D];
    u8 unk1D;
};

class Obj {
public:
    virtual void v_c();
    virtual Item* v3(int index);
    virtual void v_d();
    virtual int v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};

class Owner {
public:
    u8 pad[0x30];
    Obj* unk30;
    Obj* unk34;
    u8 pad2[0x45 - 0x38];
    u8 unk45;
    u8 pad3[2];
    int unk48;
};

extern "C" void fn_27_A403C(Owner* self) {
    int count = self->unk30->v5();
    for (int i = 0; i < count; i++) {
        Item* item = self->unk30->v3(i);
        if (((u8)item->unk1D >> 6) & 1) {
            int v = ((u8)self->unk45 >> 6) & 1;
            int n = -v | v;
            fn_27_A6DEC((int)item, self->unk48, (int)((unsigned)n >> 31));
        }
    }
    self->unk34->v10();
}
