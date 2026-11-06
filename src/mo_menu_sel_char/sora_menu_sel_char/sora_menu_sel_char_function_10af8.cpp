#include <types.h>
#pragma force_active on
struct Entry { char pad[0xa4]; int state; int index; };
struct Holder { char pad[0x44]; void* entries[385]; int count; };
extern "C" void fn_10_14E5C(void*, int);
extern "C" Entry* fn_10_39DC(Holder*, int);
extern "C" void fn_10_1A348(Entry*, unsigned int, int);
extern "C" void fn_10_1860C(void*);
extern "C" void fn_10_10AF8(Holder* self, int flag) {
    for (int i = 0; i < self->count; i++) {
        fn_10_14E5C(self->entries[i], flag);
    }
    if (flag == 0) {
        int index;
        for (int i = 0; i < self->count; i++) {
            Entry* entry = fn_10_39DC(self, i);
            if ((unsigned int)&index != 0) index = entry->index;
            if (entry->state == 5) {
                fn_10_1A348(fn_10_39DC(self, i), 0, 0);
                fn_10_1860C(self->entries[index]);
            }
        }
    }
}