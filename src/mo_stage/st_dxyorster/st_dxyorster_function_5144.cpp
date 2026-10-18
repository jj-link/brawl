#pragma force_active on
struct Entry {
    int a;
    short b, c;
    float d, e;
    int f;
    float g, h;
    int i, j, k, l, m;
    unsigned char n, o, p, q, r;
};

struct Vector {
    virtual int pad8();
    virtual int pad12();
    virtual int pad16();
    virtual int size();
    virtual int pad24();
    virtual int pad28();
    virtual int pad32();
    virtual int pad36();
    virtual int pad40();
    virtual int pad44();
    virtual int pad48();
    virtual int pad52();
    virtual int pad56();
    virtual int get3c();
    virtual bool get40();
    virtual int pad68();
    virtual int pad72();
    virtual int pad76();
    virtual int pad80();
    virtual int pad84();
    virtual int pad88();
    virtual int pad92();
    virtual int pad96();
    virtual int pad100();
    virtual int pad104();
    virtual int pad108();
    virtual Entry* at(int);
    virtual int get74();
    virtual int get78();
    virtual void setSize(int);

    int calc;
};

extern "C" int push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
    void*, bool, int, int, int);

extern "C" void fn_76_5144(Vector* self, const Entry* value) {
    int index = push__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfaceblll(
        &self->calc, self->get40(), self->get3c(), self->get74(), self->get78());

    Entry* out = self->at(index);
    out->a = value->a;
    out->b = value->b;
    out->c = value->c;
    out->d = value->d;
    out->e = value->e;
    out->f = value->f;
    out->g = value->g;
    out->h = value->h;
    out->i = value->i;
    out->j = value->j;
    out->k = value->k;
    out->l = value->l;
    out->m = value->m;
    out->n = value->n;
    out->o = value->o;
    out->p = value->p;
    out->q = value->q;
    out->r = value->r;

    int size = self->size();
    self->setSize(size + 1);
}
