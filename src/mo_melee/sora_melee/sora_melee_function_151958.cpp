#pragma force_active on
typedef unsigned int u32;

extern const float lbl_27_rodata_1E60;
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, u32 id, u32 index);

class VObj {
public:
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int getState();
};

extern "C" float fn_27_151958(void* unused, void* self) {
    float value = lbl_27_rodata_1E60;
    u32 a = *(u32*)((u32)self + 0xd8);
    VObj* b = *(VObj**)(a + 0x70);
    int state = b->getState();
    if ((u32)(state - 0x11) <= 1) {
        value *= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xc63, 0);
    }
    return value;
}
