#pragma force_active on
struct A { virtual void v0(); virtual void v1(); virtual void v2(); virtual int v3(); };
struct B { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual int v4(unsigned long); };
struct H { char pad[0x14]; A* a; char pad2[0x64-0x18]; B* b; };
struct M { char pad[0xd8]; H* h; };
extern "C" void fn_109_D6F8(void*, int, int);
extern "C" void fn_109_D5EC(void* u, M* m) {
    int r31 = m->h->a->v3();
    int r = m->h->b->v4(0x20000000);
    if (r == 0 && r31 == 0) fn_109_D6F8(m, 0xfb8, 0xbbc);
    else if (r == 2 && r31 == 0) fn_109_D6F8(m, 0xfb9, 0xbbc);
}