#include <types.h>
#pragma force_active on

typedef struct Node {
    u32 flags;
    u32 owner;
    u32 generation;
    u16 type;
    u16 count;
    u8 rest[0x1C];
} Node;

typedef struct Entry {
    u32 generation;
    Node *node;
} Entry;

typedef struct State {
    u16 first;
    u16 alloc_count;
    u8 pad[0xD0];
    Entry entries[26];
    u8 pad2[0x548];
    Node nodes[26];
} State;

extern State lbl_8053A6E0;
extern s32 fn_803ACB44(s32, s32, Node **, u16 *, u16 *);
extern s32 fn_803AC61C(s32, s32 *, Entry *, s32);

s32 fn_803ACCC8(s32 arg0, s32 arg1, s32 *arg2)
{
    Node *node;
    Entry *entry;
    s32 spC;
    u16 spA;
    u16 sp8;
    s32 result;

    if (arg0 == 0 || arg2 == 0) {
        return 1;
    }
    result = fn_803ACB44(arg0, arg1, &node, &spA, &sp8);
    if (result != 0) {
        return result;
    }
    node->generation++;
    node->generation = node->generation & 0xFFFF;
    node->count++;
    entry = &lbl_8053A6E0.entries[sp8];
    entry->generation = node->generation;
    entry->node = node;
    result = fn_803AC61C(arg0, &spC, (Entry *)((u8 *)entry - 0xD4), sp8 * 8);
    if (result != 0) {
        return result;
    }
    if (spC != 0) {
        node->flags |= 4;
    }
    *arg2 = (u8)spA | 0x400 | (lbl_8053A6E0.nodes[spA].generation << 16);
    return 0;
}