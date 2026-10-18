#pragma force_active on
struct S
{
    unsigned int pad[2];
    unsigned int value : 4;
};

extern "C" void fn_63_AEEC(S* p, unsigned int value)
{
    p->value = value;
}
