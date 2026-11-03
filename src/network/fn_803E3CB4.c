#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Node { char pad[0x34]; void *p34; char pad2[0x230]; u16 *p268; } Node;
typedef struct Obj { char pad[8]; Node *node; char data[16]; } Obj;
extern int fn_803E3730(Obj *, void *, u32, u32 *);
extern int fn_803E3928(Obj *, void *, u32, u32 *);
extern int fn_803E3AD8(Obj *, void *, u32, u32 *);

int fn_803E3CB4(Obj *s, char *buffer, u32 n, u32 *out) {
    u32 sp;
    int r;
    u16 *q;
    s->node->p34 = s->data;
    *out = 0;
    r = fn_803E3730(s, buffer, n, &sp);
    *out += sp;
    if (r != 0) return r;
    if (sp >= n) return 0;
    n -= sp;
    if (s == 0) q = 0; else q = s->node->p268;
    while (n >= *q) {
        r = fn_803E3928(s, buffer + *out, n, &sp);
        *out += sp;
        if (r != 0) return r;
        if (sp == 0) break;
        n -= sp;
    }
    r = fn_803E3AD8(s, buffer + *out, n, &sp);
    *out += sp;
    if (r != 0) return r;
    return 0;
}