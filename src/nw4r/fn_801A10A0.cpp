#pragma force_active on
struct S {
    unsigned int a0;
    unsigned short h4, h6, h8, ha, hc, he, h10;
    unsigned int a14;
    unsigned char b18, b19, b1a, b1b, b1c, b1d, b1e, b1f;
    unsigned char b20, b21, b22, b23, b24, b25, b26, b27;
    unsigned char b28, b29, b2a, b2b, b2c, b2d, b2e, b2f;
    unsigned char b30, b31, b32, b33, b34, b35, b36, b37, b38;
};

extern "C" S lbl_804A9974;

extern "C" void fn_801A10A0(const S* s)
{
    lbl_804A9974 = *s;
}
