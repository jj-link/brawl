#include <gr/gr_gimmick.h>
#include <snd/snd_system.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_4410;

struct grGimmickSpring : grGimmick {
    char padding[0xC];
    unsigned char state;
    float frame;
};

extern "C" void setMotionOff__15grGimmickSpringFv(grGimmickSpring* self) {
    self->m_modelAnims[0]->unbindShapeAnim(self->m_sceneModels[0]);
    self->changeNodeAnim(0, 0);
    self->changeShapeAnim(0, 0);
    g_sndSystem->playSE((SndID)0x226E, -1, 0, 0, -1);
    self->state = 2;
    self->frame = lbl_27_rodata_4410;
}
