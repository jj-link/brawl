#pragma force_active on
extern "C" int fn_93_102D0(void* self);

struct VA {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual int g(int a);
    virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3(); virtual void w4(); virtual void w5(); virtual void w6(); virtual void w7(); virtual void w8(); virtual void w9();
    virtual void w10(); virtual void w11(); virtual void w12(); virtual void w13(); virtual void w14(); virtual void w15(); virtual void w16(); virtual void w17(); virtual void w18(); virtual void w19();
    virtual void w20(); virtual void w21(); virtual void w22(); virtual void w23(); virtual void w24(); virtual void w25(); virtual void w26(); virtual void w27(); virtual void w28(); virtual void w29();
    virtual void w30(); virtual void w31(); virtual void w32(); virtual void w33(); virtual void w34(); virtual void w35(); virtual void w36(); virtual void w37(); virtual void w38(); virtual void w39();
    virtual void w40(); virtual void w41(); virtual void w42(); virtual void w43(); virtual void w44(); virtual void w45(); virtual void w46(); virtual void w47(); virtual void w48(); virtual void w49();
    virtual void w50(); virtual void w51(); virtual void w52(); virtual void w53(); virtual void w54(); virtual void w55(); virtual void w56(); virtual void w57(); virtual void w58(); virtual void w59();
    virtual void w60(); virtual void w61(); virtual void w62(); virtual void w63(); virtual void w64(); virtual void w65(); virtual void w66(); virtual void w67(); virtual void w68(); virtual void w69();
    virtual void w70(); virtual void w71(); virtual void w72(); virtual void w73(); virtual void w74(); virtual void w75(); virtual void w76(); virtual void w77(); virtual void w78(); virtual void w79();
    virtual void w80(); virtual void w81(); virtual void w82(); virtual void w83(); virtual void w84(); virtual void w85(); virtual void w86(); virtual void w87(); virtual void w88();
    virtual void k(int a, bool b, bool c);
};

struct VB {
    virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4(); virtual void b5(); virtual void b6(); virtual void b7(); virtual void b8();
    virtual void b9();
};

extern "C" void fn_93_100A8(void* unused, void* self) {
    char* s = (char*)self;
    if (((VA*)(*(char**)(*(char**)(s + 0xd8) + 0x54)))->g(2)) {
        ((VA*)(*(char**)(*(char**)(s + 0xd8) + 0x54)))->k(2, false, false);
    }
    if (fn_93_102D0(self)) {
        ((VB*)(*(char**)(*(char**)(s + 0xd8) + 0x7c)))->b9();
    }
}
