#pragma force_active on
typedef struct Obj {
    char pad0[0x28]; int f28;
    char pad2[0x80]; int ac, b0, b4, b8, bc, c0, c4, c8, cc;
    char pad3[4]; int d4, d8, dc;
} Obj;
typedef struct Context { char pad[0x7e4]; void (*callback)(int, int); } Context;
typedef struct Entry { char pad[8]; int result; } Entry;
extern int fn_803A88D4(int, int);
extern int fn_803A9558(int, int);
extern int fn_803A91DC(int, int, int, int, int);
extern int fn_803A9348(int, int, int);
extern int fn_803A9490(int, int);
extern int fn_803A8A2C(int, int);
extern int fn_803A8AF4(int);
extern void fn_803900EC(Context *, int);
extern Entry *fn_803970CC(int, Obj *);
int fn_80392088(Context *ctx, int arg1, Obj *obj, int arg3) {
    int done = 0;
    int result;
    Entry *entry;
    obj->ac = fn_803A88D4(obj->cc, obj->f28);
    if (ctx->callback != 0 && obj->d4 != 0)
        ctx->callback(obj->ac, obj->d4);
    if (obj->c8 == 1) {
        if (fn_803A9558(obj->ac, obj->dc) != 0) return -1005;
    } else if (obj->b0 != 0 && obj->b8 != 0) {
        if (fn_803A91DC(obj->ac, obj->b0, obj->b4, obj->b8, obj->bc) != 0) return -1005;
    }
    if (obj->c0 != 0) {
        if (fn_803A9348(obj->ac, obj->c0, obj->c4) != 0) return -1004;
    } else {
        if (fn_803A9490(obj->ac, obj->d8) != 0) return -1004;
    }
    if (fn_803A8A2C(obj->ac, arg3) < -1) return -1001;
    while (!done) {
        entry = fn_803970CC(arg1, obj);
        result = fn_803A8AF4(obj->ac);
        fn_803900EC(ctx, result);
        if (entry != 0) entry->result = result;
        switch (result) {
        case -7: case -3: case -2: break;
        case 0: done = 1; break;
        default: return -1001;
        }
    }
    return 0;
}