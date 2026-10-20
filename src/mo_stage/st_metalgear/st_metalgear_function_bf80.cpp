#pragma force_active on
struct Element {
    int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18;
    float f0, f1, f2;
    int b0, b1, b2, b3, b4, b5;
    short s;
    char c0, c1, c2;
};

class Array {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int size();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int v3c();
    virtual bool v40();
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
    virtual Element* at(int);
    virtual int v74();
    virtual int v78();
    virtual void setSize(int);
};

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, int, bool, int, int, int, int);

extern "C" void fn_71_BF80(Array* self, int index, const Element* value) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        (char*)self + 4, index, self->v40(), self->size(),
        self->v3c(), self->v74(), self->v78());
    *self->at(pos) = *value;
    self->setSize(self->size() + 1);
}
