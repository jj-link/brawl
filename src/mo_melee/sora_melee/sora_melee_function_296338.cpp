extern "C" void shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(void* a, int b, int c, int d);

class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual int v4();
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
    virtual int v27();
    virtual void v28();
    virtual void v29(int x);
};

#pragma force_active on
extern "C" void fn_27_296338(Node* self) {
    int a;
    int b;
    int c;
    b = self->v27();
    a = self->v13();
    c = self->v4();
    shift__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((char*)self + 4, c, a, b);
    self->v29(self->v3() - 1);
}
