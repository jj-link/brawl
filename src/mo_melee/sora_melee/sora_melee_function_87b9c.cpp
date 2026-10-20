#pragma force_active on
typedef unsigned char u8;

struct Flags {
    u8 b0 : 1;
    u8 rest : 7;
};

extern "C" {
void fn_27_87B9C(u8* p)
{
    Flags* f = (Flags*)p;
    f->b0 = 0;
}
}
