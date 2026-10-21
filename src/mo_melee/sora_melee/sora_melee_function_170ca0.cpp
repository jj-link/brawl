#pragma force_active on

extern "C" unsigned int fn_27_170720(int);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
extern float lbl_27_rodata_2230;

struct A {
    int a;
    int b;
};

struct Inner : A {
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
    virtual void v38(int);
};

struct Obj64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, unsigned long);
};

struct Obj0C {
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
    virtual void v15(float*, int);
};

struct Mid {
    char pad[0xC];
    Obj0C* unk0C;
    Inner* unk10;
    char pad14[0x50];
    Obj64* unk64;
};

struct Arg1 {
    char pad[0xD8];
    Mid* mid;
};

extern "C" void fn_27_170CA0(void* unused, Arg1* arg1, int arg2) {
    float sp[3];
    if (fn_27_170720(arg2) == 1) {
        arg1->mid->unk10->v38(0);
        int val = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(arg1, 0x5a0a, 0);
        arg1->mid->unk64->v5(val, 0x10000002);
    }
    sp[0] = lbl_27_rodata_2230;
    sp[1] = lbl_27_rodata_2230;
    sp[2] = lbl_27_rodata_2230;
    arg1->mid->unk0C->v15(sp, 0);
}
