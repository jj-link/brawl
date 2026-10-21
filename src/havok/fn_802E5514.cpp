#pragma force_active on
#include <types.h>

struct fn_805330F8_struct {
    void* field0;
    void* field4;
    void* field8;
    s32 fieldC;
};

extern "C" void fn_802E5258(void* arg0);
extern "C" void fn_802E5278(void* p);
extern "C" s32 fn_802E52F0(void);
extern char lbl_80413130[];
extern fn_805330F8_struct lbl_805330F8;

extern "C" void fn_802E5514(void) {
    s32 r = fn_802E52F0();
    lbl_805330F8.field0 = &lbl_80413130;
    lbl_805330F8.field4 = fn_802E5258;
    lbl_805330F8.field8 = fn_802E5278;
    lbl_805330F8.fieldC = r;
}

__declspec(section ".ctors") extern void* const fn_802E5514_ctor = (void*)fn_802E5514;
