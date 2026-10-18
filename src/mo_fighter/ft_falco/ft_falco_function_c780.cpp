#pragma force_active on
class FtEmbeddedBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

extern "C" void fn_108_C780(void* object) {
    FtEmbeddedBase* p = reinterpret_cast<FtEmbeddedBase*>(static_cast<char*>(object) + 0x1CAE0);
    p->vf2();
}
