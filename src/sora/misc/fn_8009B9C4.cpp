#include <types.h>
#pragma force_active on

struct Owner {
    char pad[0x60];
    void** items;
    s32 count;
};

extern "C" void fn_80095F74(void*);

extern "C" void fn_8009B9C4(Owner* self) {
    for (s32 i = 0; i < self->count; ++i) {
        fn_80095F74(self->items[i]);
    }
}
