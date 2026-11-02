#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Node {
    u8 pad[12];
    u32 generation;
    u8 pad1[16];
    u16 value;
    u8 pad2[18];
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

static inline int invalid(u32 a) {
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

int fn_803AC40C(int arg0, u16 *arg1) {
    u32 index;
    int result;
    if (arg0 == 0 || arg1 == 0) {
        return 1;
    }
    index = (u32)arg0 & 0xFF;
    result = invalid((u32)arg0);
    if (result) {
        return result;
    }
    *arg1 = lbl_8053A6E0.nodes[index].value;
    return 0;
}