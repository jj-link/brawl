#pragma force_active on
typedef int s32;
extern void OSReport(const char* fmt, ...);
extern char lbl_80493128[];

s32 fn_803EC394(s32 arg0) {
    if (arg0 == 0) {
        OSReport(lbl_80493128);
        return -2;
    }
    return 0;
}
