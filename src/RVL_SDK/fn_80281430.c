#include <types.h>
#pragma force_active on

typedef struct Obj {
    void *vt;
    u16 pad4;
    u16 flag;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    u8 f18;
} Obj;

extern char lbl_80486498[];
extern void fn_80281D64(int, int, int);

Obj *fn_80281430(Obj *o, int a, int b, const char *flag)
{
    o->flag = 1;
    o->vt = lbl_80486498;
    o->f8 = 0;
    o->fC = a;
    o->f10 = 0;
    o->f14 = *flag ? b - 1 : b;
    o->f18 = 0;
    if (*flag) fn_80281D64(a, 0, b);
    return o;
}
