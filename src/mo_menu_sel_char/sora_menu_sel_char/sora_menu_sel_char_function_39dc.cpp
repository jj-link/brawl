#pragma force_active on
struct B { char pad[0x1a8]; int v; };
struct A { char pad[0x44]; B* p[1]; };
extern "C" int fn_10_39DC(A* a, int i) {
    return a->p[i]->v;
}
