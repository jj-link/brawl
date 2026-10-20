#pragma force_active on
struct Base {
    unsigned char pad0[0x3C];
};

struct Dispatch : Base {
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
    virtual void setupMelee();
};

struct Kart : Dispatch {
    unsigned char pad40[0x110];
    unsigned char unk150;
    unsigned char pad151[3];
    float unk154;
};

extern "C" void __ct__10grYakumonoFPCc(Kart*, const char*);
extern "C" const float lbl_49_rodata_50[];
extern "C" unsigned char lbl_49_data_690[];

extern "C" Kart* fn_49_13B0(Kart* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void**)((unsigned char*)self + 0x3C) = lbl_49_data_690;
    self->unk150 = 0;
    self->unk154 = lbl_49_rodata_50[0];
    self->setupMelee();
    return self;
}
