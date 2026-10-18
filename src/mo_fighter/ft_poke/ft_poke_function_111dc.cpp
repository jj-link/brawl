#pragma force_active on
struct FtPokeFlags {
    char pad[0xa4];
    unsigned char a : 1;
    unsigned char b : 1;
};

extern "C" int fn_116_111DC(FtPokeFlags *p)
{
    return p->b != 0;
}
