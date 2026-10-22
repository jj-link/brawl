#pragma force_active on
struct Vec { int x, y, z; };
struct Param {
    unsigned task, a, b, c;
    int owner, team, f18, f1c;
    Vec pos;
    float lr;
    int value, f34, situation, status, f40, motion, f48;
    unsigned char active : 1;
    unsigned char bits1 : 7;
    unsigned char bits2 : 2;
    unsigned char bits3 : 6;
    Param(unsigned t, unsigned r, int v, const Vec& p, float f)
        : task(t), a(r), b(r), c(r), owner(-1), team(-1), f18(0), f1c(0), pos(p), lr(f),
          value(v), f34(0), situation(2), status(0x80), f40(0), motion(0x35f), f48(0),
          active(1), bits1(0), bits2(0) {}
};
struct M {
    virtual void s08(); virtual void s0c(); virtual void s10(); virtual void s14();
    virtual void s18(); virtual void s1c();
    virtual void a20(int);
    virtual void s24(); virtual void s28();
    virtual void a2c(int);
    virtual void a30(int);
    virtual void s34(); virtual void s38();
    virtual void a3c(float, unsigned);
    virtual void s40(); virtual void s44(); virtual void s48(); virtual void s4c();
    virtual void s50(); virtual void s54(); virtual void s58(); virtual void s5c(); virtual void s60();
    virtual void a64(float);
    virtual void s68(); virtual void s6c(); virtual void s70(); virtual void s74();
    virtual void s78(); virtual void s7c(); virtual void s80(); virtual void s84(); virtual void s88(); virtual void s8c();
    virtual void a90(int, void*);
};
struct Acc { char p[0xc]; M* m0c; char q[8]; M* m18; char r[0x48]; M* m64; char s[8]; M* m70; };
struct Mod { char p[0xd8]; Acc* a; };
struct Obj { char p[0x60]; Mod* m; };
extern "C" {
extern const float lbl_112_rodata_3C;
void fn_27_1D8370(void*, const Param*);
void fn_112_10D08(Obj* o, float f1, float f2, unsigned task, unsigned res, int value, const Vec* pos) {
    Param p(task, res, value, *pos, lbl_112_rodata_3C);
    fn_27_1D8370(o, &p);
    Acc* a = o->m->a;
    a->m18->a20(-1);
    o->m->a->m18->a2c(5);
    o->m->a->m18->a30(5);
    o->m->a->m64->a3c(f1, 0x21000001);
    o->m->a->m0c->a64(f2);
    o->m->a->m70->a90(0, o->m);
}
}
