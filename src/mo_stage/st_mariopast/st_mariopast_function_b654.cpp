#pragma force_active on
struct S
{
    unsigned int pad[2];
    unsigned int bits : 9;
    unsigned int rest : 23;
};

extern "C" void fn_48_B654(S *p, unsigned int value)
{
    p->bits = value;
}
