#pragma force_active on
class VBase {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};

extern "C" void fn_102_A1BC(char* self) {
    VBase* obj = (VBase*)(self + 0x13bd0);
    obj->c();
}
