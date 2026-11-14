#include <types.h>
#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSTime.h>
#include <mt/mt_prng.h>
#include <string.h>
#pragma force_active on

struct NtMutexes {
    OSMutex m0;
    OSMutex m1;
    OSMutex m2;
    OSMutex m3;
};

extern NtMutexes lbl_8049EC30;
extern OSCond lbl_805A03C8;
extern signed char lbl_805A03D0;
extern s32 lbl_805A03D4;
extern unsigned char lbl_805A0418[8];
extern s32 gUnk805a03d8;
extern s32 g_NtMatchingStatus;
extern s32 lbl_805A03E0;
extern unsigned char lbl_805A03E4;
extern s32 lbl_805A03FC;
extern s32 lbl_805A0400;
extern s32 lbl_805A0404;
extern unsigned char lbl_805A0408;
extern unsigned char lbl_805A0409;
extern unsigned char lbl_805A0410[4];
extern unsigned char lbl_805A0414;
extern unsigned char lbl_805A0415;
extern unsigned char lbl_8059E742;
extern unsigned char lbl_8059E743;
extern unsigned char lbl_8059E744;
extern unsigned char lbl_8059E745;
extern s32 g_NtAIDBitmap;
extern s32 lbl_805A03E8;
extern s32 lbl_805A03EC;
extern s32 lbl_805A03F0;
extern s32 lbl_805A03F4;
extern s32 lbl_805A0428;
extern mtRand lbl_805A0420;

extern "C" {
void init__6mtRandFl(mtRand*, u32);
}

#pragma push
#pragma opt_propagation off
extern "C" void fn_80146E44(void) {
    NtMutexes* base = &lbl_8049EC30;
    OSMutex NtMutexes::*first = &NtMutexes::m0;
    lbl_805A03D0 = 0;
    OSInitMutex(&base->m3);
    OSInitCond(&lbl_805A03C8);
    OSInitMutex(&(base->*first));
    OSInitMutex(&base->m1);
    lbl_805A03D4 = 0;
    gUnk805a03d8 = 0;
    g_NtMatchingStatus = 0;
    lbl_805A03E0 = 0;
    lbl_805A03E4 = 0;
    lbl_805A03FC = 0;
    lbl_805A0400 = -1;
    lbl_805A0404 = 0;
    lbl_805A0408 = 0;
    lbl_805A0409 = 0x1E;
    memset(lbl_805A0418, 0, 8);
    lbl_805A0414 = 0;
    lbl_8059E742 = 0xFF;
    lbl_8059E743 = 0xFF;
    lbl_8059E744 = 0xFF;
    lbl_8059E745 = 0xFF;
    lbl_805A0415 = 0;
    memset(lbl_805A0410, 0, 4);
    g_NtAIDBitmap = 0;
    lbl_805A03E8 = 0;
    lbl_805A03EC = 0;
    lbl_805A03F0 = 0;
    lbl_805A03F4 = 0;
    lbl_805A0428 = 0;
    init__6mtRandFl(&lbl_805A0420, OSGetTick());
}
#pragma pop
