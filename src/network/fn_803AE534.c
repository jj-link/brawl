#include <types.h>
#pragma force_active on

typedef struct Node {
    u16 flags;
    u16 f2;
    u8 *data;
    u8 *data2;
    u32 v1;
    u32 v2;
    u32 stride;
    s32 sentinel;
    u32 v3;
    struct Node *next;
    struct Node *prev;
} Node;

static inline void initNode(Node *n, Node *prev, Node *next, u8 *data, u32 stride, u32 flag)
{
    n->prev = prev;
    n->next = next;
    n->data = data;
    n->data2 = data;
    n->v1 = 0;
    n->v2 = 0;
    n->stride = stride;
    n->sentinel = -1;
    n->f2 = 0;
    n->v3 = 0;
    n->flags &= 0xFFFC;
    if (flag != 0) {
        n->flags |= 4;
    } else {
        n->flags &= ~4;
    }
}

static inline void initFinal(Node *n, Node *flagNode, Node *prev, Node *next, u8 *data, u32 stride, u32 flag)
{
    n->prev = prev;
    n->next = next;
    n->data = data;
    n->data2 = data;
    n->v1 = 0;
    n->v2 = 0;
    n->stride = stride;
    n->sentinel = -1;
    n->f2 = 0;
    n->v3 = 0;
    flagNode->flags &= 0xFFFC;
    if (flag != 0) {
        flagNode->flags |= 4;
    } else {
        flagNode->flags &= ~4;
    }
}

s32 fn_803AE534(u16 *arg0, Node **arg1, Node *arg2, u8 *arg3,
                u32 arg4, u32 arg5, u32 arg6)
{
    s32 end;
    Node *last;
    u32 limit;
    u32 rem;
    u32 count;
    u8 *data;
    u32 step;
    u32 i;

    *arg1 = arg2;
    count = ((s32)*arg0 >> 9) * arg5;

    if ((arg6 == 1 && arg4 / count < 1) || (arg6 == 0 && arg4 / count < 2)) {
        return 30;
    }

    if (arg4 / count == 1) {
        initNode(arg2, arg2, arg2, arg3, arg5, arg6);
        return 0;
    }

    rem = arg4 % count;
    limit = (arg4 - rem) - count;
    last = arg2 + limit;
    initNode(arg2, last, arg2 + count, arg3, arg5, arg6);

    for (i = count; i < limit; i += count) {
        initNode(arg2 + i, arg2 + (i - count), arg2 + (i + count), arg3 + (i << 9), arg5, arg6);
    }

    initFinal(arg2 + ((s32)arg4 - (s32)rem - (s32)count), last, arg2 + (arg4 - rem - count - count), arg2, arg3 + (((s32)arg4 - (s32)rem - (s32)count) << 9), arg5, arg6);
    return 0;
}
