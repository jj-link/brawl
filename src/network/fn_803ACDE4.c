#pragma force_active on

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct Node {
    u32 flags;
    char pad[4];
    u32 generation;
    char rest[2];
    u16 count;
    char rest2[28];
} Node;

typedef struct Entry {
    u32 generation;
    Node* node;
} Entry;

typedef struct State {
    u16 first;
    char pad[0xD2];
    Entry entries[26];
    char pad2[0x548];
    Node nodes[26];
    char pad3[4];
} State;

extern State lbl_8053A6E0;

static inline int invalid(u32 a) {
    u32 index = a & 0xFF;
    u32 type = a & 0xFF00;
    u32 generation = a >> 16;
    Node* node;
    u16 i;

    if (index >= 26 || type != 0x400 ||
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

static inline int find(u32 a, Node* node, u16* out) {
    u16 i;

    for (i = 0; i < 26; i++) {
        if (lbl_8053A6E0.entries[i].node == node &&
            (a >> 16) == lbl_8053A6E0.entries[i].generation) {
            break;
        }
    }
    if (i >= 26) {
        return 1;
    }
    *out = i;
    return 0;
}

int fn_803ACDE4(u32 a) {
    u32 index;
    int result;
    Node* node;
    u32 flags;
    u16 i;

    if (a == 0) {
        return 1;
    }
    index = a & 0xFF;
    result = invalid(a);
    if (result) {
        return result;
    }

    node = &lbl_8053A6E0.nodes[index];
    flags = node->flags;
    if (!(flags & 1)) {
        return 12;
    }
    if ((flags & 2) == 2) {
        return 13;
    }

    result = find(a, node, &i);
    if (result) {
        return result;
    }

    if (node->count == 1) {
        node->flags &= ~1;
        lbl_8053A6E0.first--;
    }
    node->count--;
    lbl_8053A6E0.entries[i].node = 0;
    return 0;
}
