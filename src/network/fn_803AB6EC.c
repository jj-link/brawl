#pragma force_active on
typedef struct {
    unsigned int flags;
    int *ops;
    char pad[10];
    unsigned short count;
    char pad1[4];
    char data[8];
    unsigned short mode;
    char pad2[2];
    unsigned int attr;
    char pad3[8];
    int extra;
} Node;
extern void fn_803ADD18(int, int);
int fn_803AB6EC(int arg, Node *node) {
    int value;
    if (node->count == 0 || (node->flags & 0x20)) {
        value = ((int (*)(int, int *))node->ops[2])(arg, node->ops);
        if (value != 0) {
            if (node->extra != 0) fn_803ADD18(node->extra, value);
            return 0x15;
        }
        value = ((int (*)(int, void *, int *))node->ops[7])(arg, node->data, node->ops);
        if (value != 0) {
            if (node->extra != 0) fn_803ADD18(node->extra, value);
            return 0x15;
        }
        if (node->mode & 0x1ff) return 0x16;
        if (node->attr & 1) node->flags |= 0x10;
        else node->flags &= ~0x10;
        node->flags = (node->flags | 2) & ~0x20;
    }
    node->count++;
    return 0;
}