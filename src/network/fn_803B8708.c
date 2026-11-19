#include <types.h>
#pragma force_active on

typedef struct {
    u16 unk0;
    char pad2[0xA];
    u32 unkC;
    char pad10[8];
    u16 unk18;
    char pad1A[6];
    u8 unk20;
    char pad21;
    u8 unk22;
    char pad23[5];
    u32 unk28;
    char pad2c[8];
    s32 unk34;
    char pad38[0x15C8];
    u32 unk1600;
    char pad1604[0x26C];
    void *unk1870;
    char pad1874[0x1C];
    s32 (*unk1890)(void *);
} Ctx;

typedef struct {
    char pad0[2];
    u16 unk2;
    u8 *unk4;
    u8 *unk8;
    char padC[0xC];
    u32 unk18;
} Buf;

extern s32 fn_803AFEDC(Ctx *, u32, Buf **);
extern s32 fn_803B6F80(Ctx *, Buf *);

s32 fn_803B8708(Ctx *c, u32 idx, u32 *out, Buf **bp) {
    Buf *p;
    u32 a, cnt;
    s32 r;
    u32 m;
    u32 lo;

    if (c == 0) {
        return 0xA;
    }
    if ((idx < 2 || idx >= (u32)(c->unk34 + 2)) && idx != 0 && idx != 1) {
        return 0xE;
    }
    m = (u16)(idx + ((idx >> 1) & 0x7FFF));
    a = (u16)(c->unk28 + (m >> c->unk20));
    cnt = 1;
    if (c->unk18 & 0x80) {
        cnt = c->unk18 & 7;
    }
    r = 0;
    while (1) {
        if (r == 0x1000 && c->unk1890 != 0) {
            s32 t = c->unk1890(c->unk1870);
            if (t == 0) {
                r = 0;
                continue;
            }
            if (t == 1 && c->unk22 >= 2 && cnt < c->unk22) {
                r = 0;
                cnt++;
                a += c->unkC;
                continue;
            }
            goto done;
        }
        p = *bp;
        if (p->unk18 > a || p->unk18 + c->unk1600 <= a) {
            if (p->unk2 == 1) {
                r = fn_803B6F80(c, p);
                if (r != 0) return r;
            }
            r = fn_803AFEDC(c, a, bp);
            if (r != 0) continue;
        } else {
            if (a != p->unk18 + ((p->unk8 - p->unk4) >> c->unk20)) {
                p->unk8 = p->unk8 + c->unk0;
            }
        }
        break;
    }
    lo = m & (c->unk0 - 1);
    if (lo == c->unk0 - 1) {
        *out = (*bp)->unk8[lo];
        p = *bp;
        if (p->unk18 > a + 1 || p->unk18 + c->unk1600 <= a + 1) {
            if (p->unk2 == 1) {
                r = fn_803B6F80(c, p);
                if (r != 0) return r;
            }
            r = fn_803AFEDC(c, a + 1, bp);
            if (r != 0) return r;
        } else if (a + 1 != p->unk18 + ((p->unk8 - p->unk4) >> c->unk20)) {
            p->unk8 = p->unk8 + c->unk0;
        }
        *out += (*bp)->unk8[0] << 8;
    } else {
        *out = (((*bp)->unk8 + lo)[1] << 8) + (*bp)->unk8[lo];
    }
done:
    if (r != 0) {
        *out = -1;
        return r;
    }
    if (idx & 1) {
        *out = *out >> 4;
    } else {
        *out &= 0xFFF;
    }
    return 0;
}