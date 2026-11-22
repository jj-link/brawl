#include <types.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual u32 slot0();
    virtual void slot1();
    virtual s32 slot2(s32 a, nw4r::g3d::G3dObj* b, s32 c);
    virtual u32 slot3(s32 a);
};

class Owner {
public:
    u8 pad[0x148];
    Object_vptr_0* m_ctrl;
};

extern "C" nw4r::g3d::G3dObj* fn_27_151A4(Owner* self, s32 a, s32 b, s32 c, s32* d, s32 e);

extern "C" void fn_27_1C4EC(Owner* self, s32 idx) {
    if (idx < 0 || self->m_ctrl->slot0() == 1) {
        return;
    }
    if (self->m_ctrl->slot3(idx) != 1) {
        s32 flag = 0;
        nw4r::g3d::G3dObj* obj = fn_27_151A4(self, idx, -1, 1, &flag, 1);
        if (obj != 0) {
            if (self->m_ctrl->slot2(idx, obj, flag) == 0) {
                obj->Destroy();
            }
        }
    }
}
