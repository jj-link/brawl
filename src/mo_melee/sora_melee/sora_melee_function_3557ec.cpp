#pragma force_active on
class stVirtualIface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual float vf9();
};

extern "C" float fn_27_3557EC(void* self, char* r4) {
    stVirtualIface* obj = *(stVirtualIface**)(*(char**)(r4 + 0xd8) + 0xc);
    return -obj->vf9();
}
