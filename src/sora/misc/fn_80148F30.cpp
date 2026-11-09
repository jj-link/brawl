#include <types.h>
#pragma force_active on

extern "C" {
extern int g_NtMatchingStatus;
extern int g_NtAIDBitmap;
extern int lbl_805A03E0;
extern int lbl_805A03FC;
extern int lbl_805A0400;
extern int lbl_805A0404;
extern unsigned char lbl_805A0409;
extern unsigned char lbl_805A0410;
extern unsigned char lbl_805A0414;
extern unsigned char lbl_805A0418[8];
extern unsigned char lbl_8059E742;
extern unsigned char lbl_8059E743;
extern unsigned char lbl_8059E744;
extern unsigned char lbl_8059E745;
extern void* lbl_805A0434;
extern char lbl_8045FF54[];

u64 memset(void* s, int c, unsigned long n);
void netReport__FPCce(const char* fmt, ...);
void fn_80146FCC(int);
}

extern "C" s32 fn_80148F30(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u64 temp_ret;
    if (g_NtMatchingStatus != 5) {
        return 0;
    }
    lbl_805A03FC = arg1;
    lbl_805A0404 = arg2;
    lbl_805A0400 = arg3;
    *(char*)((char*)lbl_805A0434 + 0x33F4) = 0;
    *(char*)((char*)lbl_805A0434 + 0x33F5) = 0;
    *(char*)((char*)lbl_805A0434 + 0x33F6) = 0;
    *(int*)((char*)lbl_805A0434 + 0x34A4) = 0;
    *(char*)((char*)lbl_805A0434 + 0x34AA) = 0;
    *(char*)((char*)lbl_805A0434 + 0x34AB) = 0;
    *(int*)((char*)arg0 + 0x3428) = 0;
    *(int*)((char*)arg0 + 0x342C) = 0;
    lbl_805A0409 = 0x1E;
    g_NtMatchingStatus = 5;
    lbl_805A03E0 = 5;
    *(char*)((char*)arg0 + 0x33CE) = 0;
    *(char*)((char*)arg0 + 0x33F5) = 0;
    *(char*)((char*)arg0 + 0x33F6) = 0;
    *(int*)((char*)arg0 + 0x3404) = 0;
    temp_ret = memset((void*)&lbl_805A0410, 0, 4);
    g_NtAIDBitmap = 0;
    lbl_805A0414 = 0;
    lbl_8059E742 = 0xFF;
    lbl_8059E745 = 0xFF;
    lbl_8059E743 = 0xFF;
    lbl_8059E744 = 0xFF;
    lbl_805A0418[0] = 0;
    lbl_805A0418[1] = 0;
    lbl_805A0418[2] = 0;
    lbl_805A0418[3] = 0;
    lbl_805A0418[4] = 0;
    lbl_805A0418[5] = 0;
    lbl_805A0418[6] = 0;
    lbl_805A0418[7] = 0;
    if (*(int*)((char*)arg0 + 0x34A4) != 0) {
        *(int*)((char*)arg0 + 0x34A4) = 0;
        netReport__FPCce(lbl_8045FF54, (u32)temp_ret);
    }
    *(int*)((char*)arg0 + 0x3430) = 0;
    fn_80146FCC(6);
    return 1;
}
