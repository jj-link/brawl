#pragma force_active on
extern float lbl_41_rodata_E80;

struct Params {
    float x, y, z, w;
};

struct Object {
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
    virtual void call(void*, Params*, void*, int);
};

extern "C" bool fn_41_34F38(Object* self, void* arg2, Params* params, void* arg4) {
    if (lbl_41_rodata_E80 == params->w && params->z <= lbl_41_rodata_E80) {
        return false;
    }
    self->call(arg2, params, arg4, -1);
    return true;
}
