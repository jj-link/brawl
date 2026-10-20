#pragma force_active on
typedef unsigned int u32;

struct Hi3 {
    u32 a : 3;
    u32 rest : 29;
};

extern "C" {
void fn_27_198958(void *p, u32 v)
{
    Hi3 *h = (Hi3 *)((u32 *)p + 2);
    h->a = v;
}
}
