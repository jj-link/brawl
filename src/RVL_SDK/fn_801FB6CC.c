#include <types.h>
#pragma force_active on
typedef struct Node {
    struct Node *next;
    struct Node *prev;
} Node;

extern Node lbl_804E43F0[];

void fn_801FB6CC(void)
{
    Node *d;
    Node *c;
    Node *b;
    u32 base;
    Node *a;

    base = (u32)lbl_804E43F0;
    a = (Node *)base;
    b = (Node *)(base + 8);
    c = (Node *)(base + 16);
    d = (Node *)(base + 24);

    a->next = a;
    a->prev = a;
    b->next = b;
    b->prev = b;
    c->next = c;
    c->prev = c;
    d->next = d;
    d->prev = d;
}
