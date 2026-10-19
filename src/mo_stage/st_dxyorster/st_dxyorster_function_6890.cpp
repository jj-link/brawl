#pragma force_active on
struct Skip {
    unsigned int a, b;
    Skip& operator=(const Skip&) { return *this; }
};

struct Pair {
    unsigned int a, b;
    Pair& operator=(const Pair& p) { a = p.a; b = p.b; return *this; }
};

struct Tail {
    Pair pairs[6];
};

struct Element {
    unsigned int first[10];
    Skip skipped;
    unsigned int middle[1];
    Tail tail;
    unsigned char last[2];
};

class Array {
public:
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual int size();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual int capacity();
    virtual bool isFull();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual Element* at(int);
    virtual int topIndex();
    virtual int lastIndex();
    virtual void setSize(int);
};

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, int, bool, int, int, int, int);

extern "C" void fn_76_6890(Array* self, int index, const Element* value) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        (char*)self + 4, index, self->isFull(), self->size(),
        self->capacity(), self->topIndex(), self->lastIndex());
    *self->at(pos) = *value;
    self->setSize(self->size() + 1);
}
