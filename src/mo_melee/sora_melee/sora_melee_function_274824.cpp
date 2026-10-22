#pragma force_active on
#define S10(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();
struct Ev { int a; int b; int pad[3]; float x; float y; };
struct Base {
    char pad0[0x3C];
    virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9();
    S10(b) S10(c) S10(d) S10(e) S10(f)
    virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3();
    virtual void g4(Ev*, int);
    virtual void g5(); virtual void g6(); virtual void g7(); virtual void g8(); virtual void g9();
    S10(h) S10(i)
    virtual void j0(); virtual void j1();
    virtual int j2();
    virtual void j3(); virtual void j4(); virtual void j5(); virtual void j6(); virtual void j7(); virtual void j8(); virtual void j9();
    virtual void k0(); virtual void k1(); virtual void k2();
};
struct grGimmick : Base {
    char padG[0x14C - 0x40];
    void startGimmickSE(unsigned long);
    void stopGimmickSE(unsigned long);
};
struct grGimmickMotionPath : grGimmick {
    unsigned char f14C;
    void startMove();
    void stopStartSE();
};
struct Info { float f0; char p[0x2C]; float f30; char p2[0x8]; float f3C; };
extern "C" void fn_27_274F38(void*);
extern "C" const float lbl_27_rodata_4508;
struct grGimmickCatapult : grGimmick {
    Base* o14C; Info* info; grGimmickMotionPath* path;
    unsigned char state; float f15C; char p[8]; int i168; int i16C;
    void processFixPosition();
};
void grGimmickCatapult::processFixPosition() {
    switch (state) {
    case 1:
        state = 2;
        f15C = lbl_27_rodata_4508;
        fn_27_274F38(this);
        startGimmickSE(0);
        break;
    case 2:
        if (f15C >= info->f30) {
            path->startMove();
            state = 3;
            startGimmickSE(1);
        }
        fn_27_274F38(this);
        break;
    case 3:
        if (path->j2()) {
            state = 4;
            Ev e;
            e.a = 0xD; e.b = 0;
            e.x = info->f0;
            e.y = info->f3C;
            o14C->g4(&e, -1);
            k2();
            path->stopStartSE();
            stopGimmickSE(1);
        } else {
            fn_27_274F38(this);
        }
        break;
    case 4:
        state = 5;
        i168 = -1;
        i16C = -1;
        startGimmickSE(3);
        break;
    case 5:
        if (path->f14C == 0) {
            state = 0;
            k1();
        }
        break;
    }
}
