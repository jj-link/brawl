#include <types.h>
#pragma force_active on

extern "C" void fn_27_36354(void*);

class soSoraObj {
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
    u8 pad0[0x38 - 4];
    u8 pad1[0x44 - 0x38];
    s32 m44;
    u8 pad2[0x66 - 0x48];
    u16 m66;
};

extern "C" void fn_27_43184(soSoraObj* p) {
    if (!((p->m66 >> 13) & 1)) {
        p->vf7();
    } else {
        fn_27_36354((char*)p + 0x38);
    }
    p->m44 = -1;
}
