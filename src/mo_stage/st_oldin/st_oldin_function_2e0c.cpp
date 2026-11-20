#pragma force_active on
#pragma fp_contract off
#pragma peephole on

#include <types.h>
#include <mt/mt_prng.h>
#include <mt/mt_vector.h>
#include <gf/gf_model.h>
#include <cm/cm_quake.h>
#include <st/st_melee.h>
#include <ai/ai_mgr.h>
#include <ec/ec_mgr.h>
#include <snd/snd_3d_generator.h>
#include <revolution/OS/OSError.h>

namespace oldin {
struct GroundBase {
    char pad[0x3C];
};

class Ground : public GroundBase {
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
    virtual void fn_53_4258();
    virtual void update(float);
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned long);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_53_4308();
    virtual void startup();
    virtual void setNode();
    virtual void fn_53_1214();
    virtual void fn_53_4300();
    virtual void fn_53_42FC();
    virtual void fn_53_4250();
    virtual void fn_53_42F4();
    virtual void fn_53_42E8();
    virtual void fn_53_42D8();
    virtual void fn_53_42C8();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual bool getNodeMatrix(void*, unsigned long, unsigned long);

    char pad40[8];
    gfModelAnimation** animations;
    char pad4C[0x88];
    void* module;
};

union Flags {
    unsigned long word;
    struct {
        unsigned long mode : 3;
        unsigned long rest : 29;
    } bits;
};

struct Melee {
    char pad0[0x200];
    Ground* ground;
    char pad204[0xC];
    void* object210;
    char pad214[0x200];
    unsigned char active;
    char pad415[3];
    int stateValue;
    int state;
    float timer;
    int node;
    unsigned long effect;
    char pad42C[8];
    Flags flags;
    char pad438[0x78];
    unsigned char flag4B0;
    char pad4B1[3];
    int value4B4;
    int value4B8;
    char pad4BC[0x128];
    snd3DGenerator generator;
    int sound1;
    int sound2;
    unsigned char soundFlag;
};

inline void setState(int* valueOut, int* stateOut, int value, int state) {
    *valueOut = value;
    *stateOut = state;
}

inline void setTranslation(void* module, const Vec3f& position) {
    char* base = static_cast<char*>(module);
    *reinterpret_cast<float*>(base + 0x5C) = position.m_x;
    *reinterpret_cast<float*>(base + 0x6C) = position.m_y;
    *reinterpret_cast<float*>(base + 0x7C) = position.m_z;
}

inline void hideGround(Ground* ground, float y, float zero) {
    setTranslation(ground->module, Vec3f(zero, y, zero));
}

struct LocalData {
    Vec3f pos60;
    Vec3f pos90;
    Vec3f posC0;
    float matrix60[12];
    float matrix90[12];
    float matrixC0[12];
};

}

extern "C" {
extern const float lbl_53_rodata_0[];
extern int lbl_53_data_0[];

void fn_8009EF8C(void*, const void*);
float getFrame__16gfModelAnimationFd(void*);
void fn_27_279FC8(void*, void*, int);
void cmReqQuake__FiP5Vec3f(int, Vec3f*);
}

extern "C" void fn_53_2E0C(oldin::Melee* self, float delta) {
    using namespace oldin;
    int* d = lbl_53_data_0;
    const float* c = lbl_53_rodata_0;
    LocalData local;

    if (!self->active)
        return;

    Vec2f zoneA;
    Vec2f zoneB;
    zoneB.m_x = c[0x70 / 4];
    zoneB.m_y = c[0x70 / 4];
    zoneA.m_x = c[0x50 / 4];
    zoneA.m_y = c[0xD0 / 4];
    g_aiMgr->setDangerZone(&zoneA, &zoneB, -1, false, false);

    switch (self->state) {
    case 0:
        setState(&self->stateValue, &self->state, d[0x2A0 / 4], 0x5FE);
    case 0x5FE:
        setState(&self->stateValue, &self->state, d[0x2A4 / 4], 0x5FF);
        break;

    case 0x5FF: {
        float random = randf();
        self->sound1 = -1;
        self->sound2 = -1;
        self->timer = c[0x78 / 4] + c[0x98 / 4] * random;
        self->ground->setVisibility(1);
        self->soundFlag = 0;
        self->flags.word &= 0x03FFFFFF;
    }
    case 0x62C: {
        self->timer -= delta;
        self->ground->getNodeMatrix(local.matrixC0, 0, self->node);
        float z = local.matrixC0[11];
        float y = local.matrixC0[7];
        float x = local.matrixC0[3];
        local.posC0.m_y = y;
        local.posC0.m_x = x;
        local.posC0.m_z = z;
        fn_8009EF8C((char*)self + 0x42C, &local.posC0);

        gfModelAnimation* animation = self->ground->animations[0];
        if (animation) {
            if (!self->soundFlag) {
                self->soundFlag = 1;
                self->generator.setPos(&local.posC0);
                self->sound1 = self->generator.playSE((SndID)0x1BBB, -1, 0, -1);
                OSReport((const char*)d + 0x2B8, local.posC0.m_x,
                         local.posC0.m_y, local.posC0.m_z);
                self->effect = g_ecMgr->setEffect((EfID)0x60);
            }

            if (self->sound2 < 0 &&
                c[0x54 / 4] <= getFrame__16gfModelAnimationFd(animation)) {
                self->generator.setPos(&local.posC0);
                self->sound2 = self->generator.playSE((SndID)0x1BBC, -1, 0, -1);
                OSReport((const char*)d + 0x2E8, local.posC0.m_x,
                         local.posC0.m_y, local.posC0.m_z);
                goto state63C;
            }

            g_ecMgr->setPos(self->effect, &local.posC0);
        }

        setState(&self->stateValue, &self->state, d[0x2A8 / 4], 0x62C);
        break;
    }

    state63CUpdate: {
        self->timer -= delta;
        self->ground->getNodeMatrix(local.matrix90, 0, self->node);
        float z = local.matrix90[11];
        float y = local.matrix90[7];
        float x = local.matrix90[3];
        local.pos90.m_y = y;
        local.pos90.m_x = x;
        local.pos90.m_z = z;
        fn_8009EF8C((char*)self + 0x42C, &local.pos90);
        g_ecMgr->setPos(self->effect, &local.pos90);
        setState(&self->stateValue, &self->state, d[0x2AC / 4], 0x63C);
        break;
    }

    case 0x63C:
    state63C:
        if (c[0] < self->timer)
            goto state63CUpdate;

        {
            self->ground->getNodeMatrix(local.matrix60, 0, self->node);
            float z = local.matrix60[11];
            float y = local.matrix60[7];
            float x = local.matrix60[3];
            local.pos60.m_y = y;
            local.pos60.m_x = x;
            local.pos60.m_z = z;
            g_ecMgr->setPos(
                g_ecMgr->setEffect((EfID)0x18), &local.pos60);
            self->generator.setPos(&local.pos60);
            self->generator.playSE((SndID)0x1BBD, -1, 0, -1);
            OSReport((const char*)d + 0x310, local.pos60.m_x,
                     local.pos60.m_y, local.pos60.m_z);
            cmReqQuake__FiP5Vec3f(cmQuake::Amplitude_XL, &local.pos60);
            fn_8009EF8C((char*)self + 0x42C, &local.pos60);
            g_ecMgr->killEffect(self->effect, 1, 1);

            local.matrix60[7] -= c[0x3C / 4];
            fn_27_279FC8(self->object210, local.matrix60, 0);

            self->ground->setVisibility(0);
            setTranslation(self->ground->module, Vec3f(c[0], c[0x40 / 4], c[0]));
            self->flag4B0 = 1;
            int value = d[0];
            self->value4B4 = value;
            self->value4B8 = 0;
            reinterpret_cast<stMelee*>(self)->playSeBasic((SndID)0x1BBE, c[0]);
            self->timer = c[0x10 / 4];
            goto state660;
        }

    state660Update:
        self->timer -= delta;
        setState(&self->stateValue, &self->state, d[0x2B0 / 4], 0x660);
        break;

    case 0x660:
    state660:
        if (c[0] < self->timer)
            goto state660Update;

        self->active = 0;
        self->ground->setVisibility(0);
        reinterpret_cast< ::Ground*>(self->ground)->setEnableCollisionStatus(false);
        hideGround(self->ground, c[0x40 / 4], c[0]);

        {
            setTranslation(static_cast<oldin::Ground*>(self->object210)->module,
                           Vec3f(c[0], c[0x40 / 4], c[0]));
        }

        {
            Flags flags = self->flags;
            flags.bits.mode = 1;
            self->flags = flags;
        }
        int nextValue = d[0x2B4 / 4];
        setState(&self->stateValue, &self->state, nextValue, 0x663);
        break;

    default:
        break;
    }
}
