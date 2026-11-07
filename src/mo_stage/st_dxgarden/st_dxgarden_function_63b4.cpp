#include <gr/gr_gimmick.h>
#include <ai/ai_mgr.h>
#pragma force_active on

struct GardenData {
    float x;
    char pad[8];
    float a;
    float b;
};

struct GardenObject {
    char pad[0x150];
    unsigned char state;
    char pad2[7];
    GardenData* data;
    snd3DGenerator sound;
    int danger;
};

inline void setVec2f(Vec2f* vec, float x, float y) {
    vec->m_x = x;
    vec->m_y = y;
}

extern "C" void fn_77_63B4(grGimmick* self, float delta) {
    GardenObject* obj = (GardenObject*)self;

    self->grGimmick::update(delta);

    switch (obj->state) {
    case 0: {
        g_ecMgr->setDrawPrio(1);
        g_ecMgr->setParent(g_ecMgr->setEffect((EfID)0x5c0003), *self->m_sceneModels, "null364", false);
        g_ecMgr->setParent(g_ecMgr->setEffect((EfID)0x5c0003), *self->m_sceneModels, "null365", false);
        g_ecMgr->setParent(g_ecMgr->setEffect((EfID)0x5c0003), *self->m_sceneModels, "ptcp", false);
        g_ecMgr->setParent(g_ecMgr->setEffect((EfID)0x5c0003), *self->m_sceneModels, "ptcp1", false);
        g_ecMgr->setParent(g_ecMgr->setEffect((EfID)0x5c0003), *self->m_sceneModels, "ptcp2", false);
        g_ecMgr->setParent(g_ecMgr->setEffect((EfID)0x5c0003), *self->m_sceneModels, "ptcp3", false);
        g_ecMgr->setDrawPrio(-1);

        Vec3f pos;
        self->getNodePosition(&pos, 0, "ptcp");
        obj->sound.playSE((SndID)0x1da3, 0, 0, -1);
        obj->sound.setPos(&pos);
        obj->state = 1;
        break;
    }
    case 1: {
        Vec3f pos;
        self->getNodePosition(&pos, 0, "ptcp");

        Vec2f second;
        Vec2f first(obj->data->x, pos.m_y);
        setVec2f(&second, obj->data->a, obj->data->b);
        obj->danger = g_aiMgr->setDangerZone(&first, &second, obj->danger, false, false);
        break;
    }
    }
}
