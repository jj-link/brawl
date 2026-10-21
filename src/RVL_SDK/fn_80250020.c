#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct Pair {
    u32 a;
    u32 b;
};

struct Src {
    u8 pad[6];
    u8 flag;
    struct Pair pairs[3];
};

struct Dst {
    u8 pad[0x40];
    struct Pair pairs[3];
};

void fn_80250020(struct Dst* dst, struct Src* src)
{
    if (src->flag != 0) {
        dst->pairs[0] = src->pairs[0];
        dst->pairs[1] = src->pairs[1];
        dst->pairs[2] = src->pairs[2];
    }
}
