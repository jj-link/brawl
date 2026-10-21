#pragma force_active on
struct O70 {
    virtual void f0(); virtual void f1(); virtual void f2();
    virtual void f3(int, void*);
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
    virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual int f16();
};

struct O14 {
    virtual void g0(); virtual void g1(); virtual void g2();
    virtual int g3();
};

struct Hdr8 { int a; int b; };

struct O10 : Hdr8 {
    virtual void h0(); virtual void h1(); virtual void h2(); virtual void h3(); virtual void h4();
    virtual void h5(); virtual void h6(); virtual void h7(); virtual void h8(); virtual void h9();
    virtual void h10(); virtual void h11(); virtual void h12(); virtual void h13(); virtual void h14();
    virtual void h15(); virtual void h16(); virtual void h17(); virtual void h18(); virtual void h19();
    virtual void h20(); virtual void h21(); virtual void h22(); virtual void h23(); virtual void h24();
    virtual void h25(); virtual void h26(); virtual void h27(); virtual void h28(); virtual void h29();
    virtual void h30(); virtual void h31(); virtual void h32(); virtual void h33();
    virtual int h34(int);
};

struct Inner {
    unsigned char pad0[0x10];
    O10* p10;
    O14* p14;
    unsigned char pad1[0x58];
    O70* p70;
};

struct Ctx {
    unsigned char pad[0xD8];
    Inner* inner;
};

extern "C" void fn_119_EB90(void*, Ctx* p) {
    switch (p->inner->p70->f16()) {
    case 0x11b:
        if (p->inner->p14->g3() == 0) {
            if (p->inner->p10->h34(0)) {
                p->inner->p70->f3(0x11d, p);
            }
        }
        break;
    }
}
