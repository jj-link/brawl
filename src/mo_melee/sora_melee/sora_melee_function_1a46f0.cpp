#pragma force_active on
typedef unsigned long u32;

struct Obj {
    char pad[0xC];
    u32 items[1];
};

extern "C" {
void* fn_27_1A46F0(Obj* self, u32 idx) {
    return &self->items[idx];
}
}
