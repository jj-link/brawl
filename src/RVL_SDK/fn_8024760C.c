#pragma force_active on
extern void *memcpy(void *, const void *, unsigned int);
extern void *memset(void *, int, unsigned int);
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Node Node;
struct Node { Node *next; u16 type; u16 flags; Node *child; };
typedef struct Group { Node *nodes; struct Group *next; } Group;
typedef struct Result {
    char a[32], b[32], c[32];
    u16 x, y;
    u8 z, w;
    u16 v, len;
    void *data;
    Group *group;
} Result;
typedef struct Uuid { u16 type; u16 pad; u16 value; u8 rest[14]; } Uuid;
extern u8 lbl_8052C9B8[0x408];
extern Group *fn_80256DE8(void *, void *, Group *);
extern Node *fn_80256CF4(Group *, unsigned int);
void fn_8024760C(int status)
{
    Uuid uuid;
    Group *group;
    Result *out = (Result *)&lbl_8052C9B8[0x38c];
    u16 flags = 0;
    Node *p, *q;
    u16 n;
    u32 len;
    void *container = *(void **)&lbl_8052C9B8[0x388];
    uuid.type = 2;
    uuid.value = 0x1124;
    lbl_8052C9B8[0x380] = 0;
    if (status) {
        (*(void (**)(int,int,void *))&lbl_8052C9B8[0x384])(status,0,0);
        return;
    }
    group = fn_80256DE8(container, &uuid, 0);
    if (!group) {
        (*(void (**)(int,int,void *))&lbl_8052C9B8[0x384])(12,0,0);
        return;
    }
    memset(out,0,0x74);
    p = fn_80256CF4(group,0x206);
    if (!p || ((int)p->flags >> 12) != 6 ||
        !(p = p->child) || ((int)p->flags >> 12) != 6 ||
        !(p = p->child) || !(q = p->next) ||
        ((int)q->flags >> 12) != 4) {
        (*(void (**)(int,int,void *))&lbl_8052C9B8[0x384])(13,0,0);
        return;
    }
    n = q->flags;
    out->len = n & 0xfff;
    if (out->len) out->data = (u8 *)q + 8;
    p = fn_80256CF4(group,0x204);
    if (p && *((u8 *)p+8)) flags |= 1;
    p = fn_80256CF4(group,0x205);
    if (p && *((u8 *)p+8)) flags |= 4;
    p = fn_80256CF4(group,0x20d);
    if (p && *((u8 *)p+8)) flags |= 2;
    p = fn_80256CF4(group,0x208);
    if (p && *((u8 *)p+8)) flags |= 8;
    p = fn_80256CF4(group,0x209);
    if (p && *((u8 *)p+8)) flags |= 16;
    p = fn_80256CF4(group,0x20a);
    if (p && *((u8 *)p+8)) flags |= 32;
    p = fn_80256CF4(group,0x100);
    if (p) {
        len = p->flags & 0xfff;
        if (len < 32) { memcpy(out->a,(u8 *)p+8,len); out->a[len] = 0; }
        else { memcpy(out->a,(u8 *)p+8,31); out->b[0] = 0; }
    } else out->a[0] = 0;
    p = fn_80256CF4(group,0x101);
    if (p) {
        len = p->flags & 0xfff;
        if (len < 32) { memcpy(out->b,(u8 *)p+8,len); out->b[len] = 0; }
        else { memcpy(out->b,(u8 *)p+8,31); out->c[0] = 0; }
    } else out->b[0] = 0;
    p = fn_80256CF4(group,0x102);
    if (p) {
        len = p->flags & 0xfff;
        if (len < 32) { memcpy(out->c,(u8 *)p+8,len); out->c[len] = 0; }
        else { memcpy(out->c,(u8 *)p+8,31); *(u8 *)&out->x = 0; }
    } else out->c[0] = 0;
    p = fn_80256CF4(group,0x200);
    if (p) out->x = *(u16 *)((u8 *)p+8);
    p = fn_80256CF4(group,0x203);
    if (p) out->w = *((u8 *)p+8);
    p = fn_80256CF4(group,0x202);
    if (p) out->z = *((u8 *)p+8);
    p = fn_80256CF4(group,0x201);
    if (p) out->y = *(u16 *)((u8 *)p+8);
    p = fn_80256CF4(group,0x20c);
    if (p) { flags |= 64; out->v = *(u16 *)((u8 *)p+8); }
    *(Group **)&lbl_8052C9B8[0x3fc] = group;
    (*(void (**)(int,int,void *))&lbl_8052C9B8[0x384])(0,flags,&lbl_8052C9B8[0x38c]);
}