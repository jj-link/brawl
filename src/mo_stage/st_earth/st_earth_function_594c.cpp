#pragma force_active on
extern "C" void fn_66_2BFC(void*);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" char lbl_66_data_F60[];
extern "C" const float lbl_66_rodata_138;

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
    unsigned char a158, a159, a15a;
    float a15c, a160, a164, a168, a16c, a170, a174, a178, a17c, a180;
    unsigned int a184;
    float a188, a18c, a190;
    unsigned int a194;
    char gen[0x20];
};

extern "C" Obj* fn_66_594C(Obj* p) {
    fn_66_2BFC(p);
    p->vt = lbl_66_data_F60;
    __ct__14snd3DGeneratorFv(p->gen);

    p->a158 = 3;
    p->a159 = 0;
    p->a15a = 0;
    float zero = lbl_66_rodata_138;
    p->a15c = zero;
    p->a160 = zero;
    p->a164 = zero;
    p->a168 = zero;
    p->a16c = zero;
    p->a170 = zero;
    p->a174 = zero;
    p->a178 = zero;
    p->a17c = zero;
    p->a180 = zero;
    p->a184 = 0;
    p->a188 = zero;
    p->a18c = zero;
    p->a190 = zero;
    p->a194 = 0;

    Part* q = &p->part;
    if (!q)
        return p;

    q->state = 1;
    q->call(0, 15);
    q->data->flags |= 0x10;
    return p;
}
