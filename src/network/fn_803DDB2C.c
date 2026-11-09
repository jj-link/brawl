#include <types.h>
#include <revolution/VF/pf_sector.h>
#pragma force_active on

extern void fn_803E75D0(u8 *, void *, u8);

typedef struct DirEnt {
    u8 name[11];
    u8 attr;
    u8 ntres;
    u8 ctenth;
    u16 ctime;
    u16 cdate;
    u16 adate;
    u16 clusHi;
    u16 mtime;
    u16 mdate;
    u16 clusLo;
    u32 size;
} DirEnt;

#define SWAP16(v) ((u16)((((u16)(v) & 0xFF) << 8) | (((u16)(v) >> 8) & 0xFF)))

s32 fn_803DDB2C(u8 *obj, u32 arg1)
{
    void *cache;
    DirEnt ent;
    int written;
    u32 value;
    s32 result;

    cache = *(void **)(obj + 0x22C);
    if (*(u32 *)(obj + 0x234) == 1)
        return 0xE;

    if (arg1 == 1)
        obj[0x21C] |= 0x20;

    fn_803E75D0(ent.name, obj + 0x20E, obj[0x21C]);
    if (ent.name[0] == 0xE5)
        ent.name[0] = 5;

    ent.attr = obj[0x21C];
    ent.ntres = obj[0x21B];
    ent.ctenth = obj[0x21D];

    ent.ctime = SWAP16(*(u16 *)(obj + 0x21E));
    ent.cdate = SWAP16(*(u16 *)(obj + 0x220));
    ent.adate = SWAP16(*(u16 *)(obj + 0x222));
    ent.mtime = SWAP16(*(u16 *)(obj + 0x224));
    ent.mdate = SWAP16(*(u16 *)(obj + 0x226));
    ent.clusHi = SWAP16(*(u32 *)(obj + 0x234) >> 16);
    ent.clusLo = SWAP16(*(u32 *)(obj + 0x234));
    value = *(u32 *)(obj + 0x228);
    ent.size = ((value << 24) | ((value & 0xFF00) << 8)) |
               ((value >> 24) | ((value >> 8) & 0xFF00));

    result = PFSEC_WriteData(cache, &ent, *(s32 *)(obj + 0x238),
                             *(u16 *)(obj + 0x23C), 0x20, &written, 0);
    if (result != 0)
        return result;

    return written != 0x20 ? 0x11 : 0;
}
