#include <types.h>
#pragma force_active on

typedef struct {
    u16 limit;
    u8 pad0[6];
    u32 count;
    u8 pad1[0x1f8c - 0x0c];
    u16 flags;
} Obj;

typedef struct {
    u8 pad0[8];
    u32 base;
} Sp;

extern s32 fn_803D6D64(void *a);
extern s32 fn_803DA5EC(void *a, u32 b, void **c);
extern void fn_803D6224(s32 a, void *b, s32 c);
extern s32 fn_803DA71C(void *a, void *b);

s32 fn_803E9178(Obj *self, void *buf, u32 idx, u32 offset, s32 len) {
    void *sp8;
    s32 r;

    if (!(self->flags & 1) || fn_803D6D64(self) == 0 || (self->flags & 2)) {
        return 9;
    }
    if (idx >= self->count || offset >= self->limit || (s32)(offset + len) > (s32)self->limit) {
        return 10;
    }
    r = fn_803DA5EC(self, idx, &sp8);
    if (r != 0) {
        return r;
    }
    fn_803D6224(((Sp *)sp8)->base + offset, buf, len);
    r = fn_803DA71C(self, sp8);
    return r != 0 ? r : 0;
}
