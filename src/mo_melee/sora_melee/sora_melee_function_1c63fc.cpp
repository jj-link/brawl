#pragma force_active on
class VBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

extern "C" void fn_27_1C63FC(char* self) {
    VBase* p = (VBase*)(self + 0x10);
    p->f1();
}
