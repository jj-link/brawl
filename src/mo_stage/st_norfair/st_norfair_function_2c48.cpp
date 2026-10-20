#pragma force_active on
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" const float lbl_54_rodata_68;
extern "C" unsigned char lbl_54_data_798[];

struct Base {
    unsigned char pad[0x3c];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void setup();
};

struct Object : Base {
    unsigned char pad40[0x110];
    unsigned char unk150;
    unsigned char pad151[3];
    float unk154;
    unsigned int unk158;
};

extern "C" Object* fn_54_2C48(Object* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void**)((char*)self + 0x3c) = lbl_54_data_798;
    self->unk150 = 0;
    self->unk154 = lbl_54_rodata_68;
    self->unk158 = 0;
    self->setup();
    return self;
}
