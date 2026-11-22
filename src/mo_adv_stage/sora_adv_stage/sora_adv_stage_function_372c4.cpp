#include <types.h>
#include <gr/gr_gimmick.h>
#include <gf/gf_model.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" void startup__9grGimmickFP9gfArchiveUlUl(void*, gfArchive*, u32, u32);
extern "C" const float lbl_40_rodata_728;

struct LocalStageData {
    float x, y, z;
    char pad[0xc];
    int sound0;
    int unk1c;
    int sound1;
};

struct LocalStageObject {
    char pad0[0x44];
    nw4r::g3d::ScnMdl** model;
    gfModelAnimation** anim;
    char pad4c[0x5c];
    grGimmick::Effect_Info* sound;
    char padac[0x10];
    LocalStageData* data0;
    char padc0[0x98];
    LocalStageData* data;

    void setSound(int index, int id, Vec2f& input, Vec2f& offset) {
        input.m_x = lbl_40_rodata_728;
        input.m_y = lbl_40_rodata_728;
        Vec2f::copy(offset, input);
        if (id > 0) {
            sound[index].m_id = id;
            sound[index].m_repeatFrame = 0;
            sound[index].m_nodeIndex = 0;
            sound[index].m_endFrame = 0;
            sound[index].m_offsetPos = offset;
        }
    }
};

extern "C" void fn_40_372C4(LocalStageObject* self, gfArchive* archive, u32 a, u32 b) {
    startup__9grGimmickFP9gfArchiveUlUl(self, archive, a, b);
    self->data = self->data0;
    if (self->anim) {
        (*self->anim)->unbindNodeAnim(*self->model);
    }
    grGimmick* gimmick = (grGimmick*)self;
    gimmick->makeCalcuCallback(1, (HeapType)15);
    gimmick->setCalcuCallbackRoot(3);
    LocalStageData* d = self->data;
    Vec3f pos;
    pos = Vec3f(d->x, d->y, lbl_40_rodata_728);
    Vec3f rot;
    rot = Vec3f(lbl_40_rodata_728, lbl_40_rodata_728, self->data->z);
    gimmick->setPos(&pos);
    gimmick->setRot(&rot);
    gimmick->grGimmick::updateCallback(0);
    gimmick->createIsValidTrigger((stTriggerData*)((char*)self->data + 0x28));
    gimmick->createSoundWork(2, 1);
    Vec2f offset0, input0;
    self->setSound(0, self->data->sound0, input0, offset0);
    Vec2f input1, offset1;
    input1.m_x = lbl_40_rodata_728;
    input1.m_y = lbl_40_rodata_728;
    Vec2f::copy(offset1, input1);
    int id = self->data->sound1;
    if (id > 0) {
        self->sound[1].m_id = id;
        self->sound[1].m_repeatFrame = 0;
        self->sound[1].m_nodeIndex = 0;
        self->sound[1].m_endFrame = 0;
        self->sound[1].m_offsetPos = offset1;
    }
}
