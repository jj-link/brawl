#pragma force_active on
typedef int s32;

typedef struct Obj {
    s32 *tbl;
    s32 pad4;
    s32 n;
} Obj;

s32 fn_8027DD5C(Obj *o, s32 idx) {
    return o->tbl[idx + o->n + 1];
}
