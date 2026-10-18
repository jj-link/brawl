#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct VBase {
    virtual ~VBase();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(u32 a, u32 b);
};

extern "C" void* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(void* self, u32 a, u32 b);

extern "C" void fn_27_18A0BC(void* unused, void* p) {
    u32* v = (u32*)getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(p, 0x10000 - 0x57F2, 0);
    u8* obj = *(u8**)((u8*)p + 0xd8);
    VBase* sub = *(VBase**)(obj + 0x64);
    sub->f4(*v, 0x20000001);
}
