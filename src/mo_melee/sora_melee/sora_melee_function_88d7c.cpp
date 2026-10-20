#pragma force_active on
struct S {
    unsigned int hi : 12;
    unsigned int f : 6;
    unsigned int lo : 14;
};

extern "C" void fn_27_88D7C(char *p, unsigned int v)
{
    ((struct S *)(p + 8))->f = v;
}
