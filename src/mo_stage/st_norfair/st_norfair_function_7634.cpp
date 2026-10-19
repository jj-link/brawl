#pragma force_active on
struct soArrayVectorCalcInterface {
    int m_dummy;
};

class soArrayVectorCalculator {
public:
    static void clear(soArrayVectorCalcInterface& iface);
};

class soArrayOwner {
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
    virtual void vfunc31(int arg);

    soArrayVectorCalcInterface m_iface;
};

extern "C" void fn_54_7634(soArrayOwner* self) {
    soArrayVectorCalculator::clear(self->m_iface);
    self->vfunc31(0);
}
