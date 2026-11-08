#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad[4];
    u32 field_4;
    u32 generation;
    u8 rest[32];
} Node;

typedef struct {
    u32 generation;
    Node *node;
} Entry;

typedef struct {
    u8 pad0[0xD4];
    Entry entries[26];
    u8 pad1[0x6EC - 0x1A4];
    Node nodes[26];
    u8 pad2[4];
} State;

extern State lbl_8053A6E0;
s32 fn_803AC504(u32, s32 *);

static inline int invalid(u32 a) {
    u32 index = a & 0xFF;
    u32 type = a & 0xFF00;
    u32 generation = a >> 16;
    Node *node;
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

s32 fn_803AD80C(s32 arg0, s32 *arg1) {
    u32 index;
    s32 result;
    if (arg0 == 0 || arg1 == 0) {
        return 1;
    }
    index = (u32)arg0 & 0xFF;
    result = invalid((u32)arg0);
    if (result) {
        return result;
    }
    result = fn_803AC504(lbl_8053A6E0.nodes[index].field_4, arg1);
    return result & ((-result | result) >> 31);
}