#pragma force_active on
struct Flags {
    unsigned int hi : 4;
    unsigned int rest : 28;
};

extern "C" void fn_57_AE2C(Flags *p, unsigned int v)
{
    p[2].hi = v;
}
