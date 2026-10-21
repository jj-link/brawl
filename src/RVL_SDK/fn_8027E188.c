#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct S {
    s32 *f0;
    s32 f4;
    s32 f8;
};

void fn_8027E188(struct S *p) {
    s32 off;
    s32 i;

    for (i = 0, off = 0; i < p->f8 + 1; i++, off += 4) {
        *(s32 *)((u8 *)p->f0 + off) = -1;
    }
    p->f4 = 0;
}
