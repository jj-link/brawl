#pragma force_active on
struct Inner {
    char pad[0x40];
    void* f40;
};

struct Mid {
    char pad[0xd8];
    Inner* fd8;
};

struct Outer {
    char pad[0x60];
    Mid* f60;
};

extern "C" {
void* fn_27_8CDB4(Outer* self)
{
    return self->f60->fd8->f40;
}
}
