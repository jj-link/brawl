#include <gr/ground.h>
#include <ai/ai_mgr.h>
#pragma force_active on

extern char lbl_73_data_1130[];
extern char lbl_73_data_1140[];
extern float lbl_73_rodata_B0;
extern float lbl_73_rodata_B4;

inline void setVec(Vec2f& v, float x, float y) { v.m_x = x; v.m_y = y; }

class PictGround : public Ground {
public:
    char pad[0x294 - 0x9c];
    int danger1;
    int danger2;
};

extern "C" void fn_73_5724(PictGround* self) {
    self->setEnableCollisionStatus(false);
    if (self->danger1 == -1 || self->danger2 == -1) {
        Vec3f pos;
        Vec2f bottomRight;
        Vec2f topLeft;
        self->getNodePosition(&pos, 0, lbl_73_data_1130);
        setVec(topLeft, pos.m_x - lbl_73_rodata_B4, lbl_73_rodata_B0 + pos.m_y);
        setVec(bottomRight, lbl_73_rodata_B4 + pos.m_x, pos.m_y - lbl_73_rodata_B0);
        self->danger1 = g_aiMgr->setDangerZone(&topLeft, &bottomRight, self->danger1, false, false);
        self->getNodePosition(&pos, 0, lbl_73_data_1140);
        setVec(topLeft, pos.m_x - lbl_73_rodata_B4, lbl_73_rodata_B0 + pos.m_y);
        setVec(bottomRight, lbl_73_rodata_B4 + pos.m_x, pos.m_y - lbl_73_rodata_B0);
        self->danger2 = g_aiMgr->setDangerZone(&topLeft, &bottomRight, self->danger2, false, false);
    }
}