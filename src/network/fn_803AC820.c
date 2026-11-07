#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct Node {
    u32 flags;
    u8 pad[8];
    u32 generation;
    u8 rest[36];
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
extern void fn_803ADC5C(u32, int);
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
void fn_803AC820(u32 a) {
    u32 index = a & 0xFF;
    int result = invalid(a);
    if (result) return;
    lbl_8053A6E0.nodes[index].flags |= 0x2C;
    fn_803ADC5C(a, 1);
}