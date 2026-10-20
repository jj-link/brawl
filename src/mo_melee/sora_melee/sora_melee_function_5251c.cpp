#pragma force_active on
class Sec {
public:
    virtual ~Sec();
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
};

class Prim {
public:
    virtual void f0();
    int pad4;
};

class Outer : public Prim, public Sec {
public:
    virtual void g2();
};

extern "C" void fn_27_5251C(Outer& self) {
    ((Sec&)self).g2();
}
