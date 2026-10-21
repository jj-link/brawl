struct IA {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(unsigned long);
};

struct IB {
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
    virtual int v16();
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* self, unsigned long id, unsigned long index);
extern "C" void fn_100_D210(void* self);

#pragma force_active on
extern "C" void fn_100_D14C(void* unused, char* self) {
    IA* a = *(IA**)(*(char**)(self + 0xD8) + 0x64);
    int r31 = a->v4(0x20000000);
    IB* b = *(IB**)(*(char**)(self + 0xD8) + 0x70);
    int r3 = b->v16();
    switch (r3) {
    case 0x113:
        if (r31 == 2) {
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xFA8, 0);
            fn_100_D210(self);
        }
        break;
    case 0x118:
        if (r31 == 2) {
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xFA9, 0);
            fn_100_D210(self);
        }
        break;
    }
}
