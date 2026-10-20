#pragma force_active on
struct S
{
    unsigned int pad[2];
    unsigned int field : 4;
};

extern "C" void fn_27_1CFF6C(S *p, unsigned int value)
{
    p->field = value;
}
