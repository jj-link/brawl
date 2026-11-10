#include <types.h>
#include <gr/gr_gimmick.h>
#pragma force_active on

extern "C" {
extern const float lbl_74_rodata_138;
extern const float lbl_74_rodata_158;
void fn_27_26399C(void*);
}

struct GimmickLimits {
    char pad[0x30];
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;
    float f44;
};

struct GroundVtBase {
    char pad[0x3c];
};

class GroundVt : public GroundVtBase {
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
    virtual void fn_74_A7C4();
    virtual void fn_74_A8A8();
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
    virtual void fn_74_2F84();
    virtual void startup();
    virtual void fn_74_B1D4();
    virtual void fn_74_EFC();
    virtual GimmickLimits* fn_74_2F7C();
};

extern "C" void fn_74_B238(grGimmick* self, void* unused, Vec3f* p) {
    GroundVt* g = reinterpret_cast<GroundVt*>(self);
    GimmickLimits* lim = g->fn_74_2F7C();
    if (lim != 0) {
        float f31 = p->m_y;
        fn_27_26399C(*(void**)((char*)self + 0x14c));
        if (lbl_74_rodata_138 != f31) {
            Vec3f cur;
            Vec3f rot = self->getRot();
            cur.m_x = rot.m_x;
            cur.m_y = rot.m_y;
            cur.m_z = rot.m_z;
            float var = lbl_74_rodata_138;
            if (f31 < lim->f30) {
                if (*((u8*)self + 0x1e0) == 1) {
                    var = var + lim->f38;
                } else {
                    var = var - lim->f38;
                }
            } else if (f31 >= lim->f34) {
                var = var + lbl_74_rodata_158 * lim->f38;
            }
            cur.m_z = cur.m_z + var;
            self->setRot(cur.m_x, cur.m_y, cur.m_z);
            if (cur.m_z < lim->f40) {
                *((u8*)self + 0x1e0) = 1;
            }
            if (cur.m_z > lim->f3c) {
                *((u8*)self + 0x1e0) = 0;
            }
            *(float*)((char*)self + 0x1dc) = lim->f44;
        }
    }
}
