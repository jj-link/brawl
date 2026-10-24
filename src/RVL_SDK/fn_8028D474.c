#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

typedef struct Blob {
    f32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24;
    u32 v28, v2C, v30, v34;
    f32 f38, f3C;
    u32 v40, v44, v48, v4C, v50;
} Blob;

typedef struct Node {
    u16 kind;
    u16 pad2;
    u16 id;
    u16 pad6;
    struct Node *next;
} Node;

typedef struct Context {
    u32 a, b, c;
} Context;

extern void fn_80295148(void *);
extern void fn_80293CBC(Node *, Blob *, Context *);
extern void fn_80288BC8(Node *, u16, Blob *, Context *);

static inline void copy_blob(Blob *dst, const Blob *src)
{
    dst->f0 = src->f0;
    dst->f4 = src->f4;
    dst->f8 = src->f8;
    dst->fC = src->fC;
    dst->f10 = src->f10;
    dst->f14 = src->f14;
    dst->f18 = src->f18;
    dst->f1C = src->f1C;
    dst->f20 = src->f20;
    dst->f24 = src->f24;
    dst->v28 = src->v28;
    dst->v2C = src->v2C;
    dst->v30 = src->v30;
    dst->v34 = src->v34;
    dst->f38 = src->f38;
    dst->f3C = src->f3C;
    dst->v40 = src->v40;
    dst->v44 = src->v44;
    dst->v48 = src->v48;
    dst->v4C = src->v4C;
    dst->v50 = src->v50;
}

static inline signed char is_kind(Node *p)
{
    return p->kind == 0x16;
}

void fn_8028D474(Node * __restrict self, const Blob *src,
                 void *a, void *b, Context *ctx)
{
    Blob local __attribute__((aligned(16)));
    Node *p;
    u16 id;

    ctx->c -= 0x18;
    copy_blob(&local, src);
    p = self->next;

    while ((int)p->kind >= 0x17) {
        p = p->next;
    }

    fn_80295148((char *)p + 8);
    p = self->next;
    id = self->id;

    if (is_kind(p)) {
        fn_80293CBC(p, &local, ctx);
    } else {
        fn_80288BC8(p, id, &local, ctx);
    }
}
