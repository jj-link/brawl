#pragma force_active on
#include <types.h>
#include <em/em_manager.h>
#include <so/so_external_value_accesser.h>
#include <so/stageobject.h>

extern "C" void* fn_41_CECC(void* mgr, void* task);
extern "C" u32 fn_27_8CC2C(StageObject* object, u32 value);

struct EmSelf {
    void* unk0;
    char pad4[2];
    u16 unk6;
    s32 unk8;
    Vec3f pos;
    Vec2f delta;
    f32 unk20;
};

extern "C" void fn_27_21CA50(EmSelf* self) {
    StageObject* obj = (StageObject*)fn_41_CECC(emManager::getInstance(), self->unk0);
    self->unk6 = 1;
    self->unk8 = soExternalValueAccesser::getStatusKind(obj);
    if (soExternalValueAccesser::getSituationKind(obj) != 5) {
        Vec2f old = *self->pos.xy();
        self->pos = soExternalValueAccesser::getPos(obj);
        old.m_x = self->pos.m_x - old.m_x;
        old.m_y = self->pos.m_y - old.m_y;
        self->delta = old;
    }
    self->unk20 = soExternalValueAccesser::getLr(obj);
    if (fn_27_8CC2C(obj, 8) == 1) {
        self->unk6 |= 2;
    }
}
