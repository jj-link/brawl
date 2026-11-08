#include <types.h>
#pragma force_active on
typedef struct Disk { char pad[0x20]; u8 shift; char pad21[0x17]; u32 size; char pad3c[0x1840]; u16 flags; } Disk;
typedef struct Inner { u32 flags; char pad04[0x30]; void *ptr; char pad38[0x22c]; u32 offset; Disk *disk; } Inner;
typedef struct A { u32 a,b,c; } A;
typedef struct B { u32 a,b,c,d; } B;
typedef struct Obj { u32 flags, pad; Inner *inner; A x; u32 pad18; B y; } Obj;
extern char lbl_8053B248[];
extern void fn_803BB01C(void *, u32);
extern int fn_803B7158(void *, u32, u32, int *, u32 *);
int fn_803B053C(Obj *obj, u32 len, u32 *out, int *out2) {
    Inner *inner;
    Disk *disk;
    B y;
    A x;
    u32 count;
    int result;
    *out = 0;
    if (lbl_8053B248 > (char *)obj || lbl_8053B248 + 0x27fb8 < (char *)obj) return 10;
    if (!obj || !(inner = obj->inner) || !(obj->flags & 1) || !(inner->flags & 1) || !(inner->flags & 2)) return 0x26;
    if (!(inner->flags & 1) || !(inner->flags & 2)) return 0x26;
    disk = obj == 0 ? 0 : inner->disk;
    if (!disk) return 0x26;
    y = obj->y;
    x = obj->x;
    inner->ptr = &obj->x;
    *out2 = -1;
    if (disk->flags & 4) {
        if (disk->size + 0x10000 != 0xffff && disk->size == 0) return 6;
    }
    fn_803BB01C(obj, obj->inner->offset + len);
    if (obj->y.a + 0x10000 == 0xffff) { *out = 0; return 0x25; }
    result = fn_803B7158((char *)obj->inner + 4, obj->y.c, len, out2, &count);
    if (result) {
        obj->y = y;
        obj->x = x;
        return result;
    }
    obj->y = y;
    obj->x = x;
    count <<= disk->shift;
    *out = len < count ? len : count;
    return 0;
}