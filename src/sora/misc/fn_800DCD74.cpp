#include <types.h>
#pragma force_active on

struct Obj {
    u32 pad[0x4C / 4];
    u32 entries[1];
};

extern "C" {
void fn_800E4CA4(char* self);

void fn_800DCD74(Obj* self, s32 index) {
    fn_800E4CA4((char*)self->entries[index]);
}
}
