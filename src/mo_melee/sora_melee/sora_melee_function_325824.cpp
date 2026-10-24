#include <types.h>
#pragma force_active on

extern "C" {
    extern s8 lbl_27_bss_51E8;
    extern u8 lbl_27_bss_51F0[];
    extern u8 lbl_27_bss_7C68[];
    extern u8 lbl_27_data_35248[];
    extern u8 lbl_27_data_383B8[];
    extern u8 lbl_27_data_A028[];
    extern u8 lbl_27_data_A0A0[];
    extern u8 lbl_27_data_A108[];
    extern u8 lbl_27_data_A138[];

    void* fn_27_CDCC4(void*);
    void fn_27_CDA70(void*, s32);
    void fn_27_7C3D8(void*, s32);
    void __construct_array(void*, void*, void*, u32, s32);
    void __register_global_object(void*, void*, void*);
    void fn_27_92F10(void*, s32, void*, void*, void*);
    void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, s32, s32);
}

struct Flags18 {
    u32 pad0 : 4;
    u32 mode : 2;
    u32 bit6 : 1;
    u32 rest : 25;
};

extern "C" void* fn_27_325824(void* arg0, s32 arg1) {
    u32* self = (u32*)arg0;
    Flags18* f = (Flags18*)&self[6];

    self[0] = (u32)lbl_27_data_35248;
    self[1] = (u32)(lbl_27_data_35248 + 0x48);
    self[2] &= 0x01FFFFFF;
    self[4] = (u32)lbl_27_data_383B8;
    self[5] = (u32)(lbl_27_data_383B8 + 0x48);
    f->pad0 = 0;
    f->mode = 1;
    f->bit6 = 0;

    __construct_array((u8*)arg0 + 0x1C, (void*)fn_27_CDCC4,
                      (void*)fn_27_CDA70, 0x10, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        (u8*)arg0 + 0x14, 1, 1);

    if (lbl_27_bss_51E8 == 0) {
        *(void**)lbl_27_bss_51F0 = lbl_27_data_A138;
        *(void**)(lbl_27_bss_51F0 + 4) = lbl_27_data_A108;
        *(void**)lbl_27_bss_51F0 = lbl_27_data_A0A0;
        *(void**)(lbl_27_bss_51F0 + 4) = lbl_27_data_A0A0 + 0x10;
        *(void**)lbl_27_bss_51F0 = lbl_27_data_A028;
        *(void**)(lbl_27_bss_51F0 + 4) = lbl_27_data_A028 + 0x10;
        __register_global_object(lbl_27_bss_51F0, (void*)fn_27_7C3D8,
                                 lbl_27_bss_7C68);
        lbl_27_bss_51E8 = 1;
    }

    fn_27_92F10((u8*)arg0 + 0x30, arg1, arg0,
                lbl_27_bss_51F0, (u8*)arg0 + 0x10);
    return arg0;
}
