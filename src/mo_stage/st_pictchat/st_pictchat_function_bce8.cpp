#pragma force_active on

extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, bool b, int c, int d);

class MyClass {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int size();
    virtual bool isEmpty();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual int capacity();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual void w();
    virtual void x();
    virtual int getTopIndex();
    virtual void y();
    virtual void setSize(int);
};

extern "C" void fn_73_BCE8(MyClass* self) {
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, self->isEmpty(), self->capacity(), self->getTopIndex());
    int sz = self->size();
    self->setSize(sz - 1);
}
