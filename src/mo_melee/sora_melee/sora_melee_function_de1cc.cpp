#pragma force_active on

typedef signed int s32;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
    void*, s32, s32, s32);

class Obj {
public:
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual s32 get14();
    virtual s32 get18();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual s32 get3C();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual s32 get74();
    virtual void pad28();
    virtual void set7C(s32);
};

extern "C" void fn_27_DE1CC(Obj* self) {
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(
        (char*)self + 4, self->get18(), self->get3C(), self->get74());
    self->set7C(self->get14() - 1);
}
