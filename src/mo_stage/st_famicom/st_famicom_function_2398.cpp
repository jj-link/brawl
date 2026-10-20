#pragma force_active on
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" const float lbl_68_rodata_18;
extern "C" unsigned char lbl_68_data_598[];

struct Base {
    unsigned char pad[0x3c];
};

struct Object : Base {
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

extern "C" void* fn_68_2398(void* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void**)((char*)self + 0x3c) = lbl_68_data_598;
    *((unsigned char*)self + 0x150) = 0;
    *(float*)((char*)self + 0x154) = lbl_68_rodata_18;
    ((Object*)self)->setupMelee();
    return self;
}
