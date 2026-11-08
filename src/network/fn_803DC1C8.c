#include <types.h>
#pragma force_active on

extern u8 *PFPATH_GetVolumeFromPath(const char *);
extern void PF_enterCritical(void *);
extern void PF_exitCritical(void *);
extern s32 fn_803E9974(void *);
extern s32 fn_803DBA3C(void *, const char *, void *);
extern char lbl_805644C0[];

s32 fn_803DC1C8(const char *path, void *arg1) {
    u8 *volume;
    s32 result;

    volume = PFPATH_GetVolumeFromPath(path);
    PF_enterCritical(volume + 0x1F90);
    result = fn_803E9974(volume);
    if (result != 0) {
        PF_exitCritical(volume + 0x1F90);
        *(s32 *)(lbl_805644C0 + 0x40) = result;
        *(s32 *)(volume + 0x1F80) = result;
        return result;
    }
    result = fn_803DBA3C(volume, path, arg1);
    if (result != 0) {
        *(s32 *)(lbl_805644C0 + 0x40) = result;
        *(s32 *)(volume + 0x1F80) = result;
    }
    PF_exitCritical(volume + 0x1F90);
    return result;
}