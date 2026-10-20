#pragma force_active on
class fnBase {
public:
    virtual void f0();
    virtual void f1();
};

extern "C" {
void fn_27_8753C(fnBase* p) {
    return p->f1();
}
}
