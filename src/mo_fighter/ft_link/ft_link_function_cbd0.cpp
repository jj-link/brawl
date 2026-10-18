#pragma force_active on
class ThunkBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

extern "C" void fn_93_CBD0(void* object) {
    ThunkBase* base = reinterpret_cast<ThunkBase*>(static_cast<char*>(object) + 0x19DAC);
    base->f2();
}
