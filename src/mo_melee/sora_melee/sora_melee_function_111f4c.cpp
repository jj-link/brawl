#pragma force_active on
struct Inner {
    char pad[0x1f];
    unsigned char a : 2;
    unsigned char b : 1;
    unsigned char c : 5;
};

struct Outer {
    Inner* inner;
};

extern "C" {
bool fn_27_111F4C(Outer* o)
{
    return o->inner->b;
}
}
