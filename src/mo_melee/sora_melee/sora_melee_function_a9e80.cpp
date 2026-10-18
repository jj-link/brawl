#pragma force_active on
struct Value {
    int tag;
    int value;
};

struct Ref {
    Value* p;
    bool flag;

    Ref(Value* q) : p(q), flag(false) {}

    int get() const {
        return flag == 1 ? 0 : p->value;
    }
};

inline int getValue(Ref ref) {
    return ref.get();
}

struct Args {
    Args() {}

    Args(const Args& x) {
        for (int i = 0; i < 3; i++)
            data[i] = x.data[i];
    }

    virtual void a();
    virtual void b();
    virtual Value* at(int);

    int data[3];
};

inline Ref getArg(Args& a) {
    return Ref(a.at(0));
}

struct Input {
    virtual void a();
    virtual signed char kind();
    virtual signed char mode();
    virtual int count();
    virtual void b();
    virtual Args args();
};

struct Output {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void set(int);
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual int valid(signed char);
};

extern "C" int fn_27_A9E80(Output* self, Input* in) {
    if (!self->valid(in->kind()))
        return 0;

    signed char mode = in->mode();
    int count = in->count();

    if (mode <= -1 || mode >= 1)
        return 0;

    switch (mode) {
    case 0: {
        Args args = in->args();
        if (count == 0) {
            self->set(-2);
        } else {
            self->set(getValue(getArg(args)));
        }
        return 1;
    }
    }

    return 0;
}
