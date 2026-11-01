#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed int s32;

typedef struct {
    void (*func)(void *, u32);
    u32 arg;
} InitFunc;

typedef struct {
    u32 flags;
    u32 handle;
    u8 pad[0x24];
    InitFunc *owner;
    u8 pad2[4];
} Node;

typedef struct {
    Node *node;
    u32 generation;
} Entry;

typedef struct {
    u16 first;
    u16 alloc_count;
    u32 pad0;
    Entry entries[26];
    u8 pad1[0xCC];
    Node nodes[26];
} State;

extern State lbl_8053A6E0;

s32 fn_803AB508(InitFunc *arg0, Node **arg1, u16 *arg2, u16 *arg3)
{
    u16 count;
    InitFunc *owner;
    u16 i;
    u16 idx;
    Node *first_free;

    *arg1 = 0;
    first_free = 0;
    idx = 0;
    for (count = 0; count < 26; count++) {
        if (lbl_8053A6E0.entries[count].node == 0) {
            break;
        }
    }

    if (count >= 26) {
        return 8;
    }

    *arg3 = count;

    for (i = 0; i < 26; i++) {
        if (!(lbl_8053A6E0.nodes[i].flags & 1)) {
            if (first_free == 0) {
                first_free = &lbl_8053A6E0.nodes[i];
                idx = i;
            }
        } else {
            owner = lbl_8053A6E0.nodes[i].owner;
            if (owner->func == arg0->func && arg0->arg == owner->arg) {
                *arg1 = &lbl_8053A6E0.nodes[i];
                *arg2 = i;
                return 0;
            }
        }
    }

    if (first_free == 0) {
        return 8;
    }

    arg0->func(&first_free->handle, arg0->arg);
    first_free->owner = arg0;
    first_free->flags |= 1;
    lbl_8053A6E0.alloc_count++;
    *arg1 = first_free;
    *arg2 = idx;
    return 0;
}
