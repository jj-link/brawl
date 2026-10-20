#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn27Obj {
    u32 pad[2];
    s32 count;
};

extern "C" void* fn_27_FEB44(fn27Obj* self, s32 idx) {
    s32 i = (self->count >> 30) + idx;
    if (i >= 1) {
        i -= 1;
    }
    return (char*)self + i * 12 + 12;
}
