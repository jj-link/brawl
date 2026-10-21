#pragma force_active on

class soArrayVectorCalcInterface;

namespace soArrayVectorCalculator {
    void pop(soArrayVectorCalcInterface& interface, bool isEmpty, long capacity, long lastIndex);
}

class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual bool v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual int v28();
    virtual void v29(int);
};

extern "C" void fn_103_F974(VObj* self) {
    int capacity;
    int lastIndex;
    lastIndex = self->v28();
    capacity = self->v13();
    bool isEmpty = self->v4();
    soArrayVectorCalculator::pop(*(soArrayVectorCalcInterface*)((char*)self + 4), isEmpty, capacity, lastIndex);
    int size = self->v3();
    self->v29(size - 1);
}
