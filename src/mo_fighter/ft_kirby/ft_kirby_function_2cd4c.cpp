#pragma force_active on

struct Vec3i { int x, y, z; };

struct Param {
    unsigned task, a, b, c;
    int owner, team, f18, f1c;
    Vec3i pos;
    float lr;
    int value, f34, situation, status, f40, motion, f48;
    unsigned char fA : 1, fB : 3, fC : 1, fD : 3;
    unsigned char fE : 2, fF : 6;
    Param(unsigned t, unsigned r, int v, const Vec3i& p, float f)
        : task(t), a(r), b(r), c(r), owner(-1), team(-1), f18(0), f1c(0), pos(p), lr(f),
          value(v), f34(0), situation(2), status(0x80), f40(0), motion(0x35F), f48(0) {
        fA = 1;
        fB = 0;
        fC = 1;
        fD = 0;
        fE = 0;
    }
};

struct MotionBase { char pad[8]; };

class Motion : public MotionBase {
public:
    virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(int, int); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87();
    virtual void m88(); virtual void m89(); virtual void m90(); virtual void m91();
    virtual void m92(); virtual void m93(); virtual void m94(); virtual void m95();
    virtual void m96(); virtual void m97(); virtual void m98(); virtual void m99();
    virtual void m100(); virtual void m101(); virtual void m102(); virtual void m103();
    virtual void m104(); virtual void m105(); virtual void m106(); virtual void m107();
    virtual void m108(); virtual void m109(); virtual void m110(); virtual void m111();
    virtual void m112(); virtual void m113();
    virtual unsigned get(int);
};

class VObj {
public:
    virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int, bool); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(float, unsigned);
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(unsigned); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(int, void*);
};

struct Acc { char p0[0x10]; Motion* m10; VObj* m14; char p1[0x4C]; VObj* m64; char p2[8]; VObj* m70; };
struct Mod { char p[0xD8]; Acc* a; };
struct Obj { char p[0x60]; Mod* m; };

extern "C" {
void fn_27_1D8370(void*, const Param*);

void fn_96_2CD4C(Obj* o, unsigned task, unsigned res, const Vec3i* pos, float f1, float f2, float f3) {
    Param p(task, res, -1, *pos, f1);
    fn_27_1D8370(o, &p);
    if (o->m->a->m10->get(0) == 1) {
        o->m->a->m14->v8(0, false);
        o->m->a->m10->m21(1, 0);
    } else {
        o->m->a->m14->v8(2, false);
        o->m->a->m10->m21(5, 0);
    }
    o->m->a->m70->v36(0, o->m);
    o->m->a->m64->v15(f2, 0x21000000);
    o->m->a->m64->v15(f3, 0x21000001);
    o->m->a->m64->v20(0x12000000);
}
}
