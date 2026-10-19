#pragma force_active on
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* self, unsigned long a, unsigned long b);

struct VBase {
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
    virtual unsigned int v19(unsigned long);
};

extern "C" float fn_113_22580(void* self) {
    VBase* obj = *(VBase**)(*(char**)((char*)self + 0xd8) + 0x64);
    if (obj->v19(0x12000003) == 1) {
        return getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xfcb, 0);
    }
    return getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xfc7, 0);
}
