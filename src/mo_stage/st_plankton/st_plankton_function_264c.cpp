#pragma force_active on
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" const float lbl_74_rodata_90;
extern "C" unsigned char lbl_74_data_8B0[];

struct Prefix {
    unsigned char pad[0x3c];
};

struct Object : Prefix {
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
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
    virtual void setup();

    unsigned char pad1[0x110];
    unsigned char unk150;
    unsigned char pad2[3];
    float unk154;
};

extern "C" Object* fn_74_264C(Object* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void**)((char*)self + 0x3c) = lbl_74_data_8B0;
    self->unk150 = 0;
    self->unk154 = lbl_74_rodata_90;
    self->setup();
    return self;
}
