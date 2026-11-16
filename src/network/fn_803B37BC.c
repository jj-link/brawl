#include <types.h>
#pragma force_active on

extern s32 fn_803BE78C(u8 *, const u8 *, s32);
extern s32 fn_803C0440(void *, void *, s32, u16, s32, s32 *, s32);

#define SWAP16(v) ((u16)((((u16)(v) & 0xFF) << 8) | (((u16)(v) >> 8) & 0xFF)))

typedef struct Ent {
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
} Ent;

s32 fn_803B37BC(u8 *arg0, u32 arg1)
{
    u32 pos;
    u32 size;
    u32 value;
    u32 written;
    u8 *vol;
    Ent ent;
    s32 result;

    if (arg0 == NULL)
        return 0xA;

    vol = (u8 *)*(u32 *)(arg0 + 0x22C);
    if (vol == NULL)
        return 0xA;

    pos = *(u32 *)(arg0 + 0x238);
    if (pos < ((u32)*(u32 *)(vol + 0x30) - (u32)*(u16 *)(vol + 0x24)))
        return 0x1C;
    size = *(u32 *)(vol + 0x8);
    if (pos >= size)
        return 0x10;

    if (*(u32 *)(arg0 + 0x234) == 1)
        return 0xE;

    if (arg1 == 1)
        arg0[0x21C] |= 0x20;

    fn_803BE78C(ent.name, arg0 + 0x20E, arg0[0x21C]);
    if (ent.name[0] == 0xE5)
        ent.name[0] = 5;

    ent.attr = arg0[0x21C];
    ent.ntres = arg0[0x21B];
    ent.ctenth = arg0[0x21D];

    ent.ctime = SWAP16(*(u16 *)(arg0 + 0x21E));
    ent.cdate = SWAP16(*(u16 *)(arg0 + 0x220));
    ent.adate = SWAP16(*(u16 *)(arg0 + 0x222));
    ent.mtime = SWAP16(*(u16 *)(arg0 + 0x224));
    ent.mdate = SWAP16(*(u16 *)(arg0 + 0x226));
    ent.clusHi = SWAP16(*(u32 *)(arg0 + 0x234) >> 16);
    ent.clusLo = SWAP16(*(u32 *)(arg0 + 0x234));
    value = *(u32 *)(arg0 + 0x228);
    ent.size = ((value << 24) | ((value & 0xFF00) << 8)) |
               ((value >> 24) | ((value >> 8) & 0xFF00));

    result = fn_803C0440((void *)vol, &ent, *(s32 *)(arg0 + 0x238),
                         *(u16 *)(arg0 + 0x23C), 0x20, (s32 *)&written, 0);
    if (result != 0)
        return result;

    return (s32)((((s32)written - 0x20) | (0x20 - (s32)written)) >> 0x1F) & 0x11;
}
