#pragma force_active on
struct S { char pad[8]; unsigned int a : 6; signed int f : 6; };

extern "C" int fn_79_5750(S *a0)
{
    return a0->f;
}
