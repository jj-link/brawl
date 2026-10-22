#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct Node {
    char pad[12];
    u32 generation;
    char rest[36];
} Node;

typedef struct Entry {
    u32 generation;
    Node* node;
} Entry;

typedef struct State {
    u32 first;
    Entry entries[26];
    char pad[0xD0];
    Node nodes[26];
} State;

extern State lbl_8053A6E0;
extern int fn_803AB6EC(u32, Node*);

static inline int invalid(u32 a) {
    u32 index = a & 0xFF;
    u32 type = a & 0xFF00;
    u32 generation = a >> 16;
    Node* node;
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

int fn_803ABC88(u32 a) {
    u32 index;
    int result;
    if (a == 0) {
        return 1;
    }
    index = a & 0xFF;
    result = invalid(a);
    if (result) {
        return result;
    }
    return fn_803AB6EC(a, &lbl_8053A6E0.nodes[index]);
}
