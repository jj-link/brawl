#pragma force_active on

extern "C" void __ct__15grGimmickSpringFPCc(void*, const char*);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" unsigned char lbl_63_data_6290[];
extern "C" const float lbl_63_rodata_220;

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

struct Base {
    char pad[0x3c];
};

struct Obj : Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void setupMelee();

    char pad40[0x90];
    Part part;
    char padDC[0xc0];
    int a19c;
    unsigned char a1a0;
    char pad1a1[3];
    int a1a4;
    unsigned char a1a8;
    char pad1a9[3];
    int a1ac;
    unsigned char a1b0;
    unsigned char a1b1;
    char pad1b2[2];
    float a1b4;
    float a1b8;
    float a1bc;
    char gen[0x20];
};

extern "C" Obj* fn_63_16368(Obj* p, const char* name) {
    __ct__15grGimmickSpringFPCc(p, name);
    *(unsigned char**)((char*)p + 0x3c) = lbl_63_data_6290;
    __ct__14snd3DGeneratorFv(p->gen);

    p->a19c = 0;
    p->a1a0 = 4;
    p->a1a4 = 0;
    p->a1a8 = 1;
    p->a1ac = 0;
    p->a1b0 = 0;
    p->a1b1 = 0;
    float zero = lbl_63_rodata_220;
    p->a1b4 = zero;
    p->a1b8 = zero;
    p->a1bc = zero;

    Part* q = &p->part;
    if (!q)
        return p;

    q->state = 1;
    q->call(0, 15);
    q->data->flags |= 4;
    q->data->flags |= 1;
    p->setupMelee();
    return p;
}
