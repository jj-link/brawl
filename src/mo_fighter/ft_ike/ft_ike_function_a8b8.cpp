#pragma force_active on
class IkeSubobject {
public:
    virtual void* vf0();
    virtual void* vf1();
    virtual void* vf2();
};

extern "C" void* fn_119_A8B8(char* self) {
    IkeSubobject* sub = reinterpret_cast<IkeSubobject*>(self + 0xA5CC);
    return sub->vf2();
}
