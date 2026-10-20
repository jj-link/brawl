#include <types.h>
#pragma force_active on

struct fn27Entry {
    void* p0;
    void* p1;
};

struct fn27Obj {
    char pad[0x150];
    fn27Entry* arr;
    u32 count;
};

extern "C" void fn_27_27C1E8(fn27Obj* self, u32 idx, void* a, void* b) {
    if (idx >= self->count) {
        return;
    }
    fn27Entry* e = &self->arr[idx];
    e->p0 = a;
    e->p1 = b;
}
