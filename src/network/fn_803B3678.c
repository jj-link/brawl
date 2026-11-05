#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct Ctx {
    u16 f0;
    char pad[0x1a];
    int f1c;
    char pad20[0xc];
    u32 f2c;
    u32 f30;
} Ctx;
typedef struct Buf {
    char pad[8];
    void *f8;
} Buf;
extern int fn_803AFD48(Ctx *, int, Buf **);
extern void fn_803AFE4C(Ctx *, Buf *);
extern void *fn_803A976C(void *, int, u32);
extern int fn_803B7F1C(Ctx *);
extern int fn_803C0440(Ctx *, void *, u32, int, u16, u32 *, int);
extern void fn_803C16BC(void *, void *);
extern char lbl_80492720[];

int fn_803B3678(Ctx *c) {
    Buf *buf;
    u32 count;
    u32 i;
    int r;
    if (c == 0) return 10;
    switch (c->f1c) {
    case 2:
        fn_803B7F1C(c);
        break;
    case 0:
    case 1:
        r = fn_803AFD48(c, -1, &buf);
        if (r != 0) return r;
        fn_803A976C(buf->f8, 0, c->f0);
        for (i = c->f2c; i < c->f30; i++) {
            r = fn_803C0440(c, buf->f8, i, 0, c->f0, &count, 0);
            if (r != 0) {
                fn_803AFE4C(c, buf);
                return r;
            }
            if (count != c->f0) {
                fn_803AFE4C(c, buf);
                return 17;
            }
        }
        fn_803AFE4C(c, buf);
        break;
    default:
        return 7;
    }
    fn_803C16BC(lbl_80492720, c);
    return 0;
}