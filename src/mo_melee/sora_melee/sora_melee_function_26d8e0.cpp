#include <types.h>
#pragma force_active on

extern "C" {
extern u32 lbl_27_data_56728;
extern u32 lbl_27_data_5672C;
}

class fnObj {
public:
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf11(void* p);
    u32 m_4;
};

extern "C" void fn_27_26D8E0(fnObj* obj) {
    obj->vf11(&lbl_27_data_56728);
    obj->m_4 = lbl_27_data_5672C;
}
