#pragma force_active on
extern "C" const float lbl_41_rodata_E30;
extern "C" void fn_41_322F0(void*);
struct Pad8 { char p[8]; };
struct Big;
struct X { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual int a9(); };
struct Y : Pad8 { virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4(); virtual void b5(); virtual void b6(); virtual void b7(); virtual void b8(); virtual void b9(); virtual void b10(); virtual void b11(); virtual void b12(); virtual void b13(Big*); };
struct Z { virtual void c0(); virtual void c1(); virtual void c2(void*, float, short*); };
struct Z2 { virtual void c0(); virtual void c1(); virtual void c2(void*, short*); };
struct W : Pad8 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(int, int); virtual unsigned char d20(int); };
struct V { virtual void e0(); virtual void e1(); virtual void e2(); virtual int e3(); };
struct Big { char p[0x10]; W* w; V* v; char q[0x2c]; X* x; char r[0x24]; Z* z; char s[0x48]; Y* y; };
struct Acc { char p[0xd8]; Big* m; };
struct St { char p[0x34]; int f; };
struct Self { char p[0x6c]; Acc* a; char q[0x2184-0x70]; St* st; };
inline Y* extract(Big* m, Z2*& z) {
    Y* y = m->y;
    z = (Z2*)m->z;
    return y;
}
extern "C" void fn_41_32734(Self* s) {
    if (s->a->m->x->a9() == 0) {
        short k = 0x1d;
        Z2* z;
        Acc* a = s->a;
        Big* m = a->m;
        Y* y = extract(m, z);
        y->b13(m);
        z->c2(a, &k);
    } else {
        short k = 0x10;
        Acc* a = s->a;
        Z* z = a->m->z;
        z->c2(a, lbl_41_rodata_E30, &k);
    }
    if (s->st->f != 0) {
        if (s->a->m->w->d20(0)) {
            if (s->a->m->v->e3() == 2) {
                if (s->a->m->w->d20(0) != 6) s->a->m->w->d19(5, 0);
            } else s->a->m->w->d19(1, 0);
        }
    }
    if (s->a->m->x->a9() == 0) fn_41_322F0(s);
}