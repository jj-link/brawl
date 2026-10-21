#pragma force_active on
typedef int s32;

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* self, void* iface, s32 b, s32 l);

class Obj {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual s32 g3();
    virtual void* g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual s32 g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void g19();
    virtual void g20();
    virtual void g21();
    virtual void g22();
    virtual void g23();
    virtual void g24();
    virtual void g25();
    virtual void g26();
    virtual s32 g27();
    virtual void g28();
    virtual void g29(s32 n);
};

extern "C" void fn_70_A32C(Obj* self) {
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, self->g4(), self->g13(), self->g27());
    self->g29(self->g3() - 1);
}
