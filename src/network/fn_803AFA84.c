#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Node {
    u16 flags;
    unsigned char pad[0x16];
    u32 value;
    unsigned char pad1[4];
    struct Node *next;
} Node;

extern int fn_803AE918(int, Node *);
extern int fn_803C7F98(int, int);

int fn_803AFA84(int arg0, Node *arg1)
{
    Node *node;
    int result;
    int valid;
    int pending;
    int empty;

    pending = 0;
    node = arg1;
    result = 0;

    if (!(arg1->flags & 1)) {
        return 0;
    }

    do {
        int ret;

        if (!(node->flags & 1)) {
            break;
        }

        valid = 0;
        if (node != 0 && (node->flags & 2) &&
            node->value != 0xFFFFFFFFU) {
            valid = 1;
        }

        ret = fn_803AE918(arg0, node);
        if (valid != 0 && ret == 0) {
            pending = 1;
        }

        if (ret != 0 && result == 0) {
            result = ret;
        }

        node = node->next;
    } while (node != arg1);

    if (pending != 0) {
        empty = result == 0;
        if (fn_803C7F98(arg0, empty) != 0 && empty == 1) {
            return 0x11;
        }
    }

    return result;
}
