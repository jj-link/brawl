#include <ai/ai_mgr.h>
#pragma force_active on
struct Ground_base { char pad[0x3c]; };
struct Bounds { float a, b, c, d, e; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_54_D0F4();
    virtual void fn_54_D190();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_54_338C();
    virtual void startup();
    virtual void setNode();
    virtual void fn_54_1310();
    virtual void fn_54_3150();
    virtual void fn_54_3388();
    virtual void fn_54_2C40();
    virtual void fn_54_3380();
    virtual void fn_54_3374();
    virtual void fn_54_3364();
    virtual void fn_54_3354();
    virtual void getNodeIndex();
    virtual void getNodePosition(Vec3f*, unsigned int, unsigned int);
    char pad40[0x84];
    unsigned int node;
    char padC8[0x94];
    Bounds* bounds;
    char pad160[0x18];
    unsigned char state;
    char pad179[0x9b];
    int danger;
};
extern "C" const float lbl_54_rodata_138[];
extern "C" void fn_54_D28C(Ground* self) {
    const float* c = lbl_54_rodata_138;
    Vec3f pos;
    Vec2f second;
    Vec2f first;
    self->getNodePosition(&pos, 0, self->node);
    switch ((int)self->state) {
    case 0:
        first.m_x = self->bounds->a;
        first.m_y = self->bounds->b;
        second.m_x = c[1] + pos.m_x;
        second.m_y = self->bounds->e;
        if (second.m_x > c[2])
            second.m_x = c[2];
        if (first.m_x > second.m_x)
            second.m_x = first.m_x;
        break;
    case 1:
        first.m_x = pos.m_x - c[1];
        first.m_y = self->bounds->b;
        second.m_x = self->bounds->d;
        second.m_y = self->bounds->e;
        if (first.m_x < c[3])
            first.m_x = c[3];
        if (first.m_x > second.m_x)
            first.m_x = second.m_x;
        break;
    }
    self->danger = g_aiMgr->setDangerZone(&first, &second, self->danger, false, false);
}