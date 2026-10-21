#pragma force_active on

extern const float lbl_27_rodata_63B8;
extern const float lbl_27_rodata_63C0;

struct Vec {
    float x, y, z;
    Vec(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct FacingBase {
    char pad[8];
};

struct Facing : FacingBase {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual float get();
};

struct Flag {
    short value;
    short padding;
    Flag(short v) : value(v) {}
};

struct Posture {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void setA(const Vec*, const Flag*);
    virtual void setB(const Vec*, const Flag*);
};

struct Modules {
    char pad[0x7C];
    Posture* posture;
    char pad80[0x3C];
    Facing* facing;
};

struct Owner {
    char pad[0xD8];
    Modules* modules;
};

struct Self {
    char pad[0x60];
    Owner* owner;
};

extern "C" int fn_27_2E4C80(Self* self) {
    Facing* f = self->owner->modules->facing;
    Vec a(-f->get(), lbl_27_rodata_63B8, lbl_27_rodata_63C0);

    f = self->owner->modules->facing;
    Vec b(-f->get(), lbl_27_rodata_63C0, lbl_27_rodata_63C0);

    Flag first(1);
    Posture* p = self->owner->modules->posture;
    p->setA(&a, &first);

    Flag second(1);
    p = self->owner->modules->posture;
    p->setB(&b, &second);

    return 0;
}
