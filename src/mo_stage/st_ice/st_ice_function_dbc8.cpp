#pragma force_active on
extern "C" void fn_62_2C84(void*);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" unsigned char lbl_62_data_3CA0[];
extern "C" const float lbl_62_rodata_178;

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
    char paddc[0x7c];
    unsigned int a158, a15c;
    float a160, a164, a168, a16c, a170, a174;
    unsigned int a178;
    unsigned char a17c;
    char pad17d[3];
    unsigned int a180;
    float a184, a188;
    unsigned char a18c, a18d;
    char pad18e[2];
    unsigned int a190, a194, a198, a19c, a1a0;
    char gen[0x20];
};

extern "C" Obj* fn_62_DBC8(Obj* p) {
    fn_62_2C84(p);
    p->vt = lbl_62_data_3CA0;
    __ct__14snd3DGeneratorFv(p->gen);

    p->a158 = 0;
    p->a15c = 0;
    p->a178 = 0;
    float zero = lbl_62_rodata_178;
    p->a160 = zero;
    p->a164 = zero;
    p->a168 = zero;
    p->a16c = zero;
    p->a170 = zero;
    p->a174 = zero;
    p->a17c = 3;
    p->a180 = 0;
    p->a184 = zero;
    p->a188 = zero;
    p->a18c = 0;
    p->a18d = 0;
    p->a190 = 0;
    p->a194 = 0;
    p->a198 = 0;
    p->a19c = 0;
    p->a1a0 = 0;

    Part* q = &p->part;
    if (!q)
        return p;

    q->state = 1;
    q->call(0, 15);
    q->data->flags |= 1;
    q->data->flags |= 2;
    return p;
}
