#pragma force_active on
struct FnBits {
    unsigned long pad[2];
    unsigned long a : 8;
    unsigned long b : 4;
    unsigned long c : 20;
};

extern "C" void fn_66_A774(FnBits *s, unsigned long v)
{
    s->b = v;
}
