#pragma force_active on
class soBaseVirt {
public:
    virtual ~soBaseVirt();
    virtual void f0();
    virtual void f1();
    virtual bool f2();
};

extern "C" {
bool fn_27_CC4E0(soBaseVirt* p) {
    return !p->f2();
}
}
