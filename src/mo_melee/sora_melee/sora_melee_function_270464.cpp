#pragma force_active on
struct grPad {
    char pad[0x3c];
};

struct grSubBase : public grPad {
    virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3(); virtual void w4(); virtual void w5(); virtual void w6(); virtual void w7(); virtual void w8(); virtual void w9();
    virtual void w10(); virtual void w11(); virtual void w12(); virtual void w13(); virtual void w14(); virtual void w15(); virtual void w16(); virtual void w17(); virtual void w18(); virtual void w19();
    virtual void w20(); virtual void w21(); virtual void w22(); virtual void w23(); virtual void w24(); virtual void w25(); virtual void w26(); virtual void w27(); virtual void w28(); virtual void w29();
    virtual void w30(); virtual void w31(); virtual void w32(); virtual void w33(); virtual void w34(); virtual void w35(); virtual void w36(); virtual void w37(); virtual void w38(); virtual void w39();
    virtual void w40(); virtual void w41(); virtual void w42(); virtual void w43(); virtual void w44(); virtual void w45(); virtual void w46(); virtual void w47(); virtual void w48(); virtual void w49();
    virtual void w50(); virtual void w51(); virtual void w52(); virtual void w53(); virtual void w54(); virtual void w55(); virtual void w56(); virtual void w57(); virtual void w58(); virtual void w59();
    virtual void w60(); virtual void w61();
    virtual void notify(int* ev, int value);
};

struct grGimmickSpring : public grPad {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
    virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29();
    virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39();
    virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43(); virtual void f44(); virtual void f45(); virtual void f46(); virtual void f47(); virtual void f48(); virtual void f49();
    virtual void f50(); virtual void f51(); virtual void f52(); virtual void f53(); virtual void f54(); virtual void f55(); virtual void f56(); virtual void f57(); virtual void f58(); virtual void f59();
    virtual void f60(); virtual void f61(); virtual void f62(); virtual void f63(); virtual void f64(); virtual void f65(); virtual void f66(); virtual void f67(); virtual void f68(); virtual void f69();
    virtual void f70(); virtual void f71(); virtual void f72(); virtual void f73(); virtual void f74(); virtual void f75(); virtual void f76(); virtual void f77(); virtual void f78(); virtual void f79();
    virtual void f80(); virtual void f81(); virtual void f82(); virtual void f83(); virtual void f84(); virtual void f85(); virtual void f86(); virtual void f87(); virtual void f88(); virtual void f89();
    virtual void f90(); virtual void f91(); virtual void f92(); virtual void f93(); virtual void f94(); virtual void f95(); virtual void f96(); virtual void f97(); virtual void f98(); virtual void f99();
    virtual void f100(); virtual void f101(); virtual void f102(); virtual void f103(); virtual void f104(); virtual void f105(); virtual void f106(); virtual void f107(); virtual void f108(); virtual void f109();
    virtual void f110(); virtual void f111(); virtual void f112();
    virtual void getPos(float* out);
    char pad2[0x14c - 0x40];
    grSubBase* m_sub;
    void presentPosEvent();
};

void grGimmickSpring::presentPosEvent() {
    float pos[3];
    int ev[2];
    ev[0] = 0x19;
    ev[1] = 0;
    getPos(pos);
    m_sub->notify(ev, -1);
}
