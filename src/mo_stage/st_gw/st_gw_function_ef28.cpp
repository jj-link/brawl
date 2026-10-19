#pragma force_active on
class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc31(int);

    void clear(soArrayVectorCalcInterface& iface);
};

extern "C" void fn_63_EF28(soArrayVectorCalculator* self, soArrayVectorCalcInterface& iface) {
    reinterpret_cast<soArrayVectorCalculator*>((char*)self + 4)->clear(iface);
    self->vfunc31(0);
}
