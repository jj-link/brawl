#include <types.h>
#pragma force_active on

struct Entry {
    u8 pad[0x7C];
    s32 active;
    u8 group;
    u8 pad81[3];
};

struct Manager {
    u8 pad[0x60];
    Entry* entries;
    u8 pad64[8];
    s32 count;
    s32 first;
    s32 last;
    s32 freeIndex;
};

extern "C" u32 fn_80061944(Entry*, f32);

extern "C" u8 fn_8005F56C(Manager* self, int group, u32* low, u32* high, f32 value) {
    u32 i;
    Entry* entry = self->entries + self->first;
    u8 next = 0;

    for (i = self->first; i <= self->last;) {
        if (entry->active) {
            if (!(!(group != (int)entry->group))) {
                if (group < (int)entry->group && !next)
                    next = entry->group;
            } else {
                if (fn_80061944(entry, value) == 1) {
                    self->count--;
                    if (self->freeIndex > i)
                        self->freeIndex = i;
                }
                if (*low > i)
                    *low = i;
                if (*high < i)
                    *high = i;
            }
        }
        ++i;
        ++entry;
    }
    return next;
}