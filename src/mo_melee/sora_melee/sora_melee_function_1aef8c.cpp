#pragma force_active on
struct fnA {
    virtual void a0();
    int pad[3];
};

struct fnB {
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
};

struct fnD : public fnA, public fnB {
};

extern "C" {
void fn_27_1AEF8C(fnD& p) {
    fnB& r = p;
    r.b1();
}
}
