#include <types.h>
#pragma force_active on
struct Entry { int state; int arg; };
struct Manager {
    u8 pad[4];
    u8 count;
    u8 current;
    u8 pad6[2];
    u8 started;
    u8 pad9[3];
    Entry entries[1];
};
extern "C" {
extern Manager* lbl_8059FFFC;
void fn_801E99C4(int);
void fn_801E9A30(int);
void fn_801E98B0();
}
static bool hasPending(Manager* p) {
    for (int i = 0; i < p->count; ++i) {
        if (p->entries[i].state == 2)
            return true;
    }
    return false;
}
extern "C" void fn_80023CA8() {
    Manager* p = lbl_8059FFFC;
    if (hasPending(p)) {
        u8 next = 0;
        if (p->current != 0xF0) {
            p->entries[p->current].state = 0;
            next = p->current + 1;
            if (next >= p->count)
                next = 0;
        }
        if (p->entries[next].state == 2) {
            p->entries[next].state = 3;
            p->current = next;
            fn_801E99C4(p->entries[next].arg);
            if (p->started == 0) {
                fn_801E9A30(0);
                p->started = 1;
            }
        }
    }
    fn_801E98B0();
}