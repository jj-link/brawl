#pragma force_active on
struct S { int x[2]; int value; };

extern "C" int fn_50_5D10(S *p)
{
    return p->value >> 30;
}
