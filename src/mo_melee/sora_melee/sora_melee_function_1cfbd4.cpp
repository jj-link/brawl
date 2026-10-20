#pragma force_active on
typedef unsigned int u32;

struct FtBits {
    u32 w0;
    u32 w1;
    u32 field : 5;
    u32 rest : 27;
};

extern "C" {
void fn_27_1CFBD4(FtBits *p, u32 v)
{
    p->field = v;
}
}
