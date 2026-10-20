#pragma force_active on
struct Inner {
    char pad[0x4d0];
    unsigned char flag : 1;
    unsigned char rest : 7;
};

struct Outer {
    Inner* inner;
};

extern "C" {
bool fn_27_11213C(Outer* self)
{
    return self->inner->flag;
}
}
