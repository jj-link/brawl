#pragma force_active on
typedef unsigned int u32;

struct Pair {
    u32 a;
    u32 b;
};

struct Base {
    virtual void s0() = 0;
    virtual void s1() = 0;
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
};

struct SlotA : Base {
    virtual Pair* get() = 0;
};

struct SlotB : Base {
    virtual Pair* get(u32 arg) = 0;
};

extern "C" void fn_73_CEB0(Base* self, void* unused, u32 arg) {
    SlotA* a = (SlotA*)self;
    Pair* src = a->get();
    SlotB* b = (SlotB*)self;
    Pair* dst = b->get(arg);
    dst->a = src->a;
    dst->b = src->b;
}
