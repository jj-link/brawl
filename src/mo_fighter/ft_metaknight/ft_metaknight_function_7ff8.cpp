#include <types.h>
#pragma force_active on

extern "C" {
extern u32 lbl_111_bss_1B4;
void fn_111_D548(void* a, void* b);
void fn_27_135468(void* a, void* b);
}

struct FnIface {
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual s32 v18() = 0;
};

extern "C" void fn_111_7FF8(void* self, void* arg) {
    u8* s = static_cast<u8*>(self);
    FnIface* obj = *(FnIface**)(*(u8**)(*(u8**)(s + 0x60) + 0xD8) + 0x70);
    s32 r = obj->v18();
    if (r == 0x116) {
        fn_111_D548(&lbl_111_bss_1B4, *(void**)(s + 0x60));
    }
    fn_27_135468(self, arg);
}
