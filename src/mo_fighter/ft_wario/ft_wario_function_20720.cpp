#pragma force_active on
class VBase {
public:
    virtual void* f0();
    virtual void* f1();
    virtual void* f2();
    virtual void* f3();
    virtual void* f4();
};

extern "C" void* fn_110_20720(void* self) {
    VBase* obj = reinterpret_cast<VBase*>(static_cast<char*>(self) + 0xACA0);
    return obj->f2();
}
