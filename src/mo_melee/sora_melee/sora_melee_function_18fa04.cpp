#pragma force_active on

extern const float lbl_27_rodata_2638;
extern const float lbl_27_rodata_263C;

struct VB {
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
};

struct B {
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
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48(int, int, int, int, float, float, float);
};

struct Sub {
    char pad0[0x5C];
    B* p5C;
    char pad1[0x10];
    VB* p70;
};

struct Self {
    char pad0[0xd8];
    Sub* sub;
};

extern "C" void fn_27_18FA04(int, Self* self) {
    if (self->sub->p70->v16() == 0xfa) {
        self->sub->p5C->v48(0, -1, 0, 0,
            lbl_27_rodata_2638, lbl_27_rodata_263C, lbl_27_rodata_263C);
    }
}
