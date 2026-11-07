#pragma force_active on
class Obj7 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int, bool);
};

struct Pad8 {
    char pad[8];
};

class soModelModuleImpl : public Pad8 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();

    Obj7* unkC;
    char pad10[0x38];
    int unk48;
    char pad4C[0x76];
    signed char unkC2;
    unsigned char unkC3;
    char padC4;
    signed char unkC5;

    void activate();
};

void soModelModuleImpl::activate() {
    if (unkC3 != 3) {
        unkC2 = 0;
        unkC5 &= ~0x40;
        this->s20();
        unk48 = 0;
        if (unkC != 0) {
            unkC->slot6(1, false);
            unkC->slot6(2, true);
            unkC->slot6(3, false);
            unkC->slot6(4, false);
            unkC->slot6(5, false);
            unkC->slot6(6, false);
            unkC->slot6(7, false);
            unkC->slot6(8, false);
        }
        unkC5 &= ~0x80;
    }
}
