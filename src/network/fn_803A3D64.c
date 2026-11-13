#include <types.h>
#pragma force_active on

typedef struct Entry {
    u16 index;
    u16 pad02;
    u32 flags;
    u32 address;
    u32 title_hi;
    u32 title_lo;
    u16 id;
    u8 pad16[6];
    u16 value;
} Entry;

typedef struct Context {
    u8 pad00[0x10];
    u16 unk10;
    u16 limit;
    u16 count;
} Context;

extern int fn_8039832C(void *, int, int);
extern int fn_80398680(void *);
extern int fn_80398818(void *, int, int);
extern int fn_80398BD8(void *, int, void *);
extern int fn_803A230C(s64 *);
extern int fn_803A5284(void *, u16, u16);
extern s64 fn_803F1470(s64, s64);
extern int lbl_8059FDE8;
extern unsigned char *lbl_805A1170;

int fn_803A3D64(Entry *arg0) {
    unsigned char ctx[0xA0];
    s64 time;
    s64 end;
    unsigned char *base;
    Context *cp;
    Context *context;
    int result;
    int check;
    u16 index;
    u16 limit;
    u16 count;
    u32 v;

    context = (lbl_805A1170 != 0) ? (Context *)(lbl_805A1170 + 0x3600) : 0;
    if (context->count == 0) {
        if (context->unk10 != 0) {
            context->count = context->unk10;
            if (context->unk10 > 0x20) {
                context->unk10 = 0x20;
            }
            if (fn_8039832C(ctx, lbl_8059FDE8, 4) >= 0) {
                if (fn_80398818(ctx, 0, 0) >= 0) {
                    fn_80398BD8((lbl_805A1170 != 0) ? (lbl_805A1170 + 0x3600) : 0, 0x800, ctx);
                }
                fn_80398680(ctx);
            }
        }
    }
    if (context->count < 1U || context->limit < 1U || context->count < context->limit) {
        result = -0xe;
    } else {
        result = 0;
    }
    if (result < 0) {
        return result;
    }
    base = lbl_805A1170;
    limit = ((base != 0) ? (Context *)(base + 0x3600) : 0)->limit;
    count = ((base != 0) ? (Context *)(base + 0x3600) : 0)->count;
    result = fn_803A5284(arg0, limit, count);
    if (result >= 0) {
        time = 0;
        result = fn_803A230C(&time);
        if (result < 0) {
            return result;
        }
        base = lbl_805A1170;
        end = time + arg0->value * 60;
        cp = (base != 0) ? (Context *)(base + 0x3600) : 0;
        if (arg0 == 0) {
            check = -3;
        } else if (cp == 0) {
            check = -9;
        } else if (arg0->index != 0xFFFF && arg0->index >= cp->count) {
            check = -3;
        } else {
            check = 0;
        }
        switch (check) {
        case 0:
            index = arg0->index;
            if (index == 0xFFFF) {
                check = -2;
            } else {
                v = (u32)fn_803F1470(end, 60);
                cp = (base != 0) ? (Context *)(base + 0x3600) : 0;
                *(u32 *)((u8 *)cp + index * 16 + 0x84) = v;
                check = 0;
            }
            break;
        }
        result = check;
        return result;
    }
    return result;
}