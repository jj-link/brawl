#include <types.h>
#pragma force_active on
extern u8 *PFPATH_GetVolumeFromPath(const char *);
extern void PF_enterCritical(void *);
extern void PF_exitCritical(void *);
extern s32 fn_803E9B64(void *);
extern s32 fn_803E4E14(void *, const char *, s32, s32 *);
extern char lbl_805644C0[];

s32 fn_803E5694(const char *path, s32 mode, s32 *out) {
    u8 *volume;
    s32 result;
    *out = 0;
    volume = PFPATH_GetVolumeFromPath(path);
    PF_enterCritical(volume + 0x1F90);
    result = fn_803E9B64(volume);
    if (result != 0 && (result != 11 || mode != 2)) {
        PF_exitCritical(volume + 0x1F90);
        *(s32 *)(lbl_805644C0 + 0x40) = result;
        *(s32 *)(volume + 0x1F80) = result;
        return result;
    }
    result = fn_803E4E14(volume, path, mode, out);
    if (result != 0) {
        *(s32 *)(lbl_805644C0 + 0x40) = result;
        *(s32 *)(volume + 0x1F80) = result;
    } else {
        *(s32 *)(volume + 0x161C) += 1;
    }
    PF_exitCritical(volume + 0x1F90);
    return result;
}