#pragma force_active on
struct S {
    char pad[8];
    unsigned int c;
};

extern "C" int fn_72_444C(S *p)
{
    return (int)((p->c * 4) & 0xE0000000) >> 30;
}
