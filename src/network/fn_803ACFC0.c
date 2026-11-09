#pragma force_active on
#include <types.h>
typedef struct Node { u32 flags; s32 handle; u32 generation; u8 rest[0x20]; } Node;
typedef struct Entry { u32 generation; Node *node; } Entry;
typedef struct State { u8 first[0xD4]; Entry entries[26]; u8 pad[0x6EC-0xD4-26*8]; Node nodes[26]; } State;
extern State lbl_8053A6E0;
extern s32 fn_803AC72C(s32, s32);
extern s32 fn_803ABC88(s32);
extern s32 fn_803AC504(s32, s32 *);
extern void fn_803ABD7C(s32, u32);
extern s32 fn_803AC908(Node *);
static inline s32 invalid(u32 a) {
    Node *node;
    u16 i;
    u32 j;
    u32 index = a & 0xFF;
    u32 type = a & 0xFF00;
    u32 generation = a >> 16;
    if (index >= 26 || type != 0x400 ||
        generation > lbl_8053A6E0.nodes[index].generation) {
        return 1;
    }
    node = &lbl_8053A6E0.nodes[index];
    i = 0;
    for (j = 0; j < 13; j++) {
        if (lbl_8053A6E0.entries[i].node == node &&
            (a >> 16) == lbl_8053A6E0.entries[i].generation) {
            break;
        }
        i++;
        if (lbl_8053A6E0.entries[i].node == node &&
            (a >> 16) == lbl_8053A6E0.entries[i].generation) {
            break;
        }
        i++;
    }
    return i >= 26;
}
s32 fn_803ACFC0(s32 arg0) {
    s32 buf[8];
    Node *node;
    s32 result;
    u32 index;
    u32 key = (u32)arg0;
    if (arg0 == 0) {
        return 1;
    }
    index = key & 0xFF;
    result = invalid(key);
    if (result) {
        return result;
    }
    node = &lbl_8053A6E0.nodes[index];
    if (!(node->flags & 2)) {
    result = fn_803AC72C(node->handle, arg0);
    if (result != 0) {
        return result;
    }
    result = fn_803ABC88(node->handle);
    if (result != 0) {
        return result;
    }
    result = fn_803AC504(node->handle, buf);
    if (result != 0) {
        fn_803ABD7C(node->handle, 1);
        return result;
    }
    if (buf[3] & 1) {
        node->flags |= 0x10;
    } else {
        node->flags &= ~0x10;
    }
    result = fn_803AC908(node);
    if (result != 0) {
        fn_803ABD7C(node->handle, 1);
        return result;
    }
    } else {
        return 0xD;
    }
    node->flags = (node->flags | 2) & ~8;
    return 0;
}