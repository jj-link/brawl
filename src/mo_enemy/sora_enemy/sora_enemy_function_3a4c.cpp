#pragma force_active on
typedef int s32;

struct Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual float getFloat(s32 id);
};

struct Mid {
    char pad[0x64];
    Obj* unk64;
};

struct Owner {
    char pad[0x1B4];
    Mid* unk1B4;
};

extern "C" float fn_41_3A4C(Owner* p) {
    Obj* o = p->unk1B4->unk64;
    float a = o->getFloat(0x11000001);
    float b = o->getFloat(0x1100000E);
    return a - b;
}
