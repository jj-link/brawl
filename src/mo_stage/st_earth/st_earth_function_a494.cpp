#pragma force_active on
struct S
{
    unsigned int a;
    unsigned int b;
    unsigned int field : 2;
    unsigned int rest : 30;
};

extern "C" void fn_66_A494(S* p, unsigned int value)
{
    p->field = value;
}
