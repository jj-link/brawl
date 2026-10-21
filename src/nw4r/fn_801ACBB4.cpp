#pragma force_active on

class Base {
public:
    virtual void v0();
    virtual void target(int a, int b, int c);
};

extern "C" void fn_801ACBB4(Base* p) {
    p->target(2, 0, 0);
}
