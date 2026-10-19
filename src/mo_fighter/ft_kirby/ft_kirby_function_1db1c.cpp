#pragma force_active on
extern "C" void* fn_96_1D7E4(void* owner);

class VBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(float f, void* a, void* b);
};

extern "C" void fn_96_1DB1C(void* owner, float f, void* a, void* b) {
    VBase* obj = (VBase*)fn_96_1D7E4(owner);
    if (obj != 0) {
        obj->v15(f, a, b);
    }
}
