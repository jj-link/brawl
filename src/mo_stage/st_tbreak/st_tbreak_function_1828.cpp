#include <gr/gr_gimmick.h>
#include <snd/snd_system.h>
#pragma force_active on

extern "C" const float lbl_89_rodata_64;

struct TBreakGround : grGimmick {
    char padding[0xC];
    unsigned char state;
    float frame;
};

extern "C" void fn_89_1828(TBreakGround* self) {
    self->m_modelAnims[0]->unbindShapeAnim(self->m_sceneModels[0]);
    self->changeNodeAnim(0, 0);
    self->changeShapeAnim(0, 0);
    g_sndSystem->playSE((SndID)0x1EE0, -1, 0, 0, -1);
    self->state = 2;
    self->frame = lbl_89_rodata_64;
}
