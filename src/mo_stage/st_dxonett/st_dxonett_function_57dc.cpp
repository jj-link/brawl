#pragma force_active on
extern "C" {
struct FnBits {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};
struct FnObj {
    unsigned int pad[2];
    FnBits bits;
};
void fn_78_57DC(FnObj *p, unsigned int v)
{
    p->bits.b = v;
}
}
