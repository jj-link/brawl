#pragma force_active on
class soBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

extern "C" soBase* fn_27_2258E8(int);

extern "C" void fn_27_221A24(int arg) {
    soBase* p = fn_27_2258E8(arg);
    if (p == 0) {
        p = fn_27_2258E8(0x40);
    }
    p->v1();
}
