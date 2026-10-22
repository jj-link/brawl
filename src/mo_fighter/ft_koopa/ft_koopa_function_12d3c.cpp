#pragma force_active on

extern "C" {
void fn_27_12BAF8(void*, int);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
extern const float lbl_102_rodata_3C;
}

struct MainModule {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void fn1C(int, unsigned int);    // 0x1C
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void fn3C(float, unsigned int);  // 0x3C
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void fn50(unsigned int);         // 0x50
    virtual void fn54(unsigned int);         // 0x54
};

struct Module38 {
    int pad0;
    int pad4;
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void fn78(int);  // 0x78
};

struct ModuleB0 {
    int pad0;
    int pad4;
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void fn24(int);  // 0x24
};

struct Mods {
    char pad0[0x38];
    Module38* m38;
    char pad3C[0x64 - 0x3C];
    MainModule* main;
    char pad68[0xB0 - 0x68];
    ModuleB0* mB0;
};

struct Accesser {
    char pad[0xD8];
    Mods* mods;
};

struct Object {
    char pad[0x60];
    Accesser* accesser;
};

extern "C" void fn_102_12D3C(void* arg0, int arg1) {
    Object* obj = (Object*)arg0;
    Accesser* acc = obj->accesser;
    MainModule* main = acc->mods->main;

    main->fn1C(-1, 0x10000041);
    float a = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xFA6, 0);
    main->fn3C(a, 0x11000014);
    float b = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xFA8, 0);
    main->fn3C(b, 0x11000013);
    main->fn54(0x1200003D);
    main->fn54(0x1200003E);
    fn_27_12BAF8(arg0, arg1);
    acc->mods->m38->fn78(1);
    main->fn50(0x12000021);
    main->fn50(0x12000024);
    main->fn50(0x12000025);
    main->fn1C(0, 0x10000040);
    main->fn3C(lbl_102_rodata_3C, 0x11000004);
    acc->mods->mB0->fn24(1);
    main->fn54(0x12000020);
    main->fn54(0x1200002C);
}
