#pragma force_active on
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
    virtual float getA(unsigned long);
    virtual void setB(float, unsigned long);
};

struct Inner {
    char pad[0x64];
    VObj* obj;
};

struct Accesser {
    char pad[0xd8];
    Inner* inner;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, unsigned long, unsigned long);

extern "C" int fn_96_151C4(void*, Accesser* self, void* arg) {
    VObj* obj = self->inner->obj;
    float a = obj->getA(0x21000004);
    float b = *(float*)((char*)arg + 4);
    float val = a + b;
    obj->setB(val, 0x21000004);
    float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xfb8, 0);
    return !(val >= c);
}
