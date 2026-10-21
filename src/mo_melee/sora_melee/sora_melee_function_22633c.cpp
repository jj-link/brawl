#include <types.h>
#pragma force_active on

namespace nw4r {
namespace g3d {
class G3dObj {
public:
    void Destroy();
};
} // namespace g3d
} // namespace nw4r

struct Fn27Sub {
    u32 unk;
};

struct Fn27Big {
    u32 unk;
};

struct Fn27Obj {
    Fn27Sub* m_ptr0;
    u8 m_type;
    u8 pad5[0x0c - 0x05];
    nw4r::g3d::G3dObj* m_obj0;
    nw4r::g3d::G3dObj* m_obj1;
    u8 pad14[0x50 - 0x14];
    Fn27Big* m_ptr50;
};

extern "C" {
Fn27Obj* fn_27_22633C(Fn27Obj* self, s32 flag) {
    if (self) {
        if (self->m_ptr50) {
            delete self->m_ptr50;
        }
        if (self->m_type == 1) {
            if (self->m_obj0) {
                self->m_obj0->Destroy();
            }
            if (self->m_obj1) {
                self->m_obj1->Destroy();
            }
        }
        if (self->m_ptr0) {
            delete self->m_ptr0;
        }
        if (flag > 0) {
            delete self;
        }
    }
    return self;
}
}
