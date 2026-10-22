#pragma force_active on

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void PF_enterCritical(void *p);
extern void PF_exitCritical(void *p);
extern s32 fn_803D620C(s8 arg0);
extern char lbl_805644C0[];

void *fn_803EA100(s8 arg0) {
    s16 idx;

    idx = (s16)(fn_803D620C(arg0) - 0x41);
    PF_enterCritical(lbl_805644C0 + 0x64);
    if (idx < 0 || idx >= 0x1A) {
        PF_exitCritical(lbl_805644C0 + 0x64);
        return 0;
    }
    PF_exitCritical(lbl_805644C0 + 0x64);
    return lbl_805644C0 + idx * 0x1FC8 + 0xA0;
}
