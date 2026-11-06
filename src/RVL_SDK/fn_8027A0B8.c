#pragma force_active on
typedef struct Node {
    unsigned char pad0[0xc];
    struct Node *next;
    unsigned char pad10[0xa7];
    unsigned char flags;
} Node;
typedef struct Holder {
    unsigned char pad[0x2c];
    Node *node;
} Holder;
extern int fn_80279FA4(Node *);
int fn_8027A0B8(Holder *holder)
{
    Node *node = holder->node;
    if (!(node->flags & 1)) return 0;
    node = node->next;
    if (node == 0) return 1;
    if (!(node->flags & 1)) return 0;
    node = node->next;
    if (node == 0) return 1;
    if (!(node->flags & 1)) return 0;
    node = node->next;
    if (node == 0) return 1;
    if (!(node->flags & 1)) return 0;
    node = node->next;
    if (node == 0) return 1;
    if (!(node->flags & 1)) return 0;
    node = node->next;
    if (node == 0) return 1;
    return fn_80279FA4(node);
}