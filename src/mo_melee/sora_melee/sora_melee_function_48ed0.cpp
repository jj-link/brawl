#include <types.h>
#pragma force_active on

extern "C" void fn_27_36354(void*);

class soWork {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();

    u8 m_pad04[0x34 - 4];
    s32 m_34;
    u8 m_pad38[0x52 - 0x38];
    u8 m_52;
};

extern "C" {
void fn_27_48ED0(soWork* p) {
    if (p->m_52 == 0) {
        p->v5();
    } else {
        fn_27_36354((char*)p + 0x28);
    }
    p->m_34 = -1;
}
}
