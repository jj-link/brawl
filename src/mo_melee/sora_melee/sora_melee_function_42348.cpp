#pragma force_active on
struct R { char pad[0x24]; unsigned int a:11; unsigned int b:2; unsigned int c:19; };
struct B { virtual void f0(); virtual R& get(int) const; };
struct A { char pad[4]; short off; };
extern "C" unsigned int fn_27_42348(const A* a, const B* b, int i) {
    return b->get(a->off + i).b;
}
