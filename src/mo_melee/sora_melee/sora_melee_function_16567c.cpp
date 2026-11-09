#pragma force_active on
struct Accesser;

extern "C" {
float fn_27_1949F0(Accesser*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Accesser*, unsigned long, unsigned long);
void fn_27_1652A8(Accesser*, unsigned long, unsigned long, float, float, unsigned long, unsigned long);
void fn_27_164BF0(Accesser*, const char*, unsigned long, float, unsigned long);
extern const char lbl_27_rodata_2018[];
}

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
    virtual void v40(int);
};

struct Mid {
    char pad[0x60];
    Obj* obj;
};

struct Accesser {
    char pad[0xD8];
    Mid* mid;
};

extern "C" void fn_27_16567C(void* unused, Accesser* accesser) {
    float a = fn_27_1949F0(accesser);
    float e = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xbbb, 0);
    fn_27_1652A8(accesser, 0xc, 0x21000004, e, a, 0x21000005, 0);
    fn_27_164BF0(accesser, lbl_27_rodata_2018, 0x21000004, a, 0x21000005);
    accesser->mid->obj->v40(0);
}
