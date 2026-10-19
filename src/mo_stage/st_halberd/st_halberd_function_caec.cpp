#pragma force_active on
struct Item {
    int a;
    int b;
};

class Array {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int size() const;
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual int capacity() const;
    virtual bool isFull() const;
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual Item* at(int);
    virtual int getTopIndex() const;
    virtual int getLastIndex() const;
    virtual void setSize(int);
    int calc;
};

extern "C" int push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    void*, bool, int, int, int);

extern "C" void fn_57_CAEC(Array* self, const Item* src) {
    int index = push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        &self->calc, self->isFull(), self->capacity(), self->getTopIndex(), self->getLastIndex());
    *self->at(index) = *src;
    self->setSize(self->size() + 1);
}
