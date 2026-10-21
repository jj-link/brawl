#pragma force_active on

extern "C" void fn_62_2C84(void*);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" unsigned char lbl_62_data_5888[];
extern "C" const float lbl_62_rodata_1F0;

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
    unsigned int a158, a15c, a160;
    float a164, a168, a16c, a170, a174, a178, a17c, a180, a184;
    unsigned char a188, a189, a18a;
    char pad18b;
    float a18c, a190;
    char gen[0x20];
};

extern "C" Obj* fn_62_10100(Obj* p) {
    fn_62_2C84(p);
    p->vt = lbl_62_data_5888;
    __ct__14snd3DGeneratorFv(p->gen);

    p->a158 = 0;
    p->a15c = 0;
    p->a160 = 0;
    float zero = lbl_62_rodata_1F0;
    p->a164 = zero;
    p->a168 = zero;
    p->a16c = zero;
    p->a170 = zero;
    p->a174 = zero;
    p->a178 = zero;
    p->a17c = zero;
    p->a180 = zero;
    p->a184 = zero;
    p->a188 = 0;
    p->a189 = 0;
    p->a18a = 5;
    p->a18c = zero;
    p->a190 = zero;

    Part* q = &p->part;
    if (!q)
        return p;

    q->state = 1;
    q->call(0, 15);
    q->data->flags |= 1;
    q->data->flags |= 2;
    return p;
}
