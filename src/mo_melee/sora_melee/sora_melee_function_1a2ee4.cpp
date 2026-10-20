#pragma force_active on
struct Bits {
    unsigned int pad0 : 10;
    unsigned int field : 5;
    unsigned int pad1 : 17;
};

extern "C" void fn_27_1A2EE4(Bits* p, unsigned int value)
{
    p[2].field = value;
}
