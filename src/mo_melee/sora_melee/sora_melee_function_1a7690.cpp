#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad0;
    u32 pad4;
    u32 flags;
};

extern "C" int fn_27_1A7690(Flags* f) {
    return (f->flags >> 19) & 1;
}
