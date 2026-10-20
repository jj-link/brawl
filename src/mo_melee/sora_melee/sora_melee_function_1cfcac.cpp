#pragma force_active on
struct Flags {
    unsigned int : 5;
    unsigned int field : 5;
    unsigned int : 22;
};

extern "C" void fn_27_1CFCAC(Flags *p, unsigned int value)
{
    p[2].field = (value >> 0) & 0x1fu;
}
