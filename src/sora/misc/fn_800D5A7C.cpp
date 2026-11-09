#pragma force_active on
#include <types.h>
extern "C" u8 fn_800C851C();
extern "C" int fn_800C8524();
extern "C" u8 fn_800C8548();
extern "C" void fn_80146878(void*, int);
extern "C" void netReport__FPCce(const char*, ...);
extern char g_Network[];
extern char lbl_80457158[];
struct FccWord { u32 top : 8; u32 rest : 24; };
struct Entry { char pad[0x218]; };
struct Parent { char pad[0x70]; Entry entries[5]; };
static inline s32 getId(char* ent) {
    u32 w = *(u32*)(ent + 0x78);
    return (s32)((w << 24) | ((w >> 8) & 0x800000)) >> 24;
}
extern "C" void fn_800D5A7C(char* self) {
    char* base = lbl_80457158;
    char* ent;
    u8 idx;
    u8 local;
    u8 raw;
    s32 st;
    if ((*(s32*)(self + 0xFCC) >> 24) != 1) return;
    if (fn_800C8524() != 0) return;
    idx = fn_800C8548();
    if (idx == 0xFF) ent = 0;
    else ent = (char*)&((Parent*)self)->entries[idx];
    if (ent == 0) return;
    if (!((ent[0x210] >> 7) & 1)) return;
    s32 id = getId(ent);
    if (id != *(s32*)(self + 0x6C)) {
        netReport__FPCce(base + 0x1BE0);
        netReport__FPCce(base + 0x1C24, getId(ent), *(s32*)(self + 0x6C));
        fn_80146878(g_Network, 1);
        return;
    }
    local = fn_800C851C();
    if (local == 0xFF) local = 4;
    idx = fn_800C8548();
    if (idx == 0xFF) {
        u8 alt = fn_800C851C();
        if (alt == 0xFF) alt = 4;
        ent = self + alt * 0x218 + 0x70;
    } else {
        ent = (char*)&((Parent*)self)->entries[idx];
        if (!(((u8)ent[0x78] >> 7) & 1)) {
            u8 alt = fn_800C851C();
            if (alt == 0xFF) alt = 4;
            ent = self + alt * 0x218 + 0x70;
        }
    }
    raw = (ent + local)[0x68];
    st = raw;
    if (st == 1) {
        ((FccWord*)(self + 0xFCC))->top = 4;
        netReport__FPCce(base + 0x1D88, st);
        return;
    }
    if (st == 4) {
        netReport__FPCce(base + 0x1DC0, st);
        fn_80146878(g_Network, 1);
        return;
    }
    netReport__FPCce(base + 0x1DF8, st);
}