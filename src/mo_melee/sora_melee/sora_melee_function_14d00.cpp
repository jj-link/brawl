#include <so/motion/so_motion_module_impl.h>
#pragma force_active on

extern "C" float fn_27_14D00(soMotionModuleImpl* self) {
    return self->m_mainAnim.getEndFrame(*(nw4r::g3d::AnmObjChrRes**)&self->m_mainAnim);
}
