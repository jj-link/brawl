#include <types.h>
#pragma force_active on

typedef struct Obj {
    u8 pad[12];
    s32 (*fn)(s32, struct Obj *);
} Obj;
typedef struct Node {
    u32 flags;
    Obj *obj;
    u8 pad[4];
    u32 generation;
    u8 pad2[2];
    u16 count;
    u8 pad3[0x1C];
    s32 extra;
} Node;
typedef struct Entry {
    u32 generation;
    Node *node;
} Entry;
typedef struct State {
    u32 first;
    Entry entries[26];
    u8 pad[0xD0];
    Node nodes[26];
} State;

extern State lbl_8053A6E0;
extern void fn_803ADD18(s32, s32);

static inline s32 invalid(u32 a)
{
    u32 index = a & 0xFF;
    u32 type = a & 0xFF00;
    u32 generation = a >> 16;
    Node *node;
    u16 i;
    if (index >= 26 || type != 0x300 ||
        generation > lbl_8053A6E0.nodes[index].generation) {
        return 1;
    }
    node = &lbl_8053A6E0.nodes[index];
    for (i = 0; i < 26; i++) {
        if (lbl_8053A6E0.entries[i].node == node &&
            (a >> 16) == lbl_8053A6E0.entries[i].generation) {
            break;
        }
    }
    return i >= 26;
}

s32 fn_803ABD7C(s32 arg0, u32 arg1)
{
    Node *node;
    s32 result;
    u32 index;

    if (arg0 == 0)
        return 1;
    index = (u32)arg0 & 0xFF;
    result = invalid(arg0);
    if (result)
        return result;
    node = &lbl_8053A6E0.nodes[index];
    if (node->count == 0)
        return 0xE;
    result = 0;
    if (node->count == 1) {
        Obj *o = node->obj;
        result = o->fn(arg0, o);
        if (result != 0) {
            if (node->extra != 0)
                fn_803ADD18(node->extra, result);
            result = 0x15;
        }
    }
    if (result == 0 || arg1 == 1) {
        node->count -= 1;
        if (node->count == 0)
            node->flags &= ~2U;
    }
    return result;
}
