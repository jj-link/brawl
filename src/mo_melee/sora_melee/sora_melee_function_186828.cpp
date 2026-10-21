#pragma force_active on

struct Obj1 {
    char pad[8];
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual void s6() = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
    virtual void s9() = 0;
    virtual void s10() = 0;
    virtual void s11() = 0;
    virtual void s12() = 0;
    virtual void s13() = 0;
    virtual void s14() = 0;
    virtual void s15() = 0;
    virtual void s16() = 0;
    virtual void s17() = 0;
    virtual void s18() = 0;
    virtual void s19() = 0;
    virtual void s20() = 0;
    virtual void s21() = 0;
    virtual void s22() = 0;
    virtual void s23() = 0;
    virtual void s24() = 0;
    virtual void s25() = 0;
    virtual void s26() = 0;
    virtual void s27() = 0;
    virtual void s28() = 0;
    virtual void s29() = 0;
    virtual void s30() = 0;
    virtual void s31() = 0;
    virtual void s32() = 0;
    virtual void s33() = 0;
    virtual void s34() = 0;
    virtual void s35() = 0;
    virtual void s36() = 0;
    virtual void s37() = 0;
    virtual void s38() = 0;
    virtual void s39() = 0;
    virtual void s40() = 0;
    virtual void s41() = 0;
    virtual void s42() = 0;
    virtual void s43() = 0;
    virtual void s44() = 0;
    virtual int s45() = 0;
};

struct Obj2 {
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual void s6() = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
    virtual void s9() = 0;
    virtual void s10() = 0;
    virtual void s11() = 0;
    virtual void s12() = 0;
    virtual void s13() = 0;
    virtual void s14() = 0;
    virtual void s15() = 0;
    virtual void s16() = 0;
    virtual void s17() = 0;
    virtual void s18() = 0;
    virtual void s19() = 0;
    virtual void s20() = 0;
    virtual void s21() = 0;
    virtual void s22() = 0;
    virtual void s23() = 0;
    virtual void s24() = 0;
    virtual void s25() = 0;
    virtual void s26() = 0;
    virtual void s27() = 0;
    virtual void s28() = 0;
    virtual void s29() = 0;
    virtual void s30() = 0;
    virtual void s31() = 0;
    virtual void s32() = 0;
    virtual void s33() = 0;
    virtual void s34() = 0;
    virtual void s35() = 0;
    virtual void s36() = 0;
    virtual void s37() = 0;
    virtual void s38() = 0;
    virtual void s39() = 0;
    virtual void s40() = 0;
    virtual void s41() = 0;
    virtual void s42() = 0;
    virtual void s43() = 0;
    virtual void s44() = 0;
    virtual void s45() = 0;
    virtual void s46() = 0;
    virtual void s47() = 0;
    virtual void s48() = 0;
    virtual void s49() = 0;
    virtual unsigned int s50(unsigned long) = 0;
    virtual int s51(unsigned long) = 0;
};

struct Parts {
    char pad0[0x38];
    Obj1* a;
    char pad1[0x54 - 0x3c];
    Obj2* b;
};

struct Mod {
    char pad[0xd8];
    Parts* parts;
};

extern "C" int fn_27_186828(void*, Mod* m) {
    int var = 0;
    if (m->parts->a->s45() == 0) {
        if (m->parts->b->s50(0) == 1U) {
            if (m->parts->b->s51(0) == 0) {
                var = 1;
            }
        } else {
            var = 1;
        }
    }
    return var == 1;
}
