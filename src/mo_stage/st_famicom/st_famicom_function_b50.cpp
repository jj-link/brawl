#pragma force_active on
struct Flags {
    unsigned char a : 4;
    unsigned char b : 1;
    unsigned char c : 3;
};

extern "C" void fn_68_B50(void *p)
{
    struct Flags *f = (struct Flags *)((char *)p + 0x6c);
    f->b = 0;
}
