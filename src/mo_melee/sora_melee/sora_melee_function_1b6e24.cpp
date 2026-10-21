#include <types.h>
#pragma force_active on

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, s32 b, s32 c, s32 d);

class Foo {
public:
    virtual void g0() = 0;
    virtual void g1() = 0;
    virtual void g2() = 0;
    virtual s32 g3() = 0;
    virtual s32 g4() = 0;
    virtual void g5() = 0;
    virtual void g6() = 0;
    virtual void g7() = 0;
    virtual void g8() = 0;
    virtual void g9() = 0;
    virtual void g10() = 0;
    virtual void g11() = 0;
    virtual void g12() = 0;
    virtual s32 g13() = 0;
    virtual void g14() = 0;
    virtual void g15() = 0;
    virtual void g16() = 0;
    virtual void g17() = 0;
    virtual void g18() = 0;
    virtual void g19() = 0;
    virtual void g20() = 0;
    virtual void g21() = 0;
    virtual void g22() = 0;
    virtual void g23() = 0;
    virtual void g24() = 0;
    virtual void g25() = 0;
    virtual void g26() = 0;
    virtual s32 g27() = 0;
    virtual void g28() = 0;
    virtual void g29(s32) = 0;
};

extern "C" void fn_27_1B6E24(Foo* self) {
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (char*)self + 4,
        self->g4(),
        self->g13(),
        self->g27()
    );
    self->g29(self->g3() - 1);
}
