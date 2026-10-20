#pragma force_active on
typedef struct Inner {
    unsigned char pad[0xe];
    unsigned short flags;
} Inner;

typedef struct Outer {
    unsigned char pad[4];
    Inner *inner;
} Outer;

extern "C" int fn_27_2EF68(Outer *o)
{
    return ((o->inner->flags >> 8) & 1) ^ 1;
}
