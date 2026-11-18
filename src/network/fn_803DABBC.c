#include <types.h>
#pragma force_active on

typedef struct Disk { char pad[0x20]; u8 shift; char pad21[0x17]; u32 size; char pad3c[0x1f70]; u16 flags; } Disk;
typedef struct Inner { u32 flags; char pad04[0x30]; void *ptr; char pad38[0x22c]; u32 offset; Disk *disk; } Inner;
typedef struct A { u32 a, b, c; } A;
typedef struct B { u32 a, b, c, d; } B;
typedef struct Obj { u32 flags, pad; Inner *inner; A x; u32 pad18; B y; } Obj;

extern void fn_803E46AC(Obj *, u32);
extern int fn_803E4668(Obj *);
extern int fn_803E1458(void *, u32, u32, int *);
extern int fn_803E1494(void *, u32, u32, int *, u32 *);

int fn_803DABBC(Obj *obj, u32 len, u32 *out) {
    int spC;
    u32 count;
    int result;
    Disk *disk;
    B y;
    A x;
    *out = 0;
    if (!(obj->inner->flags & 1) || !(obj->inner->flags & 2)) return 0x26;
    disk = obj == 0 ? 0 : obj->inner->disk;
    y = obj->y;
    x = obj->x;
    obj->inner->ptr = &obj->x;
    spC = -1;
    if (disk->flags & 4) {
        if (disk->size + 0x10000 != 0xffff && disk->size == 0) return 6;
    }
    fn_803E46AC(obj, obj->inner->offset + len);
    if (obj->y.a + 0x10000 == 0xffff) { *out = 0; return 0x25; }
    result = fn_803E1458((char *)obj->inner + 4, obj->y.c, len, &spC);
    if (result) {
        obj->y = y;
        obj->x = x;
        return result;
    }
    count = 0;
    result = fn_803E1494((char *)obj->inner + 4, obj->y.c, len, &spC, &count);
    obj->y = y;
    obj->x = x;
    if (result) return result;
    if ((u32)(spC + 0x10000) == 0xffffU) {
        fn_803E4668(obj);
        return 0x1C;
    }
    count <<= disk->shift;
    *out = len < count ? len : count;
    return 0;
}