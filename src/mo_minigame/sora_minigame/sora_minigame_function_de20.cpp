#pragma force_active on
struct Obj {
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
    virtual void v27();
    unsigned char pad0[0x21 - 4];
    unsigned char m21;
    unsigned char pad1[2];
    float m24;
    unsigned char pad2[0x30 - 0x28];
    float m30;
};

extern "C" const float lbl_20_rodata_398;

extern "C" void fn_20_DE20(Obj* p)
{
    float z = lbl_20_rodata_398;
    p->m21 = 0;
    p->m24 = z;
    p->m30 = z;
    p->v25();
}
