#include <types.h>
#pragma force_active on

extern u8 lbl_804F7820[];
extern char lbl_8047C828[];
extern char lbl_8047C840[];
extern s32 fn_8021FA20(s32 arg0, void* arg1);
extern void fn_8022550C(void* p, ...);

void fn_80219DF8(u32 arg0, void* arg1) {
    u8 value = lbl_804F7820[arg0];
    if (value <= 4U) {
        s32 result = fn_8021FA20((s32)value, arg1);
        if (result != 0) {
            fn_8022550C(lbl_8047C828, result);
        }
    } else {
        fn_8022550C(lbl_8047C840, (s32)value);
    }
}