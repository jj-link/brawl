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
    char pad20[0x15fc];
    int count;
} Context;

extern char lbl_805644C0[];
extern u16 fn_803D68CC(void *, int);
extern int fn_803E2414(void *, void *, u32, void *);
extern int fn_803E7E14(void *, void *);
extern int fn_803DDC84(void *, void *);
extern u32 fn_803D66F4(void *);
extern void *fn_803D6724(void *, u32);
extern int fn_803E7D7C(void *, void *);
extern void fn_803D6528(void *, void *);
extern u8 PFENT_getcurrentDateTimeForEnt(void *, void *);
extern int fn_803DD674(void *, u8, void *, void *, void *, u32 *);
extern void fn_803E8D5C(void *, u32);
extern u8 fn_803DCE4C(void *);
extern void fn_803DD224(void *, void *, u8, u8, int);
extern int PFSEC_WriteData(void *, void *, u32, u16, int, u32 *, int);
extern int fn_803DD944(void *, int, void *, void *, void *);
extern int fn_803DDB2C(void *, int);

int fn_803E4968(Context *ctx, Obj *obj, void *arg2) {
    Obj copy;
    char state[0x38];
    char entry[0x20];
    char state2[0x10];
    u32 blocks[2];
    u32 written;
    u32 value;
    u32 *next;
    u8 count;
    u8 kind;
    u32 i;
    u32 sector;
    int result;
    s32 total;

    copy = *obj;
    total = (u16)fn_803D68CC(arg2, 1);
    if ((u32)(total + copy.f230) > 0x103U) return 1;
    if (total > 0xFF) return 1;
    fn_803E2414(state, state2, (u32)copy.owner, &copy.f234);
    if (ctx->count >= 5) return 0x15;
    result = fn_803E7E14(obj->text, arg2);
    if (result && (s8)obj->text[0] == 0) return 1;
    if (result) {
        result = fn_803DDC84(&copy, obj->text);
        if (result) return result;
        if (fn_803D66F4(arg2) == 1U) {
            fn_803E7D7C(obj, fn_803D6724(arg2, 1));
        } else {
            fn_803D6528(obj, fn_803D6724(arg2, 1));
        }
    } else {
        obj->name[0] = 0;
    }
    if (ctx->mode == 2) obj->f234 = 1;
    else obj->f234 = 0;
    obj->f228 = 0;
    obj->owner = ctx;
    obj->flags = 0;
    obj->size = 0x20;
    obj->kind = PFENT_getcurrentDateTimeForEnt(&obj->b, &obj->a);
    obj->c = obj->b;
    obj->d = obj->a;
    obj->e = obj->b;
    if (obj->name[0] && !(obj->flags & 0x18)) {
        count = total / 13 + (total % 13 != 0);
        result = fn_803DD674(obj, count + 1, state, blocks, arg2, &value);
        if (result) return result;
        if ((*(u32 *)(lbl_805644C0 + 0x60) & 2) == 2) fn_803E8D5C(obj->text, value);
        obj->count = count;
        sector = obj->f238;
        kind = fn_803DCE4C(obj);
        i = count;
        next = blocks;
        while (i >= 1) {
            fn_803DD224(entry, obj, i, kind, i == count);
            result = PFSEC_WriteData(ctx, entry, sector, obj->f23c, 0x20, &written, 0);
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
        result = fn_803DD944(obj, 1, state, blocks, arg2);
        if (result) return result;
    }
    if (obj->f234 == 1) obj->f234 = 0;
    return fn_803DDB2C(obj, 1);
}
