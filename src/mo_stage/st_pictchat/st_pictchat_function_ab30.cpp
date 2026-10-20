#pragma force_active on
extern "C" {
struct Fld {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};
void fn_73_AB30(unsigned char *p, unsigned int v)
{
    struct Fld *f = (struct Fld *)(p + 8);
    f->b = v;
}
}
