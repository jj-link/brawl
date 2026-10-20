#pragma force_active on
typedef struct Inner {
    char pad[0x28];
    void *f28;
} Inner;

typedef struct Mid {
    char pad[0xd8];
    Inner *fd8;
} Mid;

typedef struct Outer {
    char pad[0x60];
    Mid *f60;
} Outer;

extern "C" void *fn_27_8CD74(Outer *p)
{
    return p->f60->fd8->f28;
}
