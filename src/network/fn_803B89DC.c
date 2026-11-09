#include <types.h>
#pragma force_active on
typedef struct Obj {
u16 count;
u8 pad02[0x1E];
u8 shift;
u8 pad21[7];
u32 base;
u8 pad2c[8];
s32 limit;
} Obj;
extern s32 fn_803BFFC8(Obj *, u8 *, int, int, int);
extern s32 fn_803C0360(Obj *, u8 *, int, int, int);
s32 fn_803B89DC(Obj *arg0, u32 arg1, s32 arg2) {
u8 buf[2];
u16 idx;
u16 r28;
u16 v;
s32 r;
u16 offset;
if (arg0 == 0) return 10;
if ((arg1 < 2 || arg1 >= (u32)(arg0->limit + 2)) && arg1 != 0 && arg1 != 1) return 14;
offset = arg1 + ((s32)arg1 >> 1);
idx = (u16)(arg0->base + ((s32)offset >> arg0->shift));
r28 = (u16)(offset & (arg0->count - 1));
if (arg1 & 1) {
r = fn_803BFFC8(arg0, buf, idx, r28, 1);
if (r != 0) return r;
v = (u16)((((u16)arg2) << 4) + (buf[0] & 0xF));
} else {
r = fn_803BFFC8(arg0, buf, (u16)(arg0->base + ((s32)(offset + 1) >> arg0->shift)), (u16)((offset + 1) & (arg0->count - 1)), 1);
if (r != 0) return r;
v = (u16)(((buf[0] & 0xF0) << 8) + (arg2 & 0xFFF));
}
*(u16 *)buf = ((v << 8) & 0xFF00) | ((v >> 8) & 0xFF);
if ((s32)r28 < (s32)(arg0->count - 1)) return fn_803C0360(arg0, buf, idx, r28, 2);
r = fn_803C0360(arg0, buf, idx, r28, 1);
if (r == 0) r = fn_803C0360(arg0, buf + 1, idx + 1, 0, 1);
return r;
}
