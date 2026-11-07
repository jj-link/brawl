#include <types.h>
#pragma force_active on
typedef struct Obj {
    u16 name[0x105];
    u8 count;
    u8 pad20b[3];
    char text[13];
    u8 flags;
    u8 size;
    u8 kind;
    u16 a, b, c, d, e;
    int f228;
    void *owner;
    int f230;
    u32 f234;
    u32 f238;
    u16 f23c, f23e;
} Obj;
typedef struct Context {
    u16 size;
    char pad02[0x1a];
    int mode;
    char pad20[0x15c0];
    int count;
} Context;
extern char lbl_8053B248[];
extern u32 fn_803A9A78(void *);
extern void *fn_803A9AA8(void *, u32);
extern u16 *fn_803AA01C(u16 *, const u16 *);
extern u8 fn_803B29D8(void *);
extern void fn_803B2DB0(void *, void *, u8, u8, int);
extern int fn_803B3290(void *, u8, void *, u32 *, void *, u32 *);
extern int fn_803B35AC(void *, int, void *, u32 *, void *);
extern int fn_803B37BC(void *, int);
extern int fn_803B3968(void *, void *);
extern u8 fn_803B3BA8(u16 *, u16 *);
extern int fn_803B847C(void *, void *, u32, void *);
extern int fn_803BEF50(void *, void *);
extern int fn_803BEFE8(void *, void *);
extern void fn_803BFF54(void *, u32);
extern int fn_803C0440(void *, void *, u32, u16, int, u32 *, int);

int fn_803BB3B4(Context *ctx, Obj *obj, void *arg2, u32 arg3) {
    Obj copy;
    char state[0x38];
    char entry[0x20];
    char state2[0x10];
    u32 blocks[2];
    u32 written;
    u32 value;
    u8 kind;
    u32 *next;
    u8 count;
    u32 i;
    u32 sector;
    int result;
    copy = *obj;
    fn_803B847C(state, state2, (u32)copy.owner, &copy.f234);
    if (ctx->count >= 5) return 0x15;
    result = fn_803BEFE8(obj->text, arg2);
    if (result && (s8)obj->text[0] == 0) return 1;
    if (result) {
        result = fn_803B3968(&copy, obj->text);
        if (result) return result;
        if (fn_803A9A78(arg2) == 1)
            fn_803BEF50(obj, fn_803A9AA8(arg2, 1));
        else
            fn_803AA01C(obj->name, fn_803A9AA8(arg2, 1));
    } else {
        obj->name[0] = 0;
    }
    if (ctx->mode == 2) obj->f234 = 1;
    else obj->f234 = 0;
    obj->f228 = 0;
    obj->owner = ctx;
    obj->flags = 0;
    obj->size = 0x20;
    obj->kind = fn_803B3BA8(&obj->b, &obj->a);
    obj->c = obj->b;
    obj->d = obj->a;
    obj->e = obj->b;
    if (obj->name[0] && !(obj->flags & 0x18)) {
        count = arg3 / 13 + (arg3 % 13 != 0);
        result = fn_803B3290(obj, count + 1, state, blocks, arg2, &value);
        if (result) return result;
        if ((*(u32 *)(lbl_8053B248 + 0x3c) & 2) == 2)
            fn_803BFF54(obj->text, value);
        obj->count = count;
        sector = obj->f238;
        kind = fn_803B29D8(obj);
        i = count;
        next = blocks;
        while (i >= 1) {
            fn_803B2DB0(entry, obj, i, kind, i == count);
            result = fn_803C0440(ctx, entry, sector, obj->f23c, 0x20, &written, 0);
            if (result) return result;
            if (written != 0x20) return 0x11;
            obj->f23c += 0x20;
            if (obj->f23c >= ctx->size) {
                obj->f23c = 0;
                sector = *next++;
            }
            i--;
        }
        obj->f238 = sector;
    } else {
        result = fn_803B35AC(obj, 1, state, blocks, arg2);
        if (result) return result;
    }
    if (obj->f234 == 1) obj->f234 = 0;
    return fn_803B37BC(obj, 1);
}