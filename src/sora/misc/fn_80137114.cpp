#include <types.h>
#pragma force_active on

struct Entry {
    u8 pad[0xE];
    u16 flags;
};

extern "C" int fn_80114A60(void** a, Entry** b);

extern "C" int fn_80137114(u8* self, Entry** arg) {
    Entry** p = (Entry**)(self + 0x174);
    int ret = 0;
    u32 i = 0;
    while (i < self[0x7D]) {
        int f;
        Entry* b = *arg;
        int eq = 0;
        Entry* cur = *p;
        if (cur == b) {
            eq = 1;
        }
        if (eq) {
            ret = 1;
            break;
        }
        f = 0;
        if (cur->flags & b->flags & 0xF) {
            f = 1;
        }
        if (f) {
            if (fn_80114A60((void**)p, arg)) {
                ret = 1;
                break;
            }
        }
        p += 4;
        i++;
    }
    return ret;
}
