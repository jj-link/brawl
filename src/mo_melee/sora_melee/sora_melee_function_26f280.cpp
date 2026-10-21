#include <types.h>
#pragma force_active on

extern "C" void* fn_27_26F240(void* p, s32 n);
extern "C" void* __register_global_object(void* o, void* d, void* c);
extern "C" void* __vt__10soNullable[];
extern "C" u8 lbl_27_data_6E94[];
extern "C" u8 lbl_27_data_57108[];

struct soX { void* p0; u8 p4; void* p8; };
extern soX lbl_27_bss_5FF4;
struct DChain { void* next; void* dtor; void* obj; };
extern DChain lbl_27_bss_5FE8;

extern "C" void fn_27_26F280() {
    soX* o = &lbl_27_bss_5FF4;
    lbl_27_bss_5FF4.p0 = __vt__10soNullable;
    o->p8 = lbl_27_data_6E94;
    lbl_27_bss_5FF4.p0 = lbl_27_data_6E94 + 8;
    o->p4 = 0;
    o->p8 = lbl_27_data_57108;
    lbl_27_bss_5FF4.p0 = lbl_27_data_57108 + 8;
    __register_global_object(o, fn_27_26F240, &lbl_27_bss_5FE8);
}

__declspec(section ".ctors") extern void* const fn_27_26F280_ctor = (void*)fn_27_26F280;
