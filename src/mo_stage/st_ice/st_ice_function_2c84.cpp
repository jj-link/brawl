#pragma force_active on
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" const float lbl_62_rodata_68[];
extern "C" unsigned char lbl_62_data_7D8[];

struct Base {
    unsigned char pad[0x3c];
};

struct Object : Base {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void setup();

    unsigned char rest[0x110];
    unsigned char flag;
    float value;
};

extern "C" Object* fn_62_2C84(Object* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void**)((char*)self + 0x3c) = lbl_62_data_7D8;
    self->flag = 0;
    self->value = lbl_62_rodata_68[0];
    self->setup();
    return self;
}
