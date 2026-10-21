#pragma force_active on
struct S { char pad[8]; unsigned int flags; };

extern "C" unsigned int fn_67_4AD8(S *arg0)
{
    return (arg0->flags >> 25) & 1;
}
