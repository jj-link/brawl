#pragma force_active on
extern "C" void* fn_96_1D7E4(void* owner);

class VBase {
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
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf16(void* a, void* b, void* c, void* d);
};

extern "C" void fn_96_1DD1C(void* owner, void* a, void* b, void* c) {
    VBase* obj = (VBase*)fn_96_1D7E4(owner);
    if (obj != 0) {
        obj->vf16(a, b, c, *(void**)((char*)owner + 8));
    }
}
