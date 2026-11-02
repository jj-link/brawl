#include <types.h>
#pragma force_active on

struct Node {
    u8 active;
    s32 links[4][2];
};

struct Obj {
    u8 pad[0x54];
    Node nodes[7];
};

extern "C" s32 fn_40_48B24(Obj* o, s32 idx, s32 dir) {
    u32 i;
    for (i = 0; i < 2; i++) {
        s32 l = o->nodes[idx].links[dir][i];
        if (l != 7 && o->nodes[l].active) return l;
    }
    for (i = 0; i < 2; i++) {
        if (o->nodes[idx].links[dir][i] != 7) {
            s32 r = fn_40_48B24(o, o->nodes[idx].links[dir][i], dir);
            if (r != 7) return r;
        }
    }
    return 7;
}
