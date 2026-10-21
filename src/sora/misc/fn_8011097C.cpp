#pragma force_active on

struct Flags {
    unsigned char padding[0x2C];
    unsigned char a80 : 1;
    unsigned char a40 : 1;
    unsigned char a20 : 1;
    unsigned char aRest : 5;
    unsigned char b80 : 1;
    unsigned char b40 : 1;
    unsigned char bRest : 6;
};

extern "C" void fn_8011097C(Flags* p)
{
    p->b40 = 1;
    p->a80 = p->b40;
    if (p->a20) {
        p->a20 = 0;
    }
}
