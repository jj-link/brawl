#include <revolution/VF/pf_entry.h>
#include <revolution/VF/pf_sector.h>
#include <revolution/VF/pf_cache.h>
#pragma force_active on

extern u8 lbl_805A4AF0;
extern int fn_803DF04C(PF_ENT_ITER*, int);

int PFENT_RemoveEntry(PF_DIR_ENT* entry, PF_ENT_ITER* iter)
{
    int written;
    u8 marker = lbl_805A4AF0;
    unsigned int i;
    PF_VOLUME* volume = (PF_VOLUME*)entry->cache;
    int result;

    if (((u8*)entry)[0x20a] != 0 && !(((u8*)entry)[0x21b] & 0x18)) {
        for (i = 1; i <= ((u8*)entry)[0x20a]; i++) {
            result = fn_803DF04C(iter, 0);
            if (result != 0) return result;
            result = PFSEC_WriteData(volume, &marker, *(int*)((u8*)iter + 0x44), *(u16*)((u8*)iter + 0x48), 1, &written, 0);
            if (result != 0) return result;
            if ((unsigned int)written != 1) return 0x11;
        }
    }
    result = PFSEC_WriteData(volume, &marker, entry->sector, *(u16*)((u8*)entry + 0x23c), 1, &written, 0);
    if (result != 0) return result;
    if ((unsigned int)written != 1) return 0x11;
    result = PFCACHE_FlushDataCacheSpecific(volume, 0);
    return result & ((-result | result) >> 31);
}