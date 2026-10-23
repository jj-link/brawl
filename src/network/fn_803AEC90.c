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

typedef struct Ctx {
    u8 pad0[8];
    s32 f8;
    u8 pad1[0x1608 - 0xC];
    s32 f1608;
} Ctx;

s32 fn_803AEA18(void *, Node **, void *, Node **, s32 *);
s32 fn_803AA980(void *, s32, s32, s32, u32 *);

s32 fn_803AEC90(void *arg0, Node **arg1, void *arg2, Node **arg3, s32 arg4) {
    u32 spC;
    s32 sp8;
    s32 r;
    Node *node;
    Node *head;

    r = fn_803AEA18(arg0, arg1, arg2, arg3, &sp8);
    if (r != 0) {
        return r;
    }
    if (sp8 == 0) {
        node = *arg3;
        r = fn_803AA980(arg0, node->f4, node->f18, node->f14, &spC);
        if (r != 0) {
            node = *arg3;
            node->flags &= 0xFFFC;
            node->fC = 0;
            node->f10 = 0;
            node->f18 = -1;
            node->f1C = 0;
            head = *arg1;
            if (node == head) {
                *arg1 = node->next;
            } else if (node != head->prev) {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                head = *arg1;
                node->next = head;
                node->prev = (*arg1)->prev;
                head->prev = node;
                node->prev->next = node;
            }
            return r;
        }
        node = *arg3;
        if (spC != (u32)node->f14 && (u32)((Ctx *)arg0)->f8 != (u32)(node->f18 + spC)) {
            node->flags &= 0xFFFC;
            node->fC = 0;
            node->f10 = 0;
            node->f18 = -1;
            node->f1C = 0;
            head = *arg1;
            if (node == head) {
                *arg1 = node->next;
            } else if (node != head->prev) {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                head = *arg1;
                node->next = head;
                node->prev = (*arg1)->prev;
                head->prev = node;
                node->prev->next = node;
            }
            return 0x11;
        }
        node->flags = (u16)(node->flags & 0xFFFFFFFD);
        (*arg3)->fC = 0;
        (*arg3)->f10 = 0;
        if (arg4 != 0) {
            (*arg3)->f1C = ((Ctx *)arg0)->f1608;
        } else {
            (*arg3)->f1C = 0;
        }
    }
    return 0;
}
