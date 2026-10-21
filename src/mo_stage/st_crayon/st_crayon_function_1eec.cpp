#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_56_F90(void*);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" unsigned char lbl_56_data_AC0[];
extern "C" const float lbl_56_rodata_58;

struct Flags {
    u32 pad;
    u32 flags;
};

struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void call(int, int);

    Flags* data;
    u32 state;
};

struct Obj {
    char pad0[0x3c];
    void* vt;
    char pad40[0x90];
    Sub sub;
    char padDC[0x94];
    unsigned char a170, a171, a172, a173;
    float a174, a178, a17c, a180;
    char gen1[8];
    char gen2[8];
};

extern "C" Obj* fn_56_1EEC(Obj* p) {
    fn_56_F90(p);
    p->vt = lbl_56_data_AC0;
    __ct__14snd3DGeneratorFv(p->gen1);
    __ct__14snd3DGeneratorFv(p->gen2);

    float zero = lbl_56_rodata_58;
    p->a170 = 0;
    p->a171 = 0;
    p->a172 = 0;
    p->a173 = 0;
    p->a174 = zero;
    p->a178 = zero;
    p->a17c = zero;
    p->a180 = zero;

    Sub* s = &p->sub;
    if (!s)
        return p;

    s->state = 1;
    s->call(0, 15);
    s->data->flags |= 2;
    return p;
}
