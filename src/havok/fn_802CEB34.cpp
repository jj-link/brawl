#pragma force_active on
class MyClass {
public:
    virtual void vf0(int);
};

extern "C" void fn_802CEB34(MyClass* p) {
    p->vf0(-1);
}
