#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Node Node;
struct Node {
    u16 flags;
    u16 pad2;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    Node *next;
    Node *prev;
};

typedef struct Pool {
    u8 pad0[8];
    s32 f8;
    u8 pad1[0x1644 - 0xC];
    s32 f1644;
} Pool;

s32 fn_803D936C(Pool *, Node **, void *, Node **, s32 *);
s32 fn_803D71D4(Pool *, s32, s32, s32, u32 *);

s32 fn_803D9590(Pool *pool, Node **head, void *arg2, Node **ppnode, s32 arg4) {
    u32 spC;
    s32 sp8;
    s32 r;
    Node *node;
    Node *h;

    r = fn_803D936C(pool, head, arg2, ppnode, &sp8);
    if (r != 0) {
        return r;
    }
    if (sp8 == 0) {
        node = *ppnode;
        r = fn_803D71D4(pool, node->f4, node->f18, node->f14, &spC);
        if (r != 0) {
            node = *ppnode;
            node->flags &= 0xFFFC;
            node->fC = 0;
            node->f10 = 0;
            node->f18 = -1;
            node->f1C = 0;
            h = *head;
            if (node == h) {
                *head = node->next;
            } else if (node != h->prev) {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                h = *head;
                node->next = h;
                node->prev = (*head)->prev;
                h->prev = node;
                node->prev->next = node;
            }
            return r;
        }
        node = *ppnode;
        if (spC != (u32)node->f14 && (u32)pool->f8 != (u32)(node->f18 + spC)) {
            node->flags &= 0xFFFC;
            node->fC = 0;
            node->f10 = 0;
            node->f18 = -1;
            node->f1C = 0;
            h = *head;
            if (node == h) {
                *head = node->next;
            } else if (node != h->prev) {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                h = *head;
                node->next = h;
                node->prev = (*head)->prev;
                h->prev = node;
                node->prev->next = node;
            }
            return 0x11;
        }
        node->flags = (u16)(node->flags & 0xFFFFFFFD);
        (*ppnode)->fC = 0;
        (*ppnode)->f10 = 0;
        if (arg4 != 0) {
            (*ppnode)->f1C = pool->f1644;
        } else {
            (*ppnode)->f1C = 0;
        }
    }
    return 0;
}
