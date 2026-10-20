#pragma force_active on
extern "C" int fn_27_68140(float, float, float, float, float);
extern "C" const float lbl_27_rodata_2738[];

struct Target {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void call(int, int);
};

struct Inner {
    unsigned char padding[0x44];
    Target* target;
};

struct Modules {
    unsigned char padding[0xd8];
    Inner* inner;
};

struct Object {
    unsigned char padding[0x60];
    Modules* modules;
};

extern "C" void fn_27_1DB174(Object* self, int value, float a, float b) {
    int result = fn_27_68140(
        a,
        lbl_27_rodata_2738[18],
        lbl_27_rodata_2738[22],
        b,
        lbl_27_rodata_2738[24]
    );
    Target* target = self->modules->inner->target;
    target->call(result, value);
}
