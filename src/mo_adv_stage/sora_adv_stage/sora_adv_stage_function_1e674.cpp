#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_40_1E674(Obj* self) {
    self->flags |= 0x00080000;
}
}
