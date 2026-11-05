#pragma force_active on
extern "C" void fn_54_2C48(void*);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" unsigned char lbl_54_data_1390[];
extern "C" const float lbl_54_rodata_80;
extern "C" const float lbl_54_rodata_84;

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
    char padDc[0x80];
    unsigned int a15c, a160, a164, a168;
    float a16c;
    unsigned char a170;
    char pad171[3];
    float a174;
    unsigned char a178;
    char pad179[3];
    unsigned int a17c, a180, a184, a188, a18c;
    char gen[0x20];
};

extern "C" Obj* fn_54_3828(Obj* p) {
    fn_54_2C48(p);
    p->vt = lbl_54_data_1390;
    __ct__14snd3DGeneratorFv(p->gen);

    p->a15c = 0;
    p->a160 = 0;
    p->a164 = 0;
    p->a168 = 0;
    p->a16c = lbl_54_rodata_80;
    p->a170 = 3;
    p->a174 = lbl_54_rodata_84;
    p->a178 = 0;
    p->a17c = 0;
    p->a180 = 0;
    p->a184 = 0;
    p->a188 = 0;
    p->a18c = 0;

    Part* q = &p->part;
    if (!q) {
        return p;
    }
    q->state = 1;
    q->call(0, 15);
    q->data->flags |= 1;
    q->data->flags |= 4;
    return p;
}
