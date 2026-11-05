#include <ai/ai_mgr.h>
#pragma force_active on

struct Norfair {
    char pad0[0x150];
    unsigned char state;
    char pad151[0xB];
    Vec3f* positions;
    float* bounds;
    unsigned char* index;
    char pad168[0xB0];
    int danger1;
    int danger2;
    int danger3;
    int danger4;
};

extern "C" {
extern const float lbl_54_rodata_C8[];
void fn_27_1F299C(aiMgr*, int);
}

extern "C" void fn_54_BB48(Norfair* self) {
    const float* constants = lbl_54_rodata_C8;
    Vec2f second;
    Vec2f first;
    switch (self->state) {
    case 7:
        first.m_x = self->bounds[0];
        first.m_y = self->bounds[1];
        second.m_x = self->bounds[3];
        second.m_y = constants[9] + self->positions[*self->index].m_y;
        self->danger1 = g_aiMgr->setDangerZone(&first, &second, self->danger1, false, false);
        first.m_x = self->bounds[0];
        first.m_y = self->bounds[1];
        second.m_x = self->positions[*self->index].m_x - constants[10];
        second.m_y = self->bounds[4];
        self->danger2 = g_aiMgr->setDangerZone(&first, &second, self->danger2, false, false);
        first.m_x = constants[10] + self->positions[*self->index].m_x;
        first.m_y = self->bounds[1];
        second.m_x = self->bounds[3];
        second.m_y = self->bounds[4];
        self->danger3 = g_aiMgr->setDangerZone(&first, &second, self->danger3, false, false);
        first.m_x = self->bounds[0];
        first.m_y = self->positions[*self->index].m_y - constants[2];
        second.m_x = self->bounds[3];
        second.m_y = self->bounds[4];
        self->danger4 = g_aiMgr->setDangerZone(&first, &second, self->danger4, false, false);
        break;
    default:
        if (self->danger1 != -1) fn_27_1F299C(g_aiMgr, self->danger1);
        if (self->danger2 != -1) fn_27_1F299C(g_aiMgr, self->danger2);
        if (self->danger3 != -1) fn_27_1F299C(g_aiMgr, self->danger3);
        if (self->danger4 != -1) fn_27_1F299C(g_aiMgr, self->danger4);
        self->danger1 = -1;
        self->danger2 = -1;
        self->danger3 = -1;
        self->danger4 = -1;
        break;
    }
}
