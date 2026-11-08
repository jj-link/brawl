#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Header {
    u16 size;
    char pad[0x1E];
    u8 shift1;
    u8 shift2;
} Header;

typedef struct Tail {
    char pad[0x1F80];
    int error;
} Tail;

typedef struct Node {
    char pad[0x34];
    void *p34;
    Tail *p38;
    char pad2[0x22C];
    Header *header;
} Node;

typedef struct Obj {
    char pad[8];
    Node *node;
    char data[0xC];
    int error;
    int position;
} Obj;

extern char lbl_805644C0[];
extern int fn_803E3DE4(Obj *, char *, u32, u32 *);
extern void fn_803E15D8(void *, u32, u32 *);
extern int fn_803DABBC(Obj *, u32, u32 *);
extern int fn_803E4000(Obj *, char *, u32, u32 *);
extern int fn_803E4210(Obj *, char *, u32, u32 *);

int fn_803E4438(Obj *self, char *buffer, u32 n, u32 *out)
{
    u32 sp10;
    u32 spC;
    u32 sp8;
    int r;
    Header *header;
    u32 r26;
    u32 shift;
    u32 val;

    self->node->p34 = self->data;
    *out = 0;
    if (0xFFFFFFFFU - (u32)self->position < n) {
        n = 0xFFFFFFFFU - (u32)self->position;
        *(int *)(lbl_805644C0 + 0x40) = 0x25;
        self->node->p38->error = 0x25;
        self->error = 0x25;
    }

    r = fn_803E3DE4(self, buffer, n, &sp10);
    *out += sp10;
    if (r != 0)
        return r;
    if (sp10 >= n)
        return 0;

    n -= sp10;
    fn_803E15D8((u8 *)self->node + 4, (u32)self->position + n, &spC);
    if (self == 0)
        header = 0;
    else
        header = self->node->header;

    shift = spC << (header->shift1 + header->shift2);
    val = (u32)self->position + n;
    r26 = (val > shift) ? val - shift : 0;
    sp8 = 0;

    while (r26 != 0 || n >= header->size) {
        if (r26 != 0) {
            r = fn_803DABBC(self, r26, &sp8);
            if (r != 0 && n == r26)
                return r;
            if (sp8 == 0)
                r26 = 0;
            r26 -= sp8;
        }

        while (n >= r26 + sp8 && n >= header->size) {
            r = fn_803E4000(self, buffer + *out, n, &sp10);
            *out += sp10;
            if (r != 0)
                return r;
            if (sp10 == 0)
                return 0;
            n -= sp10;
            if (n == 0)
                break;
        }
    }

    r = fn_803E4210(self, buffer + *out, n, &sp10);
    *out += sp10;
    return r & -(r != 0);
}
