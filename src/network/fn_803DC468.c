#include <revolution/VF/pf_dir.h>
#include <revolution/VF/pf_cache.h>
#include <revolution/VF/pf_path.h>
#pragma force_active on

extern void PF_enterCritical(void *);
extern void PF_exitCritical(void *);
extern int fn_803E9B64(void *);
extern char lbl_805644C0[];

int fn_803DC468(PF_STR *path) {
    u8 *volume;
    int result;

    volume = (u8 *)PFPATH_GetVolumeFromPath(path);
    PF_enterCritical(volume + 0x1F90);
    result = fn_803E9B64(volume);
    if (result != 0) {
        PF_exitCritical(volume + 0x1F90);
        *(int *)(lbl_805644C0 + 0x40) = result;
        *(int *)(volume + 0x1F80) = result;
        return result;
    }
    *(int *)(volume + 0x1644) = 0;
    result = PFDIR_p_mkdir((PF_VOLUME *)volume, path, 0, 0);
    if (result != 0) {
        *(int *)(lbl_805644C0 + 0x40) = result;
        *(int *)(volume + 0x1F80) = result;
    } else {
        result = PFCACHE_FlushFATCache((PF_VOLUME *)volume);
        if (result != 0) {
            *(int *)(lbl_805644C0 + 0x40) = result;
            *(int *)(volume + 0x1F80) = result;
        } else {
            result = PFCACHE_FlushDataCacheSpecific((PF_VOLUME *)volume, 0);
            if (result != 0) {
                *(int *)(lbl_805644C0 + 0x40) = result;
                *(int *)(volume + 0x1F80) = result;
            }
        }
    }
    *(int *)(volume + 0x1644) = 0;
    PF_exitCritical(volume + 0x1F90);
    return result;
}