#pragma force_active on

struct ArgData {
    int type;
    unsigned long data;
};

struct Arg {
    const ArgData* p;
    unsigned char null;
    Arg(const ArgData* q) : p(q), null(0) {}
};

class List {
public:
    virtual void v0();
    virtual void v1();
    virtual const ArgData* at(int) const;
    virtual int size() const;
    char data[12];
    Arg get(int i) const { Arg a(at(i)); return a; }
};

struct Pad4 {
    int a;
};

class Iface {
public:
    virtual void v0();
};

class Self : public Pad4, public Iface {
public:
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void v15(int, int);
    virtual void v16();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual int v25(signed char);
};

class Cmd {
public:
    virtual void a0();
    virtual signed char a3();
    virtual signed char a4();
    virtual void a5();
    virtual void a6();
    virtual List a7();
};

extern "C" int fn_27_5C3B0(Self* self, Cmd* cmd) {
    if (self->v25(cmd->a3()) == 0) return 0;

    if (cmd->a4() <= -1 || cmd->a4() >= 2) return 0;

    switch (cmd->a4()) {
    case 0: {
        List sp = cmd->a7();
        Arg a0 = sp.get(0);
        int v31 = (a0.null == 1) ? 0 : a0.p->data;
        Arg a1 = sp.get(1);
        int v5 = (a1.null == 1) ? 0 : a1.p->data;
        self->v15(v31, v5);
        return 1;
    }
    case 1:
        self->v16();
        return 1;
    default:
        return 0;
    }
}