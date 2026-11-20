#include <types.h>
#pragma force_active on

typedef struct Buffer {
    u16 flags;
    u16 dirty;
    u32 unk4;
    u32 unk8;
    u8 pad0C[12];
    u32 sector;
} Buffer;

typedef struct Context {
    u16 size;
    u8 pad02[10];
    u32 stride;
    u8 pad10[8];
    u16 flags;
    u8 pad1A[2];
    s32 kind;
    u8 shift;
    u8 pad21;
    u8 limit;
    u8 pad23[5];
    u32 base;
    u8 pad2C[8];
    u32 count;
    u32 freeCount;
    u8 pad3C[0x1600 - 0x3C];
    u32 window;
    u8 pad1604[0x1870 - 0x1604];
    s32 callback_arg;
    u8 pad1874[0x1C];
    s32 (*callback)(s32);
} Context;

extern s32 fn_803AFEDC(Context *, u32, Buffer **);
extern s32 fn_803B6F80(Context *, Buffer *);
extern s32 fn_803AFC80(Buffer *);

s32 fn_803B93C4(Context *arg0, u32 arg1, u32 arg2, Buffer **arg3) {
    u16 offset;
    s32 var_r30 = 0;
    u32 var_r29;
    u32 var_r25;
    u32 pos;
    u8 shift;
    Buffer *buf;
    u32 sector;
    s32 temp;
    s32 (*cb)(s32);

    if (arg0 == 0) {
        return 10;
    }
    if ((arg1 < 2 || arg1 >= (u32)(arg0->count + 2)) && arg1 != 0 && arg1 != 1) {
        return 14;
    }
    shift = arg0->shift;
    pos = arg1 * 2;
    buf = *arg3;
    sector = buf->sector;
    var_r29 = (u16)((pos >> shift) + arg0->base);
    offset = (u16)(pos & (arg0->size - 1));
    if (sector > var_r29 || (u32)(sector + arg0->window) <= var_r29) {
        temp = fn_803B6F80(arg0, buf);
        if (temp != 0) {
            return temp;
        }
        var_r25 = 1;
        if (arg0->flags & 0x80) {
            var_r25 = arg0->flags & 7;
        }
        do {
            var_r30 = fn_803AFEDC(arg0, var_r29, arg3);
            if (var_r30 == 0x1000) {
                cb = arg0->callback;
                if (cb != 0) {
                    temp = cb(arg0->callback_arg);
                    if (temp == 0) {
                        continue;
                    }
                    if (temp == 1 && arg0->limit >= 2 && var_r25 < arg0->limit) {
                        var_r25++;
                        var_r29 += arg0->stride;
                        continue;
                    }
                }
            }
            if (var_r30 != 0) {
                return var_r30;
            }
        } while (var_r30 != 0);
    } else {
        if (var_r29 != (u32)(sector + ((s32)(buf->unk8 - buf->unk4) >> shift))) {
            buf->unk8 = buf->unk8 + arg0->size;
        }
    }
    ((u8 *)(*arg3)->unk8)[offset] = (u8)arg2;
    *((u8 *)(*arg3)->unk8 + offset + 1) = (u8)(arg2 >> 8);
    fn_803AFC80(*arg3);
    return var_r30;
}
