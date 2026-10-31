#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

struct In {
    u32 magic;
    u16 pad4;
    u16 version;
    u32 words[8];
};

struct Out {
    u32 words[10];
};

static inline int valid(const In* in) {
    if (in->magic != 0x52534152U)
        return 0;
    u32 version = in->version;
    if (version < 0x100U)
        return 0;
    return version <= 0x103U;
}

extern "C" void fn_801C7130(Out* __restrict dst, const In* __restrict src) {
    if (valid(src)) {
        dst->words[0] = src->magic;
        dst->words[1] = *(const u32*)((const unsigned char*)src + 4);
        dst->words[2] = src->words[0];
        dst->words[3] = src->words[1];
        dst->words[4] = src->words[2];
        dst->words[5] = src->words[3];
        dst->words[6] = src->words[4];
        dst->words[7] = src->words[5];
        dst->words[8] = src->words[6];
        dst->words[9] = src->words[7];
    }
}
