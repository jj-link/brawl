#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Ctx {
    u8 pad0[0x15E8];
    u32 flags;
    u8 pad1[0x1608 - 0x15EC];
    u32 val1608;
} Ctx;

typedef struct Node {
    u16 flags;
    u8 pad2[6];
    u32 start;
    u32 lo;
    u32 hi;
    u8 pad14[4];
    u32 value;
    u32 tag;
    struct Node *prev;
    struct Node *next;
} Node;

extern s32 fn_803AE918(Ctx *, Node *);
extern s32 fn_803C7F98(Ctx *, s32);

s32 fn_803AF38C(Ctx *arg0, Node **arg1, Node *arg2, s32 arg3)
{
    s32 var_r31;
    s32 temp_r3;
    Node *head;
    Node *temp_r8;

    var_r31 = 0;
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

    if (arg2->lo == 0) {
        arg2->flags = (u16)(arg2->flags | 2);
        arg2->lo = arg2->start;
        arg2->hi = arg2->start;
    } else {
        if (arg2->start < arg2->lo) {
            arg2->lo = arg2->start;
        } else if (arg2->start > arg2->hi) {
            arg2->hi = arg2->start;
        }
    }

    if (arg3 != 0) {
        arg2->tag = arg0->val1608;
    } else {
        arg2->tag = 0;
    }

    if ((arg0->flags & 1) || ((arg0->flags & 4) && (arg2->flags & 4))) {
        if (arg2 != 0 && (arg2->flags & 2) && arg2->value != 0xFFFFFFFFU) {
            var_r31 = 1;
        }
        temp_r3 = fn_803AE918(arg0, arg2);
        if (temp_r3 != 0) {
            return temp_r3;
        }
        if (var_r31 != 0 && fn_803C7F98(arg0, 1) != 0) {
            return 0x11;
        }
    }
    return 0;
}
