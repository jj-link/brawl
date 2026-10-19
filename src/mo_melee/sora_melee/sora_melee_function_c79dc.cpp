#include <types.h>
#pragma force_active on

class soIndexList {
public:
    virtual void vf0();
    virtual s32* vf1(s32 index);

    soIndexList* m_04;
    s32* m_08;
    s32 m_0C;
};

extern "C" s32* fn_27_C79DC(soIndexList* self, s32 index) {
    if (index >= self->m_0C) {
        soIndexList* child = self->m_04;
        if (child != 0) {
            return child->vf1(index - self->m_0C);
        }
    }
    return self->m_08 + index;
}
