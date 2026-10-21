#pragma force_active on
extern "C" void fn_62_2C84(void*);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" unsigned char lbl_62_data_22B8[];
extern "C" const float lbl_62_rodata_D8;
extern "C" const float lbl_62_rodata_DC;

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
    unsigned int a158;
    float a15c, a160, a164, a168, a16c, a170, a174, a178, a17c;
    char gen[0x20];
};

extern "C" Obj* fn_62_8588(Obj* p) {
    fn_62_2C84(p);
    p->vt = lbl_62_data_22B8;
    __ct__14snd3DGeneratorFv(p->gen);

    p->a158 = 0;
    p->a15c = lbl_62_rodata_D8;
    p->a160 = lbl_62_rodata_D8;
    p->a164 = lbl_62_rodata_D8;
    p->a168 = lbl_62_rodata_D8;
    p->a16c = lbl_62_rodata_D8;
    p->a170 = lbl_62_rodata_DC;
    p->a174 = lbl_62_rodata_D8;
    p->a178 = lbl_62_rodata_D8;
    p->a17c = lbl_62_rodata_DC;

    Part* q = &p->part;
    if (!q)
        return p;

    q->state = 1;
    q->call(0, 15);
    q->data->flags |= 8;
    return p;
}
