#pragma force_active on

struct Flags {
    unsigned int pad;
    unsigned int flags;
};

struct Part {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void call(int, int);
    Flags* data;
    unsigned int state;
};

struct Obj {
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    Part part;
    char paddc[0x7c];
    unsigned int a158;
    unsigned int a15c;
    unsigned int a160;
    unsigned char a164;
    char pad165[3];
    float a168;
    unsigned char a16c;
    unsigned char a16d;
    char pad16e[2];
    unsigned int a170;
    char gen[8];
    int a17c;
    int a180;
};

extern "C" void fn_61_2320(Obj*);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" char lbl_61_data_25A0[];
extern "C" const float lbl_61_rodata_118;

extern "C" Obj* fn_61_7018(Obj* p) {
    fn_61_2320(p);
    p->vtable = lbl_61_data_25A0;
    __ct__14snd3DGeneratorFv(p->gen);

    p->a158 = 0;
    p->a15c = 0;
    p->a160 = 0;
    p->a164 = 2;
    p->a168 = lbl_61_rodata_118;
    p->a16c = 0;
    p->a16d = 0;
    p->a170 = 0;

    Part* q = &p->part;
    if (!q)
        return p;

    q->state = 1;
    q->call(0, 15);
    q->data->flags |= 8;
    p->a17c = -1;
    p->a180 = -1;
    return p;
}
