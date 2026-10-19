#pragma force_active on
extern "C" {
typedef unsigned char u8;
typedef int s32;

struct Obj {
    u8 pad[8];
    s32 flags;
};

void* fn_79_5CDC(Obj* self, s32 idx) {
    s32 i = (self->flags >> 28) + idx;
    if (i >= 6) {
        i -= 6;
    }
    return (u8*)self + (i << 3) + 12;
}
}
