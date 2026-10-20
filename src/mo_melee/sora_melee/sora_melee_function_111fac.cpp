#pragma force_active on
typedef unsigned char u8;

struct Inner {
    char pad[0x1f];
    u8 a : 5;
    u8 flag : 1;
    u8 b : 2;
};

struct Outer {
    Inner *p;
};

extern "C" {
bool fn_27_111FAC(Outer *o)
{
    return o->p->flag;
}
}
