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
};

struct Anim : AnimBase {
    Flags* data;
    u32 state;
    virtual void set(int, int);
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

    char pad40[0x90];
    Anim anim;
    char padDC[0x74];
    unsigned char a150;
    float a154;
    float a158;
    float a15c;
    float a160;
};

extern "C" void __ct__10grYakumonoFPCc(Obj*, const char*);
extern const float lbl_46_rodata_D0;
extern VTable lbl_46_data_C88;

extern "C" Obj* fn_46_44B4(Obj* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(VTable**)((char*)self + 0x3c) = &lbl_46_data_C88;
    self->a150 = 0;
    self->a154 = lbl_46_rodata_D0;
    self->a158 = lbl_46_rodata_D0;
    self->a15c = lbl_46_rodata_D0;
    self->a160 = lbl_46_rodata_D0;

    Anim* a = &self->anim;
    if (!a)
        return self;

    a->state = 1;
    a->set(0, 15);
    a->data->flags |= 4;
    self->f26();
    return self;
}
