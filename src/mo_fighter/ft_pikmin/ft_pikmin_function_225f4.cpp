#pragma force_active on
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, unsigned long id, unsigned long idx);

struct VObj {
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
    virtual unsigned long check(unsigned long flag);
};

extern "C" float fn_113_225F4(unsigned char* self) {
    VObj* obj = *(VObj**)(*(unsigned char**)(self + 0xd8) + 0x64);
    if (obj->check(0x12000003) == 1) {
        return getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xfcc, 0);
    }
    return getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xfc8, 0);
}
