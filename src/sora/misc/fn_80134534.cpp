#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
extern "C" u32 fn_80111C54(u16 *p, u32 x);
struct S { u16 a; u16 b; };
struct En { u32 a; u32 b; u16* c; u32 d; };
struct E { char pad[0xD4]; En e[1]; };
extern "C" S fn_80134534(E* o, int i) {
    S s2;
    S s1;
    int f2 = 0, f1 = 0;
    En* p = &o->e[i];
    u32 a = p->a;
    if (a != 0 && p->b != 0) f1 = 1;
    if (f1 && p->c != 0) f2 = 1;
    if (f2) {
        *(u32*)&s1 = 0xFFFF;
        s1.a = *p->c;
        s1.b = fn_80111C54(p->c, a);
        return s1;
    } else {
        *(u32*)&s2 = 0xFFFF;
        s2.a = 0;
        s2.b = 0;
        return s2;
    }
}
