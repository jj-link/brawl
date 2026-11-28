#include <types.h>
#pragma force_active on

extern "C" {
extern s32 lbl_85_rodata_80[4][2];
extern u32 lbl_85_rodata_A0[2][4];
}

static inline u32 checkBit(const u32 *bits, u32 x, u32 y, u32 w, u32 h)
{
    u32 r = 0;
    if (x >= w || y >= h) {
        r = 2;
    } else if ((1 << x) & bits[y]) {
        r = 1;
    }
    return r;
}

static inline bool getTile(char *p, u32 x, u32 y, u32 *out)
{
    if (x >= *(u32 *)(p + 0x2b4) || y >= *(u32 *)(p + 0x2b8))
        return false;
    u8 tile = *(u8 *)(p + x * 14 + y + 0x3f4);
    if (tile >= *(u32 *)(p + 0x2c0))
        return false;
    *out = *(u32 *)(p + tile * 0x18 + 0x4f4);
    return true;
}

static inline u32 getMask(const u32 *pcur, u32 x, u32 y)
{
    const u32 &cur = *pcur;
    if (!((cur >> 10) & 3)) {
    s32 k = (cur >> 6) & 0xF;
    switch (k) {
    case 1:
    case 3:
        return 0xC;
    case 4:
    case 5:
        return 0;
    }
    u32 a;
    s32 px;
    s32 py;
    s32 w;
    s32 h;
    s32 flip;
    s32 dy;
    s32 dx;
    a = cur >> 24;
    w = (cur >> 21) & 7;
    h = (cur >> 18) & 7;
    px = a % 18;
    py = a / 18;
    if (!((cur >> 18) & 1) && ((cur & 7) == 2 || (cur & 7) == 5))
        py++;
    flip = (cur >> 5) & 1;
    dx = x - (px - w / 2);
    dy = y - (py - h / 2);
    if (flip)
        dx = (w - 1) - dx;
    switch (k) {
    case 2: {
        u32 m = 0xF;
        if (dx == 0)
            m &= ~(4 << flip);
        if (dx == w - 1)
            m &= ~(2U >> flip);
        return m;
    }
    case 6:
    case 9:
        if (dx == w - 1)
            return 2 >> flip;
        break;
    case 7:
        if (dx > dy)
            return 0xF;
        if (dx == dy)
            return 2 >> flip;
        break;
    }
    }
    return 0;
}

extern "C" s32 fn_85_8F0(char *arg0, s32 flags, u32 *arg2, u32 *bits, u32 bw, u32 bh)
{
    u32 v = *arg2;
    u32 a = v >> 24;
    s32 w = (v >> 21) & 7;
    s32 h = (v >> 18) & 7;
    s32 x = a % 18;
    s32 y = a / 18;
    s32 xr;
    u32 cur;
    int i;

    if (!((v >> 18) & 1) && ((v & 7) == 2 || (v & 7) == 5))
        y++;
    x -= w / 2;
    y -= h / 2;

    for (i = 0; i < 4; i++) {
        u32 tx = x + lbl_85_rodata_80[i][0];
        u32 ty = y + lbl_85_rodata_80[i][1];
        if (checkBit(bits, tx, ty, bw, bh) == 1) {
            if (getTile(arg0, tx, ty, &cur)) {
                u32 need = lbl_85_rodata_A0[0][i];
                if (need == (need & getMask(&cur, tx, ty)))
                    continue;
            }
            flags |= 0x100;
            break;
        }
    }

    xr = x + w;
    for (i = 0; i < 4; i++) {
        u32 tx = (x + w - 1) - lbl_85_rodata_80[i][0];
        u32 ty = y + lbl_85_rodata_80[i][1];
        if (checkBit(bits, tx, ty, bw, bh) == 1) {
            if (getTile(arg0, tx, ty, &cur)) {
                u32 need = lbl_85_rodata_A0[1][i];
                if (need == (need & getMask(&cur, tx, ty)))
                    continue;
            }
            flags |= 0x200;
            break;
        }
    }

    if (!(flags & 0x100)) {
        if (checkBit((u32 *)(arg0 + 0x34c), x - 1, y, bw, bh) == 1)
            flags |= 0x100;
    }
    if (!(flags & 0x200)) {
        if (checkBit((u32 *)(arg0 + 0x34c), xr, y, bw, bh) == 1)
            flags |= 0x200;
    }
    return flags;
}
