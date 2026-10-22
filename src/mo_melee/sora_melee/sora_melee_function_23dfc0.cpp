#pragma force_active on
struct Sub { char p[8]; unsigned char b8; unsigned char b9; };
struct G2 { char p[0x606]; unsigned char b606; };
struct Glob { char p[0x30]; G2* g2; };
struct Pad { char p0[0x3c]; };
struct Self : Pad {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual int v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(int); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual unsigned char* v37();
    Sub* s;
    int i44;
    unsigned i48;
    int i4c;
    char p50[7];
    unsigned char b57;
    char p58[5];
    unsigned char b5d;
};
extern "C" {
int fn_27_23AC10(void*);
void fn_27_23AC24(void*);
void fn_27_23BC0C(void*);
void fn_27_109920(void*, int);
void fn_27_109D50(void*, int, int);
}
extern Glob* g_GameGlobal;
extern void* g_ftManager;
struct Y : Pad {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9();
    virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4(); virtual void b5(); virtual void b6(); virtual void b7(); virtual void b8(); virtual void b9();
    virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7(); virtual void c8(); virtual void c9();
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
    virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3(); virtual void e4(); virtual void e5(); virtual void e6(); virtual void e7(); virtual void e8(); virtual void e9();
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
    virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7(); virtual void g8(); virtual void g9();
    virtual void h0(); virtual void h1(); virtual void h2(); virtual void h3(); virtual void h4(); virtual void h5(); virtual void h6(); virtual void h7(); virtual void h8(); virtual void h9();
    virtual void i0(); virtual void i1(); virtual void i2(); virtual void i3(); virtual void i4(); virtual void i5(); virtual void i6(); virtual void i7(); virtual void i8(); virtual void i9();
    virtual void j0(); virtual void j1(); virtual void j2(); virtual void j3(); virtual void j4(); virtual void j5(); virtual void j6(); virtual void j7(); virtual void j8(); virtual void j9();
    virtual void k0(); virtual void k1(); virtual void k2(); virtual void k3(); virtual void k4(); virtual void k5(); virtual void k6(); virtual void k7(); virtual void k8(); virtual void k9();
    virtual void l0(); virtual void l1(); virtual void l2(); virtual void l3(); virtual void l4(); virtual void l5(); virtual void l6();
    virtual void m0(unsigned);
};
extern Y* lbl_27_bss_5668;

extern "C" void fn_27_23DFC0(Self* self) {
    if ((unsigned)((self->b5d >> 3) & 1) == 1) return;
    if (!self->v25()) return;
    if (fn_27_23AC10(self)) return;
    unsigned char* r = self->v37();
    if (!r) return;
    unsigned a = r[1];
    if (a == 3) return;
    if ((signed char)r[4] == 0 && (unsigned)((self->s->b9 >> 5) & 7) == 1) return;
    if ((unsigned)((self->s->b8 >> 2) & 0x3f) == 6 && self->i48 == 1 && !((g_GameGlobal->g2->b606 >> 7) & 1) && a == 0) return;
    if (self->i4c == -1) fn_27_23BC0C(self);
    fn_27_109920(g_ftManager, self->i4c);
    fn_27_109D50(g_ftManager, self->i4c, self->b57);
    if (lbl_27_bss_5668) lbl_27_bss_5668->m0(self->i48);
    self->v29(1);
    fn_27_23AC24(self);
}
