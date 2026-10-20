#include <types.h>
#pragma force_active on

extern float lbl_27_rodata_3C0;

struct Obj {
    virtual void f0();
    virtual Obj* get();
    char pad[0x2C];
    float value;
};

struct Self {
    char pad[0x28];
    Obj* obj;
    char pad2[0x24];
    u8 flag;
};

extern "C" float fn_27_297CC(Self* self) {
    if (((self->flag >> 3) & 1) == 0) {
        return self->obj->get()->value;
    }
    return lbl_27_rodata_3C0;
}
