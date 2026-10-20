#include <so/ground/so_ground_module_impl.h>
#pragma force_active on

extern const float lbl_27_rodata_3C4;
extern const float lbl_27_rodata_3C0;

extern "C" Vec2f fn_27_27E70(soGroundModuleImpl* self, unsigned int index) {
    Vec2f result;
    result.m_x = lbl_27_rodata_3C4;
    result.m_y = lbl_27_rodata_3C0;

    if (self->isAttach(0) == 1) {
        unsigned char flags =
            *((unsigned char*)self->m_groundShapeArray->at(index).m_collStatus + 0x6d);

        if (flags & 8) {
            result = self->getTouchNormal(8, 0);
        } else if (flags & 1) {
            result = self->getTouchNormal(1, 0);
        } else if (flags & 2) {
            result = self->getTouchNormal(2, 0);
        } else {
            result = self->getTouchNormal(4, 0);
        }
    }

    return result;
}
