#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Inner {
    u8 pad[0x40];
    s32 state;
} Inner;

typedef struct Obj {
    u8 pad[8];
    Inner *inner;
} Obj;

extern u32 lbl_8059F980;
extern void *memcpy(void *, const void *, unsigned long);
extern s32 fn_8037442C(void *, void *, s32);

s32 fn_803779DC(Obj *arg0, u32 arg1, u32 arg2)
{
    u8 buf[12];
    u16 hdr;
    s32 len = 0;
    s32 idx;

    if (arg0->inner->state == 2) {
        hdr = 7;
        memcpy(buf, &hdr, 2);
        len = 2;
    }

    memcpy(buf + len, &lbl_8059F980, 2);
    len += 2;
    buf[len++] = 0x65;
    buf[len] = (u8)(arg1 >> 8);
    idx = len + 1;
    len += 2;
    buf[idx] = (u8)arg1;

    if (arg1 != arg2) {
        buf[len] = (u8)(arg2 >> 8);
        idx = len + 1;
        len += 2;
        buf[idx] = (u8)arg2;
    }

    if (fn_8037442C(arg0, buf, len) == 0) {
        return 0;
    }
    return 1;
}
