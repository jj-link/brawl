#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

struct Pair { s32 a; s32 b; };
struct Blob { Pair p[10]; };
extern const Blob lbl_80406F98;
struct Table { Blob b; s32 pad; };

inline s32 testRange(s32 r9, s32 r4) {
    s32 result = 1;
    for (s32 i = r9; i <= r4; i++) {
        s32 k = i - 1;
        s32 sh = (k * 2) % 32;
        void* base = g_GameGlobal->m_record;
        u32 word = *(u32*)((u8*)base + ((k * 2) / 32) * 4 + 0x15AC);
        if (!((1 << sh) & word)) {
            result = 0;
            break;
        }
    }
    return result;
}

extern "C" s32 fn_800596EC(s32 arg0) {
    Table t;
    s32 r9 = 0;
    s32 r4 = 0;
    t.b = lbl_80406F98;
    switch (arg0) {
    case 0x30: r9 = t.b.p[0].a; r4 = t.b.p[0].b; break;
    case 0x33: r9 = t.b.p[1].a; r4 = t.b.p[1].b; break;
    case 0x35: r9 = t.b.p[2].a; r4 = t.b.p[2].b; break;
    case 0x37: r9 = t.b.p[3].a; r4 = t.b.p[3].b; break;
    case 0x32: r9 = t.b.p[4].a; r4 = t.b.p[4].b; break;
    case 0x36: r9 = t.b.p[5].a; r4 = t.b.p[5].b; break;
    case 0x38: r9 = t.b.p[6].a; r4 = t.b.p[6].b; break;
    case 0x34: r9 = t.b.p[7].a; r4 = t.b.p[7].b; break;
    case 0x39: r9 = t.b.p[8].a; r4 = t.b.p[8].b; break;
    case 0x2F: r9 = t.b.p[9].a; r4 = t.b.p[9].b; break;
    case 0x6B: r9 = 1; r4 = 0x1A5; break;
    default: r4 = 0; r9 = 0; break;
    }
    if (r9 == 0) return 0;
    return testRange(r9, r4);
}