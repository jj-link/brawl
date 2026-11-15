#pragma force_active on
#include <types.h>

typedef struct Ctx {
    u8 pad0[0x1624];
    u32 flags1624;
    u8 pad1[0x1644 - 0x1628];
    u32 val1644;
} Ctx;

typedef struct Node {
    u16 flags;
    u8 pad2[6];
    u32 start;
    u32 lo;
    u32 hi;
    u8 pad14[8];
    u32 tag;
    struct Node *prev;
    struct Node *next;
} Node;

extern s32 fn_803D9280(Ctx *ctx, Node *node);

s32 fn_803D9C50(Ctx *arg0, Node **arg1, Node *arg2, s32 arg3)
{
    s32 temp_r3;
    u32 temp_r4;
    Node *head;
    Node *temp_r8;

    head = *arg1;
    if (arg2 != head) {
        if (arg2 == head->next) {
            *arg1 = arg2;
        } else {
            arg2->next->prev = arg2->prev;
            arg2->prev->next = arg2->next;
            temp_r8 = *arg1;
            arg2->prev = temp_r8;
            arg2->next = (*arg1)->next;
            temp_r8->next = arg2;
            arg2->next->prev = arg2;
            *arg1 = arg2;
        }
    }

    arg2->flags = (u16)(arg2->flags | 2);
    if (arg2->lo == 0) {
        arg2->lo = arg2->start;
        arg2->hi = arg2->start;
    } else {
        if ((u32)arg2->start < (u32)arg2->lo) {
            arg2->lo = arg2->start;
        } else if ((u32)arg2->start > (u32)arg2->hi) {
            arg2->hi = arg2->start;
        }
    }

    if (arg3 != 0) {
        arg2->tag = arg0->val1644;
    } else {
        arg2->tag = 0;
    }

    temp_r4 = arg0->flags1624;
    if ((temp_r4 & 1) || ((temp_r4 & 4) && (arg2->flags & 4))) {
        temp_r3 = fn_803D9280(arg0, arg2);
        if (temp_r3 != 0) {
            return temp_r3;
        }
    }
    return 0;
}