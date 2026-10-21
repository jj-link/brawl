#include <types.h>
#pragma force_active on

class soSoraObj {
public:
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual void fn3();
    virtual void fn4();
    virtual void fn5();
    virtual void dispatch();
    void* field;
};

extern "C" {
    extern s8 lbl_27_bss_51E8;
    extern soSoraObj lbl_27_bss_51F0;
    extern u8 lbl_27_data_A138[];
    extern u8 lbl_27_data_A108[];
    extern u8 lbl_27_data_A0A0[];
    extern u8 lbl_27_data_A028[];
    extern u8 lbl_27_bss_8BD0[];
    void fn_27_7C3D8(void*, s32);
    void __register_global_object(void*, void*, void*);
}

extern "C" void fn_27_3BAAB0() {
    if (lbl_27_bss_51E8 == 0) {
        *(void**)&lbl_27_bss_51F0 = lbl_27_data_A138;
        lbl_27_bss_51F0.field = lbl_27_data_A108;
        *(void**)&lbl_27_bss_51F0 = lbl_27_data_A0A0;
        lbl_27_bss_51F0.field = lbl_27_data_A0A0 + 0x10;
        *(void**)&lbl_27_bss_51F0 = lbl_27_data_A028;
        lbl_27_bss_51F0.field = lbl_27_data_A028 + 0x10;
        __register_global_object(&lbl_27_bss_51F0, (void*)fn_27_7C3D8, lbl_27_bss_8BD0);
        lbl_27_bss_51E8 = 1;
    }
    soSoraObj* p = &lbl_27_bss_51F0;
    p->dispatch();
}
