#pragma force_active on
extern "C" {
void __ct__10grYakumonoFPCc(void*, const char*);
extern unsigned char lbl_73_data_E40[];
extern const float lbl_73_rodata_48[];
}

struct Base {
    unsigned char pad0[0x3C];
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
    virtual void v26();

    unsigned char pad1[0x110];
    unsigned char state;
    unsigned char pad2[3];
    float frame;
};

extern "C" Object* fn_73_2C64(Object* p, const char* name) {
    __ct__10grYakumonoFPCc(p, name);
    *(void**)((char*)p + 0x3C) = (void*)lbl_73_data_E40;
    p->state = 0;
    p->frame = lbl_73_rodata_48[0];
    p->v26();
    return p;
}
