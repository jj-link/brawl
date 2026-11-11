#include <types.h>
#include <string.h>
#pragma force_active on

struct Obj {
    char pad[0x20];
    s32 unk20;
    char pad24[8];
    s32 unk2C;
    char pad30[0x10];
    s32 unk40;
    s32 unk44;
};

struct Res {
    s32 unk0;
    u16 unk4;
    u8 pad6[2];
    struct Obj *unk8;
    s32 unkC;
    char pad10[0x8C];
    s32 unk9C;
};

extern s16 lbl_8059F980;
extern struct Res *fn_80377D90(struct Obj *, s32, u16);
extern s32 fn_80373FDC(struct Obj *, struct Res *, s32, u16, s32, u8 *, s32, s32);
extern s32 fn_803740D8(struct Obj *, s32, u16, u8 *, s32, s32 *);
extern s32 fn_803741F8(struct Obj *, struct Res **, s32, u16);
extern s32 fn_803783C4(struct Obj *, s32, u16, u8 *, s32);
extern s32 fn_803F6150(const void *, const void *, u32);
extern s32 fn_8035A590(s32);
extern s32 fn_80373ED4(struct Res *, s32, u8 *, s32, s32);
extern s32 fn_80373B7C(struct Res *, u8 *, s32, s32);
extern s32 fn_80375D18(struct Res *, s32, u8 *, s32);
extern s32 fn_80376350(struct Res *, s32, u8 *, s32);

static inline s32 send_packet(struct Obj *obj, s32 addr, u16 port, u8 *buf)
{
    s32 off;
    s16 prefix;
    s32 r;

    off = 0;
    if (obj->unk40 == 2) {
        prefix = 3;
        memcpy(buf, &prefix, 2);
        off = 2;
    }
    memcpy(buf + off, &lbl_8059F980, 2);
    buf[off += 2] = 0x68;
    r = fn_803783C4(obj, addr, port, buf, off + 1);
    return ((u32)(-r | r) >> 31);
}

static inline s32 send_res(struct Res *res, u8 *buf)
{
    struct Obj *o;
    s32 tmp;
    u16 cnt;
    s32 off;
    s16 prefix;
    s32 r;

    o = res->unk8;
    off = 0;
    cnt = res->unk4;
    tmp = res->unk0;
    if (o->unk40 == 2) {
        prefix = 3;
        memcpy(buf, &prefix, 2);
        off = 2;
    }
    memcpy(buf + off, &lbl_8059F980, 2);
    buf[off += 2] = 0x68;
    r = fn_803783C4(o, tmp, cnt, buf, off + 1);
    return ((u32)(-r | r) >> 31);
}

static inline s32 process_packet(struct Obj *obj, struct Res *res, s32 addr,
                                 u16 port, u8 *data, s32 size, s32 *out)
{
    s32 result;

    if (res->unkC < 5) {
        if (fn_803740D8(obj, addr, port, data, size, out) == 0) {
            return 0;
        }
    } else {
        if (res->unkC != 5 && res->unkC != 6) {
            result = 1;
        } else if (fn_8035A590(res->unk9C) != 0) {
            if (fn_80373ED4(res, 0, data, size, 0) == 0) {
                result = 0;
            } else {
                result = 1;
            }
        } else {
            result = fn_80373B7C(res, data, size, 0) != 0;
        }
        if (result == 0) {
            return 0;
        }
    }
    return 1;
}

s32 fn_80376618(struct Obj *arg0, u8 *arg1, s32 arg2, s32 arg3, u16 arg4)
{
    s32 flag;
    s32 diff;
    u8 *ptr;
    s16 tmpC;
    s16 tmpA;
    s16 tmp8;
    u8 buf28[8];
    u8 buf20[8];
    u8 buf18[8];
    struct Res *sp14;
    s32 sp10;
    s32 off;
    s32 r;
    struct Obj *o;
    u16 cnt;
    s32 tmp;

    ptr = arg1 + arg0->unk44;
    diff = arg2 - arg0->unk44;

    sp14 = fn_80377D90(arg0, arg3, arg4);
    if (arg0->unk2C != 0) {
        if (fn_80373FDC(arg0, sp14, arg3, arg4, 0, arg1, arg2, 0) == 0) {
            return 0;
        }
    }

    flag = 0;
    if (diff > 2) {
        if (fn_803F6150(ptr, &lbl_8059F980, 2)) {
        } else {
            flag = 1;
        }
    }

    if (sp14 == 0) {
        if (fn_803740D8(arg0, arg3, arg4, arg1, arg2, &sp10) == 0) {
            return 0;
        }
        if (sp10 != 0) {
            return 1;
        }
        if (flag != 0 && ptr[2] == 1) {
            goto block_unk20;
        }
        if (flag != 0 && ptr[2] == 0x68) {
            goto send_done;
        }
        if (send_packet(arg0, arg3, arg4, buf28) == 0) {
            return 0;
        }
    send_done:
        return 1;

    block_unk20:
        if (arg0->unk20 == 0) {
            return 1;
        }
        r = fn_803741F8(arg0, &sp14, arg3, arg4);
        if (r != 0) {
            if (r != 5) {
                if (send_packet(arg0, arg3, arg4, buf20) == 0) {
                    return 0;
                }
            }
            return 1;
        }
    }

    if (sp14->unkC == 7) {
        if (flag != 0 && ptr[2] == 0x68) {
            goto res_send_done;
        }
        if (send_res(sp14, buf18) == 0) {
            return 0;
        }
    res_send_done:
        return 1;
    }

    if (flag != 0 && diff >= 4) {
        if (fn_803F6150(ptr + 2, &lbl_8059F980, 2) == 0) {
            flag = 0;
            arg2 -= 2;
            arg1[3] = arg1[1];
            arg1[2] = arg1[0];
            arg1 = ptr;
            ptr += arg0->unk44;
        }
    }

    if (flag == 0) {
        return process_packet(arg0, sp14, arg3, arg4, arg1, arg2, &sp10);
    }

    if ((s32)ptr[2] < 8) {
        return fn_80375D18(sp14, ptr[2], arg1, arg2) != 0;
    }
    return fn_80376350(sp14, ptr[2], arg1, arg2) != 0;
}
