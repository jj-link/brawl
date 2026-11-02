#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_15DB0[];
void fn_27_7773C(void*);
}

class soNullable {
public:
    virtual void isNull();
    virtual void* slot1(s32);
    virtual void slot2();
    virtual s32 slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
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
    soNullable* mC;
    s32 m10;
};

extern "C" void fn_27_ABE4C(Obj* arg0) {
    u32 pad[2];
    u32 loc[28];
    s32 i;

    loc[0] = (u32)lbl_27_data_15DB0;
    loc[1] = (u32)(lbl_27_data_15DB0 + 0x48);
    loc[2] &= 0x1FFF;

    for (i = 0; i < arg0->mC->slot3(); i++) {
        pad[0] = (u32)arg0->mC->slot1(i);
        ((Tab*)loc)->f12(pad);
    }

    for (i = 0; i < (((s32)(loc[2] << 12) & (s32)0xFE000000) >> 26); i++) {
        if (*((Tab*)loc)->f3(i) != nullptr) {
            fn_27_7773C(*((Tab*)loc)->f3(i));
        }
    }

    arg0->mC->slot8();
    arg0->m10 = -1;
}
