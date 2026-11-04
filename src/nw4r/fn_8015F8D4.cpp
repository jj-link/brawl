#pragma force_active on

class VObj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual int m3();
};

struct MainObj {
    char pad0_28[0x28];
    float f28;
    char pad2c_48[0x1C];
    VObj* ptr48;
};

extern "C" float fn_8015F8D4(MainObj* self) {
    return self->f28 * (float)self->ptr48->m3();
}