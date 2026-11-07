#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef struct Node {
    u32 flags;
    s32 handle;
    u32 generation;
    char rest[32];
} Node;
typedef struct Entry {
    u32 generation;
    Node *node;
} Entry;
typedef struct State {
    char pad[0xD4];
    Entry entries[26];
    char pad2[0x548];
    Node nodes[26];
} State;
extern State lbl_8053A6E0;
extern s32 fn_803AC72C(s32, s32);
extern s32 fn_803ABD7C(s32, u32);
static inline int invalid(u32 a) {
    u32 index = a & 0xFF;
    u32 type = a & 0xFF00;
    u32 generation = a >> 16;
    Node *node;
    u16 i;
    if (index >= 26 || type != 0x400 ||
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
s32 fn_803AD1A4(u32 a, u32 b) {
    s32 result = 0;
    s32 status;
    Node *node;
    u32 index;
    if (a == 0)
        return 1;
    index = a & 0xFF;
    status = invalid(a);
    if (status)
        return status;
    node = &lbl_8053A6E0.nodes[index];
    if (!(node->flags & 2))
        return 14;
    status = fn_803AC72C(node->handle, a);
    if (status != 0)
        return status;
    status = fn_803ABD7C(node->handle, b);
    if (status != 0)
        result = status;
    if (result == 0 || b == 1) {
        node->flags &= 0xFFFFFFFD;
        node->flags &= 0xFFFFFFE7;
    }
    return result;
}