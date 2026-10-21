#pragma force_active on
typedef struct Node {
    unsigned char pad0[0x14];
    unsigned char flags;
    unsigned char pad15[0x0B];
    int field20;
    struct Node *next;
    unsigned char field28;
} Node;

typedef struct Queue {
    int field0;
    int limit;
    int field8;
    int fieldC;
    int count;
    Node *head;
    Node *tail;
    int length;
} Queue;

extern void fn_80387AB0(Queue *, Node *, int);

void fn_80387E4C(Queue *self, Node *node, int front, int mode, int flag)
{
    node->flags &= 0x43;
    node->field28 = 0;
    node->field20 = 0;

    if (mode == 2) {
        return;
    }

    if (mode == 0) {
        node->flags |= 4;
    } else if (mode == 1) {
        node->flags |= 8;
    } else if (mode == 2) {
        node->flags |= 0x20;
    } else {
        return;
    }

    if (flag && (unsigned int)mode <= 1) {
        node->flags |= 0x80;
    }

    if (self->count < self->limit) {
        fn_80387AB0(self, node, front);
    } else if (front) {
        node->next = self->head;
        self->head = node;
        if (!self->tail) {
            self->tail = node;
        }
        self->length++;
    } else {
        if (self->tail) {
            self->tail->next = node;
        }
        self->tail = node;
        node->next = 0;
        if (!self->head) {
            self->head = node;
        }
        self->length++;
    }
}
