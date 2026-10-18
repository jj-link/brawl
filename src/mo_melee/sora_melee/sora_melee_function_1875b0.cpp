#include <types.h>
#pragma force_active on

class fn27Base {
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
    virtual void vf14();
    virtual u32 vf15(void* p);
    virtual void vf16();
    virtual u32 vf17(void* p);
};

struct fn27Obj {
    u8 pad_0000[0xD8];
    void* m_d8;
};

struct fn27Mid {
    u8 pad_0000[0x40];
    fn27Base* m_40;
};

extern "C" u32 fn_27_1875B0(void* p1, void* p2) {
    fn27Obj* obj = (fn27Obj*)p2;
    fn27Mid* mid = (fn27Mid*)obj->m_d8;
    fn27Base* target = mid->m_40;
    return target->vf15(p2);
}
