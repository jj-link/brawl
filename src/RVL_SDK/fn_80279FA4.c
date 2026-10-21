#pragma force_active on
typedef struct Node {
    unsigned char pad0[0xC];
    struct Node *next;
    unsigned char pad10[0xA7];
    unsigned char flags;
} Node;

extern int fn_8027A0A4(Node *);
extern Node *fn_8027A0B0(Node *);

int fn_80279FA4(Node *node)
{
    Node *p;

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
    p = node->next;
    if (p == 0) return 1;

    if (fn_8027A0A4(p) == 0) return 0;
    if (fn_8027A0B0(p) == 0) return 1;
    return fn_80279FA4(fn_8027A0B0(p));
}
