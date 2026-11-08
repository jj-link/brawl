#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

struct In {
    u32 magic;
    u16 pad4;
    u16 version;
    u32 pad8[2];
    u32 off10;
    u32 pad14;
};

struct Out {
    u32 p0;
    u32 p4;
};

static inline int valid(const In* in) {
    if (in->magic != 0x52534551U)
        return 0;
    u32 version = in->version;
    if (version < 0x100U)
        return 0;
    return version <= 0x100U;
}

extern "C" void fn_801C2E84(Out* __restrict dst, In* __restrict src) {
    dst->p0 = 0;
    dst->p4 = 0;
    if (valid(src)) {
        dst->p0 = (u32)src;
        dst->p4 = src->off10 + (u32)src;
    }
}