#pragma force_active on
struct S { double d; int y; };

extern "C" int fn_74_6870(S* p)
{
    return p->y >> 30;
}
