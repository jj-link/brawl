#pragma force_active on
typedef unsigned int u32;

struct Obj;

struct VTable { void (*f[27])(Obj*); };

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

    char pad40[0x110];
    unsigned char a150;
    float a154;
    u32 a158;
    u32 a15c;
};

extern "C" void __ct__10grYakumonoFPCc(Obj*, const char*);
extern const float lbl_52_rodata_B0;
extern VTable lbl_52_data_848;

extern "C" Obj* fn_52_35D0(Obj* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    self->a150 = 0;
    *(VTable**)((char*)self + 0x3c) = &lbl_52_data_848;
    self->a154 = lbl_52_rodata_B0;
    self->a158 = 0;
    self->a15c = 0;
    self->f26();
    return self;
}
