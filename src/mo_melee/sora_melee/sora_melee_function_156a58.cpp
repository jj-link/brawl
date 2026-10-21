#include <types.h>
#pragma force_active on

extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, u32 id, u32 flag);
extern "C" extern const s32 lbl_27_rodata_1F30[3][2];

class VObj {
public:
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
    virtual u32 v17(u32 x);
};

extern "C" {
int fn_27_156A58(void* self, long defaultValue, void* mod) {
    void* p1 = *(void**)((char*)mod + 0xd8);
    VObj* p2 = *(VObj**)((char*)p1 + 0x64);
    if (p2->v17(0x12000012) == 1) {
        s32 idx = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(mod, 0x59e8, 0);
        if (idx != -1) {
            return lbl_27_rodata_1F30[idx][1];
        }
    }
    return defaultValue;
}
}
