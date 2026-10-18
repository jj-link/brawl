#pragma force_active on
struct Inner {
    char pad[0x70];
    void *f70;
};

struct Outer {
    char pad[0xd8];
    Inner *fd8;
};

extern "C" void *fn_115_138DC(Outer *p)
{
    return p->fd8->f70;
}
