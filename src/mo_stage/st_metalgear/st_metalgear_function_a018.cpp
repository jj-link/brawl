#pragma force_active on
struct Foo { char pad[8]; int value; };

extern "C" int fn_71_A018(const Foo *p)
{
    return p->value >> 30;
}
