#pragma force_active on
typedef unsigned char u8;

struct fn27Work {
    u8 pad[0xa4];
    u8 a : 1;
    u8 flag : 1;
    u8 c : 1;
    u8 d : 1;
    u8 e : 1;
    u8 f : 1;
    u8 g : 1;
    u8 h : 1;
};

extern "C" {
bool fn_27_1DB914(fn27Work* p)
{
    return p->flag;
}
}
