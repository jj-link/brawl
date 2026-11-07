#include <types.h>
#pragma force_active on
extern "C" {
void fn_8027C808(void*, void*, void*, u32, u32, u32, u32, u32, u32, u32, u32);
extern u8 lbl_80412CA8[];
extern u8 lbl_80532340[];
extern u8 lbl_80532FA8[];
}
extern "C" void fn_802E2038() {
    fn_8027C808(lbl_80532FA8, lbl_80412CA8, lbl_80532340, 8, 0, 0, 0, 0, 0, 0, 0);
}

__declspec(section ".ctors") extern void* const fn_802E2038_ctor = (void*)fn_802E2038;
