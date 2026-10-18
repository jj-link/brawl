#pragma force_active on
class ThunkObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

extern "C" void fn_105_F478(ThunkObj* self) {
    ThunkObj* p = reinterpret_cast<ThunkObj*>(reinterpret_cast<char*>(self) + 0x1F89C);
    p->f2();
}
