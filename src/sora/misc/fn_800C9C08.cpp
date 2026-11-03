#include <types.h>
#pragma force_active on
extern "C" s32 fn_800C9A4C(u32);
extern "C" s32 fn_800CBCB0(void*, s32*);
extern "C" void fn_800CF22C(void*);
extern s32 gUnk805a03d8;
extern s32 lbl_805A03F0;
extern void* lbl_805A0434;
extern "C" s32 fn_800C9C08(void* arg0, s32* arg1, s32* arg2, u8* arg3) {
    s32 result;
    if (arg2 != 0) *arg2 = 0;
    if (arg1 != 0) *arg1 = 0;
    if (arg3 != 0) *arg3 = *(u8*)((char*)lbl_805A0434 + 0x343c);
    if (gUnk805a03d8 == 0) return 0;
    result = fn_800CBCB0(arg0, arg2);
    if (result != 0) {
        *arg1 = result;
        return 3;
    }
    bool flag = gUnk805a03d8 >= 1 && gUnk805a03d8 < 3;
    if (flag != 0) return 1;
    if (lbl_805A03F0 != 0) {
        if (arg2 != 0) *arg2 = lbl_805A03F0;
        if (arg1 != 0) *arg1 = fn_800C9A4C(*arg2);
        return 3;
    }
    if (arg3 != 0) *arg3 = *(u8*)((char*)lbl_805A0434 + 0x343c);
    *(s32*)((char*)arg0 + 0x40) = 0;
    fn_800CF22C(arg0);
    return 2;
}