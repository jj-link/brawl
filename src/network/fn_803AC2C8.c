#pragma force_active on
#include <types.h>

typedef struct Node Node;

typedef struct {
    u32 generation;
    Node *node;
} Entry;

typedef struct {
    char pad[0x10];
    int (*func)(u32, int);
} Ops;

struct Node {
    u32 flags;
    Ops *ops;
    u32 unk;
    u32 generation;
    char pad[0x20];
    int error;
};

typedef struct {
    u32 first;
    Entry entries[26];
    char pad[0xd0];
    Node nodes[26];
} State;

extern State lbl_8053A6E0;
extern void fn_803ADD18(int, int);

static inline int invalid(u32 a)
{
    u32 index = a & 0xFF;
    u32 type = a & 0xFF00;
    u32 generation = a >> 16;
    Node *node;
    u16 i;

    if (index >= 26 || type != 0x300 ||
        generation > lbl_8053A6E0.nodes[index].generation)
        return 1;

    node = &lbl_8053A6E0.nodes[index];
    for (i = 0; i < 26; i++) {
        if (lbl_8053A6E0.entries[i].node == node &&
            (a >> 16) == lbl_8053A6E0.entries[i].generation)
            break;
    }
    return i >= 26;
}

int fn_803AC2C8(u32 arg0, int arg1)
{
    u32 index;
    int result;
    int error;
    Node *node;

    if (arg0 == 0)
        return 1;

    index = arg0 & 0xFF;
    result = invalid(arg0);
    if (result)
        return result;

    node = &lbl_8053A6E0.nodes[index];
    error = node->ops->func(arg0, arg1);
    if (error) {
        if (node->error)
            fn_803ADD18(node->error, error);
        return 21;
    }
    return 0;
}
