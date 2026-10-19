#pragma force_active on
struct FnState46
{
    char pad[0x6c];
    unsigned char a : 4;
    unsigned char b : 1;
    unsigned char c : 3;
};

extern "C" void fn_46_4820(FnState46 *p)
{
    p->b = 0;
}
