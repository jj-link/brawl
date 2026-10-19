#pragma force_active on
struct Module {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6(unsigned long id);
    virtual void v7();
    virtual void v8();
    virtual void v9(unsigned long arg);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual int v19(unsigned long id);
    virtual void v20(unsigned long id);
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
    virtual void v35(unsigned long arg);
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
    virtual void v48();
    virtual void v49();
    virtual void v50(int a, int b, int c, int d, float x, float y, float z);
};

struct Modules {
    char pad0[0x58];
    Module* m58;
    Module* m5c;
    char pad1[0x4];
    Module* work;
    char pad2[0x20];
    Module* m88;
};

struct soModuleAccesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
void fn_27_89DAC(int, soModuleAccesser*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
}

extern "C" void fn_27_184668(void*, soModuleAccesser* accesser) {
    float a, b, c;

    fn_27_89DAC(3, accesser);
    fn_27_89DAC(1, accesser);
    fn_27_89DAC(2, accesser);
    fn_27_89DAC(4, accesser);
    accesser->modules->m58->v9(0);
    accesser->modules->m88->v35(0);
    if (accesser->modules->work->v6(0x20000001) == 0x20 ||
        accesser->modules->work->v19(0x22000013) != 0) {
        a = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xd53, 0);
        b = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xd52, 0);
        c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xd51, 0);
    } else if (accesser->modules->work->v6(0x20000001) == 5) {
        a = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xd3c, 0);
        b = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xd3b, 0);
        c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xd3a, 0);
    }
    accesser->modules->m5c->v50(0, -1, 0, 0, a, b, c);
    accesser->modules->work->v20(0x12000001);
    accesser->modules->work->v20(0x12000029);
}
