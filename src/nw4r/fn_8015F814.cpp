#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual int slot1();
};

struct MainObj {
    char pad0_24[0x24];
    float f24;
    char pad28_48[0x20];
    Object_vptr_0* ptr48;
};

extern "C" float fn_8015F814(MainObj* self) {
    return self->f24 * (float)self->ptr48->slot1();
}
