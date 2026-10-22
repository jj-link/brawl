#pragma force_active on

struct Args {
    int unk0;
    float unk4;
    float unk8;
    char unkC[4];
};

struct Module {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(float);
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
    virtual void v30(Args*);
};

struct Inner {
    char pad[8];
    Module* module;
};

struct Outer {
    char pad[0xd8];
    Inner* inner;
};

struct Target {
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3(void*);
};

extern "C" const float lbl_110_rodata_18;
extern "C" const float lbl_110_rodata_1C;
extern "C" void fn_110_D084(Target*, Outer*);

extern "C" void fn_110_D90C(Target* self, Outer* outer) {
    const float* c = &lbl_110_rodata_18;
    Module* mod = outer->inner->module;
    Args a;
    a.unk0 = 0x1e7;
    a.unk4 = *c;
    a.unk8 = lbl_110_rodata_1C;
    a.unkC[0] = 0;
    a.unkC[1] = 0;
    a.unkC[2] = 0;
    a.unkC[3] = 0;
    mod->v30(&a);
    mod->v7(*c);
    fn_110_D084(self, outer);
    self->t3(outer);
}
