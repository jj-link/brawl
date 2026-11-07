#include <types.h>
#pragma force_active on

typedef struct Inner {
    char pad[0x264];
    u32 limit;
    char pad2[0x14];
    u16 flags;
} Inner;

typedef struct Obj {
    char pad[4];
    u32 flags;
    Inner *inner;
    char pad2[0x10];
    u32 pos;
    char pad3[0xc];
    u16 field;
} Obj;

extern int fn_803BA3D0(Obj *, char *, u32, u32 *);

int fn_803BBBB8(void *unused, char *buffer, u32 size, u32 count, Obj *obj, u32 *out) {
    u32 n = 0;
    int result;
    *out = 0;
    if (!(obj->flags & 8) && ((obj->flags & 1) || (obj->flags & 4)))
        return 10;
    if ((obj->inner->flags & 3) && obj->field == 0)
        return 25;
    if (obj->pos >= obj->inner->limit)
        return 28;
    result = fn_803BA3D0(obj, buffer, size * count, &n);
    *out = n / size;
    return result & ((-result | result) >> 31);
}
