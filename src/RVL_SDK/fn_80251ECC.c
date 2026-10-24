#pragma force_active on
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern void fn_8024A764(void*, u8, s16, s32, s32);
extern void fn_80252784(void*, s16, s16*);
extern void* fn_80256160(void*, s32);
extern unsigned char lbl_8052D5A8[];

void fn_80251ECC(void* arg0, s16 arg1, s16 arg2, u8 arg3) {
    u8 sp8;
    void* result;

    sp8 = arg3;
    result = fn_80256160(arg0, 0);
    *(void**)((char*)lbl_8052D5A8 + 0x3c + (arg1 - 0x40) * 4) = result;
    if (result == 0) {
        fn_8024A764(arg0, sp8, arg1, 4, 0);
        return;
    }
    *(s16*)((char*)result + 0x68) = arg1;
    fn_80252784(result, 0xa, (s16*)&sp8);
}
