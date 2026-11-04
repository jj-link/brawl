#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct Node Node;
typedef struct Callback { void *unused; int (*call)(int, struct Callback *); } Callback;
struct Node { u32 flags; Callback *callback; u32 unk8; u32 generation; u16 count; u8 pad[0x1E]; int extra; };
typedef struct Entry { u32 generation; Node *node; } Entry;
typedef struct State { u16 unused; u16 count; Entry entries[26]; u8 pad[0xD0]; Node nodes[26]; } State;
extern State lbl_8053A6E0;
extern void fn_803ADD18(int, int);
static inline int invalid(u32 a) {
    u32 index = a & 0xff;
    u32 type = a & 0xff00;
    u32 generation = a >> 16;
    Node *node;
    u16 i;
    if (index >= 26 || type != 0x300 || generation > lbl_8053A6E0.nodes[index].generation)
        return 1;
    node = &lbl_8053A6E0.nodes[index];
    for (i = 0; i < 26; i++) {
        if (lbl_8053A6E0.entries[i].node == node && generation == lbl_8053A6E0.entries[i].generation)
            break;
    }
    return i >= 26;
}
static inline int find(u32 a, Node *node, u16 *out) {
    u16 i;
    for (i = 0; i < 26; i++) {
        if (lbl_8053A6E0.entries[i].node == node && (a >> 16) == lbl_8053A6E0.entries[i].generation)
            break;
    }
    if (i >= 26) return 1;
    *out = i;
    return 0;
}
int fn_803ABA30(u32 a) {
    u32 index;
    int result;
    int value;
    u16 slot;
    Node *node;
    if (a == 0) return 1;
    index = a & 0xff;
    result = invalid(a);
    if (result) return result;
    node = &lbl_8053A6E0.nodes[index];
    if (!(node->flags & 1)) return 13;
    if ((node->flags & 2) == 2) return 13;
    result = find(a, node, &slot);
    if (result) return result;
    if (node->count == 1) {
        value = node->callback->call(a, node->callback);
        if (value != 0) {
            if (node->extra != 0) fn_803ADD18(node->extra, value);
            return 21;
        }
    }
    if (node->count == 1) {
        node->flags &= ~1;
        lbl_8053A6E0.count--;
    }
    node->count--;
    lbl_8053A6E0.entries[slot].node = 0;
    return 0;
}