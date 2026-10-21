#pragma force_active on
typedef unsigned int u32;

struct Dst {
    char pad[0x20];
    u32 a;
    u32 b;
};

struct Src {
    u32 a;
    u32 b;
};

int fn_803D8DD4(struct Dst *dst, struct Src *src) {
    dst->a = src->a;
    dst->b = src->b;
    return 0;
}
