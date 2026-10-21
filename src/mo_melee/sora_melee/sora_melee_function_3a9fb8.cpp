#pragma force_active on

extern const float lbl_27_rodata_7EF0;
extern const float lbl_27_rodata_7EF8;

struct ID {
    short value;
    short pad;
};

struct Vec {
    float x, y, z;
};

struct Getter {
    char pad[8];
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

struct Setter {
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
    virtual void setA(const Vec&, const ID&);
    virtual void setB(const Vec&, const ID&);
};

struct Modules {
    char pad[0x7C];
    Setter* setter;
    char pad80[0x3C];
    Getter* getter;
};

struct Inner {
    char pad[0xD8];
    Modules* modules;
};

struct Self {
    char pad[0x60];
    Inner* inner;
};

extern "C" int fn_27_3A9FB8(Self* self) {
    Vec a = {
        -self->inner->modules->getter->get(),
        lbl_27_rodata_7EF0,
        lbl_27_rodata_7EF8
    };
    Vec b = {
        -self->inner->modules->getter->get(),
        lbl_27_rodata_7EF8,
        lbl_27_rodata_7EF8
    };

    ID idA;
    idA.value = 1;
    self->inner->modules->setter->setA(a, idA);

    ID idB;
    idB.value = 1;
    self->inner->modules->setter->setB(b, idB);

    return 0;
}
