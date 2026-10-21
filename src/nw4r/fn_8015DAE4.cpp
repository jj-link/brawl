#pragma force_active on
extern "C" {
struct Inner {
    unsigned char pad[0x12];
    unsigned short value;
};
struct Outer {
    unsigned char pad[0x10];
    Inner *inner;
};
unsigned short fn_8015DAE4(Outer *arg)
{
    return arg->inner->value;
}
}
