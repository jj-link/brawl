#pragma force_active on

extern const float lbl_27_rodata_7BDC;
extern const float lbl_27_rodata_7BE4;

struct Vec {
    float x, y, z;
};

struct PostureData {
    char pad[8];
};

struct Posture : PostureData {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual float get();
};

struct Ground {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void set1(const Vec*, const struct Kind*);
    virtual void set2(const Vec*, const struct Kind*);
};

struct Kind {
    short value;
    short pad;

    Kind(short v) : value(v) {}
};

struct Modules {
    char pad[0x7C];
    Ground* ground;
    char pad80[0x3C];
    Posture* posture;
};

struct Owner {
    char pad[0xD8];
    Modules* modules;
};

struct Self {
    char pad[0x60];
    Owner* owner;
};

extern "C" int fn_27_37620C(Self* self) {
    Posture* p = self->owner->modules->posture;
    Vec first = {
        -p->get(),
        lbl_27_rodata_7BDC,
        lbl_27_rodata_7BE4
    };

    p = self->owner->modules->posture;
    Vec second = {
        -p->get(),
        lbl_27_rodata_7BE4,
        lbl_27_rodata_7BE4
    };

    Kind one(1);
    Ground* g = self->owner->modules->ground;
    g->set1(&first, &one);

    Kind two(1);
    g = self->owner->modules->ground;
    g->set2(&second, &two);

    return 0;
}
