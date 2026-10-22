#include <types.h>
#pragma force_active on

struct SoChild {
    virtual void v0();
    virtual void* vf3(int index);
    virtual void vf4();
    virtual int vf5();
};

#define VPAD(n) virtual void v##n() = 0;
struct SoOwner {
    VPAD(1) VPAD(2) VPAD(3) VPAD(4) VPAD(5) VPAD(6) VPAD(7) VPAD(8) VPAD(9) VPAD(10)
    VPAD(11) VPAD(12) VPAD(13) VPAD(14) VPAD(15) VPAD(16) VPAD(17) VPAD(18) VPAD(19) VPAD(20)
    VPAD(21) VPAD(22) VPAD(23) VPAD(24) VPAD(25) VPAD(26) VPAD(27) VPAD(28) VPAD(29) VPAD(30)
    VPAD(31) VPAD(32) VPAD(33) VPAD(34) VPAD(35) VPAD(36) VPAD(37) VPAD(38) VPAD(39) VPAD(40)
    VPAD(41) VPAD(42) VPAD(43) VPAD(44) VPAD(45) VPAD(46) VPAD(47) VPAD(48) VPAD(49) VPAD(50)
    VPAD(51) VPAD(52)
    virtual void vf53(int index, u32 a, u32 b) = 0;
    u8 pad0[0x40 - 0x4];
    SoChild* m_child;
    u8 pad1[0x54 - 0x44];
};

extern "C" void fn_27_BBA24(SoOwner* self, int type, u32 a, u32 b) {
    int count = self->m_child->vf5();
    for (int i = count - 1; i >= 0; i--) {
        void* obj = self->m_child->vf3(i);
        if (type == *(int*)obj) {
            self->vf53(i, a, b);
        }
    }
}
