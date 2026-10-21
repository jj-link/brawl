#pragma force_active on

class Interface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* f3();
};

extern "C" char* fn_8019D814(Interface* arg0) {
    return arg0->f3() + 4;
}
