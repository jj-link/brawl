#include <types.h>
#pragma force_active on

extern "C" void fn_802FEA54(void*, void*, s32);

extern "C" void fn_802AFF44(void* arg0, s32 arg1, s32* arg2, s32 arg3) {
    if (*(s8*)((u8*)arg0 + 0x78) == 0) {
        s32 arr[5];
        arr[0] = arg1;
        s32 v = *arg2;
        arr[1] = (s32)arg2;
        arr[3] = arg3;
        arr[4] = *(s32*)((u8*)arg0 + 8);
        arr[2] = v;
        fn_802FEA54((u8*)arg0 + 0x30, arr, arr[4]);
    }
}
