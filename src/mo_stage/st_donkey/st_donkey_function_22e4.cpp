#pragma force_active on
struct Flags {
    char pad[0x6c];
    unsigned char a : 4;
    unsigned char b : 1;
    unsigned char c : 3;
};

extern "C" void fn_50_22E4(struct Flags *p)
{
    p->b = 0;
}
