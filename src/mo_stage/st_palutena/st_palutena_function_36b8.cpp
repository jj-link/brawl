#pragma force_active on
extern "C" const float lbl_67_rodata_10;

struct Parameters {
    float scale;
    char pad[12];
    float threshold1;
    float threshold2;
    float threshold3;
};

struct ObjectBase {
    char pad0[0x3C];

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
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual Parameters* getParameters();
};

struct Object : ObjectBase {
    char pad1[0x11C];
    float* value;
};

extern "C" unsigned char fn_67_36B8(Object* self) {
    Parameters* params = self->getParameters();
    if (!params)
        return 0;

    float value = *self->value;
    if (value <= lbl_67_rodata_10)
        return 4;
    if (value <= params->scale * params->threshold3)
        return 3;
    if (value <= params->scale * params->threshold2)
        return 2;

    return value <= params->scale * params->threshold1 ? 1 : 0;
}
