#include <types.h>
#include <string.h>
#pragma force_active on

typedef struct Attribute {
    u32 length;
    u8 *data;
    u16 id;
    u8 type;
} Attribute;

typedef struct Range {
    u16 lo;
    u16 hi;
} Range;

typedef struct RangeList {
    u16 count;
    Range r[16];
} RangeList;

typedef struct ItemList {
    u16 count;
    u8 items[288];
} ItemList;

extern void *fn_8022EFF8(s32);
extern void fn_802319E4(s32, void *);
extern void fn_8024ABC4(u16, void *);
extern void fn_8025B344(u8 *, u16, s32, s32);
extern u8 *fn_8025B480(u8 *, u32, ItemList *);
extern u8 *fn_8025B7D0(u8 *, u32, RangeList *);
extern u8 *fn_80257724(u8 *, ItemList *);
extern Attribute *fn_80257994(u8 *, u32, u32);
extern u8 *fn_8025B1F0(u8 *, Attribute *);
extern u8 lbl_8052D9C0[];
extern u8 lbl_80485164[];

void fn_8025AAC8(u8 *self, u16 arg1, u32 arg2, u8 *arg3)
{
    ItemList l90;
    RangeList l4C;
    RangeList l08;
    u8 *hdr;
    RangeList *rec;
    u8 *wp;
    u16 len;
    u8 *cur;
    u8 *base;
    u16 i;
    u8 *table;
    Attribute *attr;
    u8 *packet;
    s32 overflow;
    u8 *start;
    u8 *p;
    u16 m;
    u16 rem;
    u16 innerLength;
    s32 t;
    s32 n;

    overflow = 0;
    p = fn_8025B480(arg3, arg2, &l90);
    if (p == 0 || l90.count == 0) {
        fn_8025B344(self, arg1, 3, 0);
        return;
    }
    len = (u16)((p[0] << 8) + p[1]);
    t = *(u16 *)(self + 0x20) - 10;
    if ((s32)len > t) {
        len = (u16)t;
    }
    p = fn_8025B7D0(p + 2, arg2, &l4C);
    if (p == 0 || l4C.count == 0) {
        fn_8025B344(self, arg1, 3, 0);
        return;
    }
    l08 = l4C;
    if (p[0] != 0) {
        if (p[0] != 2) {
            fn_8025B344(self, arg1, 5, 0);
            return;
        }
        m = (u16)((p[1] << 8) + p[2]);
        if (m != *(u16 *)(self + 0x476)) {
            fn_8025B344(self, arg1, 5, 0);
            return;
        }
    } else {
        *(u16 *)(self + 0x476) = 0;
        cur = self + 0x29;
        table = fn_80257724(0, &l90);
        while (table != 0) {
            l4C = l08;
            start = cur;
            i = 0;
            cur += 3;
            while (i < l4C.count) {
                rec = (RangeList *)((u8 *)&l4C + (u32)i * 4);
                attr = fn_80257994(table, rec->r[0].lo, rec->r[0].hi);
                if (attr != 0) {
                    if (attr->length > (u32)((u16)(0x3E8 - (u16)(cur - (self + 0x26))) - 6)) {
                        overflow = 1;
                        break;
                    }
                    cur = fn_8025B1F0(cur, attr);
                    if (rec->r[0].lo != rec->r[0].hi) {
                        i--;
                        rec->r[0].lo = (u16)(attr->id + 1);
                    }
                }
                i++;
            }
            if (overflow != 0) {
                break;
            }
            innerLength = (u16)((cur - start) - 3);
            if (innerLength != 0) {
                start[0] = 0x36;
                start[1] = (u8)(innerLength >> 8);
                start[2] = (u8)innerLength;
            } else {
                cur = start;
            }
            table = fn_80257724(table, &l90);
        }
        m = (u16)(cur - (self + 0x26));
        *(u16 *)(self + 0x24) = m;
        if (m > 0xFF) {
            self[0x26] = 0x36;
            self[0x27] = (u8)((*(u16 *)(self + 0x24) - 3) >> 8);
            self[0x28] = (u8)(*(u16 *)(self + 0x24) - 3);
        } else {
            *(u16 *)(self + 0x476) = 1;
            self[0x27] = 0x35;
            self[0x28] = (u8)(m - 3);
            *(u16 *)(self + 0x24) = (u16)(m - 1);
        }
    }

    packet = fn_8022EFF8(2);
    if (packet == 0) {
        if (lbl_8052D9C0[0x4630] >= 1) {
            fn_802319E4(0xA0000, lbl_80485164);
        }
        return;
    }
    base = packet + 0x11;
    *(u16 *)(packet + 4) = 9;
    base[0] = 7;
    base[1] = (u8)(arg1 >> 8);
    base[2] = (u8)arg1;
    wp = base + 3;
    hdr = wp;
    if (*(u16 *)(self + 0x24) <= len) {
        len = *(u16 *)(self + 0x24);
    }
    wp[2] = (u8)(len >> 8);
    wp[3] = (u8)len;
    wp += 4;
    memcpy(wp, self + *(u16 *)(self + 0x476) + 0x26, len);
    wp += len;
    rem = *(u16 *)(self + 0x476);
    *(u16 *)(self + 0x24) -= len;
    *(u16 *)(self + 0x476) = rem + len;
    if (*(u16 *)(self + 0x24) != 0) {
        wp[0] = 2;
        wp[1] = (u8)(*(u16 *)(self + 0x476) >> 8);
        wp[2] = (u8)*(u16 *)(self + 0x476);
        wp += 3;
    } else {
        wp[0] = 0;
        wp += 1;
    }
    n = (wp - hdr) - 2;
    hdr[0] = (u8)((u16)n >> 8);
    hdr[1] = (u8)n;
    *(u16 *)(packet + 2) = (u16)(wp - base);
    fn_8024ABC4(*(u16 *)(self + 0x22), packet);
}
