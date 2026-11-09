#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Ctx {
    u16 f0;
    char p2[4];
    u8 f6;
    char p7[9];
    int f10;
    char p14[8];
    int f1c;
    u8 f20;
    u8 f21;
    char p22[14];
    int f30;
} Ctx;

typedef struct Node {
    u8 pad0[8];
    void *data;
} Node;

typedef struct Ent {
    int a;
    int b;
    u32 c;
    int d;
    int e;
} Ent;

extern Ent lbl_8041B0E0[];
extern int PFCACHE_FlushFATCache(Ctx *);
extern int PFSEC_WriteData(void *, void *, s32, s32, s32, u32 *, s32);
extern s32 fn_803DA454(Ctx *, s32, Node **, s32 *);
extern void fn_803D634C(void *, s32, u32);
extern void fn_803DA55C(Ctx *, Node *);
extern int fn_803E25FC(Ctx *, u16, u16);
extern int fn_803E2DF0(Ctx *, int, u32);
extern int fn_803E3244(Ctx *, int, u32);

int fn_803E2074(Ctx *c) {
    u32 written;
    s32 unused;
    Node *node;
    int r;
    int base;
    int i;
    int t = c->f1c;
    int a = c->f10;
    u32 v = lbl_8041B0E0[t].c;

    switch (t) {
    case 0:
        if (v > 0xFFF)
            r = 0x10;
        else
            r = fn_803E25FC(c, a, v);
        break;
    case 1:
        if (v > 0xFFFF)
            r = 0x10;
        else
            r = fn_803E2DF0(c, a, v);
        break;
    case 2:
        if (v > 0x0FFFFFFF)
            r = 0x10;
        else
            r = fn_803E3244(c, a, v);
        break;
    default:
        r = 0xF;
    }

    if (r != 0)
        return r;

    r = PFCACHE_FlushFATCache(c);
    if (r != 0)
        return r;

    r = fn_803DA454(c, -1, &node, &unused);
    if (r != 0)
        return r;

    fn_803D634C(node->data, 0, c->f0);
    base = c->f30 + ((c->f10 - 2) << c->f21);

    for (i = 0; (u32)i < c->f6; i++) {
        r = PFSEC_WriteData(c, node->data, base + i, 0, c->f0, &written, 0);
        if (r != 0) {
            fn_803DA55C(c, node);
            return r;
        }
        if (written != c->f0) {
            fn_803DA55C(c, node);
            return 0x11;
        }
    }

    fn_803DA55C(c, node);
    return 0;
}
