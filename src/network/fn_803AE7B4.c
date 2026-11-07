#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct Node {
    u16 flags;
    u16 pad;
    u32 base;
    u32 current;
    u32 padC[2];
    u32 count;
    u32 start;
    u32 pad1C;
    struct Node *next;
} Node;
typedef struct Owner {
    char pad[0x20];
    u8 shift;
} Owner;
Node *fn_803AE7B4(Owner *owner, Node *node, u32 index) {
    u32 start;
    Node *p;
    if (index == 0xFFFFFFFFU) return 0;
    if (!(node->flags & 1)) return 0;
    start = node->start;
    if (start <= index && start + node->count - 1 >= index) {
        node->current = node->base + ((index - start) << owner->shift);
        return node;
    }
    p = node->next;
    while (p != node) {
        if (!(p->flags & 1)) return 0;
        start = p->start;
        if (start <= index && start + p->count - 1 >= index) {
            p->current = p->base + ((index - start) << owner->shift);
            return p;
        }
        p = p->next;
    }
    return 0;
}