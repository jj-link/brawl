#pragma force_active on
extern "C" void fn_62_2C84(void*);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" unsigned char lbl_62_data_3328[];
extern "C" const float lbl_62_rodata_168;

struct Flags {
    unsigned int pad;
    unsigned int flags;
};

struct Part {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void call(int, int);

    Flags* data;
    unsigned int state;
};

struct Obj {
    char pad0[0x3c];
    void* vt;
    char pad40[0x90];
    Part part;
    char pad[0x7c];
    unsigned int a158, a15c;
    float a160, a164, a168, a16c, a170, a174;
    unsigned int a178;
    char pad17c[4];
    float a180;
    unsigned int a184;
    char gen[0x20];
};

extern "C" Obj* fn_62_D3B0(Obj* p) {
    fn_62_2C84(p);
    p->vt = lbl_62_data_3328;
    __ct__14snd3DGeneratorFv(p->gen);

    p->a158 = 0;
    p->a15c = 0;
    float zero = lbl_62_rodata_168;
    p->a160 = zero;
    p->a164 = zero;
    p->a168 = zero;
    p->a16c = zero;
    p->a170 = zero;
    p->a174 = zero;
    p->a178 = 0;
    p->a180 = zero;
    p->a184 = 0;

    Part* q = &p->part;
    if (!q)
        return p;

    q->state = 1;
    q->call(0, 15);
    q->data->flags |= 1;
    return p;
}
