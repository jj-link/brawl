#pragma force_active on
extern "C" {
void __ct__10grYakumonoFPCc(void*, const char*);
extern const float lbl_48_rodata_10;
extern unsigned char lbl_48_data_530[];
}

struct Base {
    unsigned char pad0[0x3C];

    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0C();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1C();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2C();
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void f3C();
    virtual void f40();
    virtual void f44();
    virtual void f48();
    virtual void f4C();
    virtual void f50();
    virtual void f54();
    virtual void f58();
    virtual void f5C();
    virtual void f60();
    virtual void f64();
    virtual void setup();
};

struct MarioPast : Base {
    unsigned char pad40[0x110];
    unsigned char unk150;
    unsigned char pad151[3];
    float unk154;
};

extern "C" MarioPast* fn_48_1F28(MarioPast* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void**)((char*)self + 0x3C) = lbl_48_data_530;
    self->unk150 = 0;
    self->unk154 = lbl_48_rodata_10;
    self->setup();
    return self;
}
