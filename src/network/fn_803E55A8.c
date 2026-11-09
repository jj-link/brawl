#include <types.h>
#pragma force_active on

extern u8 *PFPATH_GetVolumeFromPath(const char *);
extern void PF_enterCritical(void *);
extern void PF_exitCritical(void *);
extern s32 fn_803E9B64(void *);
extern s32 PFFILE_p_remove(u8 *, char *);
extern s32 PFCACHE_FlushFATCache(void *);
extern char lbl_805644C0[];

s32 fn_803E55A8(const char *path) {
    u8 *volume;
    s32 result;

    volume = PFPATH_GetVolumeFromPath(path);
    PF_enterCritical(volume + 0x1F90);
    result = fn_803E9B64(volume);
    if (result != 0) {
        PF_exitCritical(volume + 0x1F90);
        *(s32 *)(lbl_805644C0 + 0x40) = result;
        *(s32 *)(volume + 0x1F80) = result;
        return result;
    }
    *(s32 *)(volume + 0x1644) = 0;
    result = PFFILE_p_remove(volume, (char *)path);
    if (result != 0) {
        PF_exitCritical(volume + 0x1F90);
        *(s32 *)(lbl_805644C0 + 0x40) = result;
        *(s32 *)(volume + 0x1F80) = result;
        return result;
    }
    result = PFCACHE_FlushFATCache(volume);
    if (result != 0) {
        *(s32 *)(lbl_805644C0 + 0x40) = result;
        *(s32 *)(volume + 0x1F80) = result;
    }
    PF_exitCritical(volume + 0x1F90);
    return result;
}
