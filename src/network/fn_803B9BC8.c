#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
struct Inner { u16 count; char pad[0x1E]; unsigned char shift; };
struct Mid { char pad[0x264]; u32 size; struct Inner *inner; };
struct Outer { char pad[8]; struct Mid *mp; char pad2[0x10]; u32 offset; int value; u32 value24; u16 pos; };
extern void fn_803B0468(char *, int);
int fn_803B9BC8(struct Outer *a, int arg1, int arg2) {
    struct Inner *pip;
    u32 pp;
    u32 vv;
    u16 cc;
    u32 co;
    struct Inner *pip2;
    int retv;
    retv = 1;
    pip = a == 0 ? 0 : a->mp->inner;
    pp = a->pos + arg1;
    vv = arg2 + (pp >> pip->shift);
    if (a->offset + arg1 < a->mp->size) {
        if (((u32)pip->count - 1) & pp) a->value = vv;
        else a->value = -1;
        a->offset += arg1;
    } else if (a->mp->size == 0) {
        a->value = -1;
        a->offset = 0;
        if (arg1 != 0) retv = 0;
    } else {
        retv = 0;
        a->value = -1;
        a->offset = a->mp->size;
    }
    pip2 = a == 0 ? 0 : a->mp->inner;
    co = a->offset;
    a->value24 = co >> pip2->shift;
    cc = pip2->count;
    a->pos = (u16)(co & ((u32)cc - 1));
    fn_803B0468((char *)a, vv);
    return retv;
}