#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_15DB0[];
void __dl__FPv(void*);
void fn_27_7773C(void*);
}

struct Sub {
    virtual void f0();
    virtual void* f3(s32);
    virtual void f4();
    virtual s32 f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
};

struct Tab {
    virtual void f0();
    virtual void** f3(s32);
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12(void*);
};

struct Obj {
    void* vtbl;
    void* m4;
    void* m8;
    Sub* mC;
    s32 m10;
};

extern "C" Obj* fn_27_AB18C(Obj* arg0, s32 arg1) {
    if (arg0 != nullptr) {
        u32 pad[2];
        u32 loc[28];
        s32 i;

        loc[0] = (u32)lbl_27_data_15DB0;
        loc[1] = (u32)(lbl_27_data_15DB0 + 0x48);
        loc[2] &= 0x1FFF;

        for (i = 0; i < arg0->mC->f5(); i++) {
            pad[0] = (u32)arg0->mC->f3(i);
            ((Tab*)loc)->f12(pad);
        }

        for (i = 0; i < (((s32)(loc[2] << 12) & (s32)0xFE000000) >> 26); i++) {
            if (*((Tab*)loc)->f3(i) != nullptr) {
                fn_27_7773C(*((Tab*)loc)->f3(i));
            }
        }

        arg0->mC->f10();
        arg0->m10 = -1;
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
