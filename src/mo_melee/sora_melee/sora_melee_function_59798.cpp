#include <math.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_730;

class soControllerModuleImpl {
public:
    virtual ~soControllerModuleImpl() { }
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
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual double getStickValue();
    bool isStickSide();
};

bool soControllerModuleImpl::isStickSide() {
    float v = fabs(getStickValue());
    return v < lbl_27_rodata_730;
}
