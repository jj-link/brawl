#pragma force_active on
class FtVirtBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
};

extern "C" void fn_113_E020(void* object) {
    static_cast<FtVirtBase*>(static_cast<void*>(static_cast<char*>(object) + 0x1F768))->vfunc2();
}
