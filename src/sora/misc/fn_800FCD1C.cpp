#pragma force_active on
struct B { char pad[0x64]; int f; };
struct A { char pad[0x40]; B* p; };
extern "C" void fn_800DA6EC(B*, int, int);
extern "C" void fn_800FCD1C(A* a, int x) {
    int t = (x + 0x3b) / 60;
    fn_800DA6EC(a->p, t, 0);
    if (a->p->f == 1) {
        fn_800DA6EC(a->p, t / 60, t % 60);
    } else {
        fn_800DA6EC(a->p, t, 0);
    }
}
