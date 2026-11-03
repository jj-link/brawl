#include <types.h>
#pragma force_active on

struct Value { s32 value; };

extern "C" void fn_802F0438(char *, Value *);
extern "C" char lbl_80488220[0x38];

extern "C" void fn_802E7878(char *arg0) {
    Value value;
    value.value = 1;
    if (arg0 != 0) {
        Value copy = value;
        fn_802F0438(arg0, &copy);
        *(s32 *)(arg0 + 0x58) = 0;
        *(s32 *)(arg0 + 0x5C) = 0;
        *(u32 *)(arg0 + 0x60) = 0x80000000;
        *(s32 *)(arg0 + 0x64) = 0;
        *(s32 *)(arg0 + 0x68) = 0;
        *(u32 *)(arg0 + 0x6C) = 0x80000000;
        *(void **)(arg0 + 0x0) = lbl_80488220;
        *(s32 *)(arg0 + 0x90) = 0;
        *(s32 *)(arg0 + 0x94) = 0;
        *(u32 *)(arg0 + 0x98) = 0x80000000;
    }
}
