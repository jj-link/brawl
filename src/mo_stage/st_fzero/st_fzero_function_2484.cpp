#pragma force_active on
typedef unsigned int u32;

struct Obj;
struct VTable { void (*f[29])(Obj*); };
struct Flags { u32 pad; u32 flags; };

struct AnimBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void set(int, int);
};

struct Anim : AnimBase {
    Flags* data;
    u32 state;
};

struct Base { char pad[0x3c]; };

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
    virtual void f26();
    virtual void f27();
    virtual void f28();

    char pad40[0x90];
    Anim anim;
    char padDC[0x74];
    unsigned char a150;
    float a154;
    u32 a158, a15c, a160;
    unsigned char a164;
    u32 a168, a16c, a170, a174, a178;
    unsigned char a17c;
    float a180;
};

extern "C" void __ct__10grYakumonoFPCc(Obj*, const char*);
extern const float lbl_61_rodata_30;
extern VTable lbl_61_data_1020, lbl_61_data_DF8;

extern "C" Obj* fn_61_2484(Obj* p, const char* name) {
    __ct__10grYakumonoFPCc(p, name);
    *(VTable**)((char*)p + 0x3c) = &lbl_61_data_1020;
    p->a150 = 0;
    p->a154 = lbl_61_rodata_30;
    p->f26();
    p->a158 = 0;
    *(VTable**)((char*)p + 0x3c) = &lbl_61_data_DF8;
    p->a15c = 0;
    p->a160 = 0;
    p->a164 = 0;
    p->a168 = 0;
    p->a16c = 0;
    p->a170 = 0;
    p->a174 = 0;
    p->a178 = 0;
    p->a17c = 7;
    p->a180 = lbl_61_rodata_30;

    Anim* a = &p->anim;
    if (!a)
        return p;

    a->state = 1;
    a->set(0, 15);
    a->data->flags |= 1;
    return p;
}
