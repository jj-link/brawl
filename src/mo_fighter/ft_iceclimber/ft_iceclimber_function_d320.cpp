#pragma force_active on
class IFtBase {
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
    virtual int vf14(int arg);
    virtual void vf15();
    virtual int vf16(int arg);
};

extern "C" IFtBase* fn_27_8CE34(void* p);

extern "C" int fn_105_D320(void*, void* p) {
    IFtBase* obj = fn_27_8CE34(p);
    if (obj->vf14(0) == 0) {
        return -1;
    }
    return obj->vf16(0);
}
