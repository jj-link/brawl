#pragma force_active on
struct R { char pad[0x5c]; int value; };
struct B { virtual void f0(); virtual R& get(int) const; };
struct A { char pad[4]; short off; };
extern "C" int fn_27_46F94(const A* a, const B* b, int i) {
    return b->get(a->off + i).value != 0;
}
