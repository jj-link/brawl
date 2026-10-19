#pragma force_active on
typedef unsigned char u8;

struct Inner {
    u8 pad[0x1c];
    u8 top : 1;
    u8 rest : 7;
};

struct Outer {
    u8 pad[0xc];
    u8 flag;
    u8 pad2[3];
    Inner* inner;
};

extern "C" {
void fn_27_23756C(Outer* p)
{
    if (p->flag != 0) {
        p->inner->top = 1;
    } else {
        p->inner->top = 0;
    }
}
}
