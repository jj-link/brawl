#include <types.h>
#pragma force_active on

typedef struct Hdr {
    u16 size;
    char pad[0x1E];
    u8 shift1;
    u8 shift2;
} Hdr;

typedef struct Tail {
    char pad[0x186C];
    int error;
} Tail;

typedef struct Node {
    char pad0[0x34];
    void *p34;
    Tail *p38;
    char pad1[0x228];
    u32 p264;
    Hdr *p268;
} Node;

typedef struct Obj {
    char pad[8];
    Node *node;
    char data[0xC];
    int error;
    u32 position;
    int unk20;
    u32 unk24;
    u16 unk28;
} Obj;

extern char lbl_8053B248[];
extern int fn_803BA518(Hdr *, Obj *, char *, u32, u32 *);
extern int fn_803BA770(Hdr *, Obj *, char *, u32, u32, u32 *);
extern int fn_803BAA34(Hdr *, Obj *, char *, u32, u32 *);
extern int fn_803B73E8(void *, u32, u32 *);
extern int fn_803B053C(Obj *, u32, u32 *, int *);
extern int fn_803C0440(Hdr *, char *, int, u32, u32, u32 *, int);
extern void fn_803B0468(Obj *, int);

static inline Hdr *getHdr(Obj *self)
{
    if (self == 0)
        return 0;
    return self->node->p268;
}

static inline int writeSect(Obj *self, Hdr *hdr, char *buf, int sector, u32 count, u32 *outw)
{
    u32 sp10;
    int r;
    Hdr *h;
    u32 n;
    u32 old20;
    u32 val;
    u32 cand;

    *outw = 0;
    r = fn_803C0440(hdr, buf, sector, self->unk28, count, &sp10, 1);
    if (r != 0 && sp10 == 0)
        return r;
    *outw = sp10;
    old20 = self->unk20;
    n = sp10;
    h = getHdr(self);
    val = self->unk28 + n;
    cand = old20 + (val >> h->shift1);
    if ((h->size - 1) & val)
        self->unk20 = cand;
    else
        self->unk20 = -1;
    self->position += n;
    if (self->position > self->node->p264)
        self->node->p264 = self->position;
    h = getHdr(self);
    self->unk24 = self->position >> h->shift1;
    self->unk28 = self->position & (h->size - 1);
    fn_803B0468(self, (int)cand);
    return 0;
}

static inline int doBeyond(Obj *self, Hdr *hdr, char *buf, u32 len, u32 *pcnt, u32 *pwritten)
{
    int sp8;
    u32 spC;
    int r;
    u32 w;

    *pwritten = 0;
    *pcnt = 0;
    r = fn_803B053C(self, len, &spC, &sp8);
    if (r != 0)
        return r;
    self->unk20 = sp8;
    if (spC == 0)
        return 0;
    *pcnt = spC;
    r = writeSect(self, hdr, buf + *pwritten, self->unk20, spC, &w);
    *pwritten += w;
    return r & -(r != 0);
}

int fn_803BAC8C(Obj *self, char *buffer, u32 n, u32 *out)
{
    u32 sp18;
    u32 sp14;
    int r;
    Hdr *hdr;
    u32 r26;
    u32 r27;
    u32 shift;
    u32 val;

    self->node->p34 = self->data;
    *out = 0;
    if (0xFFFFFFFFU - self->position < n) {
        n = 0xFFFFFFFFU - self->position;
        *(int *)(lbl_8053B248 + 0x1C) = 0x25;
        self->node->p38->error = 0x25;
        self->error = 0x25;
    }

    hdr = getHdr(self);

    r = fn_803BA518(hdr, self, buffer, n, &sp18);
    *out += sp18;
    if (r != 0)
        return r;
    if (sp18 >= n)
        return 0;

    n -= sp18;
    r = fn_803B73E8((char *)self->node + 4, self->position + n, &sp14);
    if (r != 0)
        return r;

    shift = sp14 << (hdr->shift1 + hdr->shift2);
    val = self->position + n;
    if (val > shift) {
        r26 = val - shift;
        r27 = n - r26;
    } else {
        r27 = n;
        r26 = 0;
    }

    while (r27 != 0 && r27 >= hdr->size) {
        r = fn_803BAA34(hdr, self, buffer + *out, r27, &sp18);
        *out += sp18;
        if (r != 0)
            return r;
        r27 -= sp18;
        n -= sp18;
    }

    while (r26 != 0 && n >= hdr->size) {
        r = doBeyond(self, hdr, buffer + *out, r26, &r27, &sp18);
        *out += sp18;
        if (r != 0)
            return r;
        if (r27 == 0)
            return 0;
        r26 -= r27;
        n -= sp18;
    }

    r = fn_803BA770(hdr, self, buffer + *out, n, r26, &sp18);
    *out += sp18;
    if (r != 0)
        return r;
    return 0;
}
