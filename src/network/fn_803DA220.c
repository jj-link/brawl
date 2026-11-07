#pragma force_active on
typedef struct Node {
    unsigned short flags;
    char pad[0x1e];
    struct Node *next;
} Node;
typedef struct Owner {
    char pad[0x1624];
    unsigned int flags;
} Owner;
extern int fn_803D9280(Owner *, Node *);
int fn_803DA220(Owner *owner, Node *node) {
    Node *current = node;
    int result = 0;
    int value;
    if (!(node->flags & 1)) return 0;
    if ((owner->flags & 1) || ((owner->flags & 4) && (node->flags & 4))) return 0;
    do {
        if (!(current->flags & 1)) break;
        value = fn_803D9280(owner, current);
        if (value != 0 && result == 0) result = value;
        current = current->next;
    } while (current != node);
    return result;
}