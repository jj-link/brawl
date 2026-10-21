#pragma force_active on

struct LocalParam {
    int value;
    signed char flag;
};

struct FirstModule {
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
    virtual void set(int, LocalParam*, int);
};

struct SecondModule {
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
    virtual void set(int);
};

struct ThirdModule {
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
    virtual void set(int, int, int);
};

struct Modules {
    char pad0[0x20];
    ThirdModule* third;
    char pad24[0x1C];
    SecondModule* second;
    char pad44[0x10];
    FirstModule* first;
};

struct Fighter {
    char pad[0xD8];
    Modules* modules;
};

extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    Fighter*, unsigned long, unsigned long);

extern "C" void fn_92_FDCC(void* unused, Fighter* self)
{
    LocalParam param;
    param.value = 0x1B;
    param.flag = 0;

    self->modules->first->set(0, &param, 0);
    self->modules->second->set(1);

    ThirdModule* third = self->modules->third;
    int value = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
        self, 0x5A2E, 0);
    third->set(value, 0, 0);
}
