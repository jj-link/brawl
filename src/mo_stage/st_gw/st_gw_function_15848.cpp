#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_63_rodata_1E0[];
float randf__Fv();
}

struct GroundObj {
    char pad_00[0x3C];
    float m_3C;
};

struct Ground_base {
    char pad[0x3C];
};

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
    virtual void fn_63_15534();
    virtual void fn_63_1558C();
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
    virtual void fn_63_3378();
    virtual void startup();
    virtual void fn_63_15BB4();
    virtual void fn_63_59C();
    virtual GroundObj* fn_63_3370();
    virtual void fn_63_336C();
    virtual void fn_63_2B64();
    virtual void fn_63_3364();
    virtual void fn_63_3358();
    virtual void fn_63_3348();
    virtual void fn_63_3338();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual bool setNodeVisibility(bool setVisibility, u32 sceneModelIndex, u32 nodeIndex, bool recursive, bool recursive_);

    char pad40[0x154 - 0x40];
    float m_154;
    char pad158[0x178 - 0x158];
    u32 m_178[3];
    char pad184[0x188 - 0x184];
    u8* m_188;
    u8* m_18C;
};

extern "C" void fn_63_15848(Ground* self, float delta) {
    const float* d = lbl_63_rodata_1E0;
    GroundObj* obj = self->fn_63_3370();
    if (obj != 0) {
        float t = self->m_154 - delta;
        self->m_154 = t;
        if (t < d[0]) {
            self->m_154 = d[0];
        }
        if (d[0] == self->m_154) {
            float r = randf__Fv();
            self->setNodeVisibility(false, 0, self->m_178[*self->m_188], true, false);
            u8* state = self->m_188;
            switch (*state) {
            case 0: {
                u8* flags = self->m_18C;
                if (flags[0] == 1) {
                    if (r < d[4]) *state = 0; else *state = 1;
                } else if (flags[1] == 1) {
                    if (r < d[4]) *state = 1; else *state = 0;
                } else {
                    if (r < d[5]) *state = 1; else *state = 0;
                }
                break;
            }
            case 1: {
                u8* flags = self->m_18C;
                if (flags[1] == 1) {
                    if (r < d[4]) *state = 1;
                    else if (r < d[6]) *state = 0;
                    else *state = 2;
                } else if (flags[0] == 1) {
                    if (r < d[4]) *state = 0;
                    else if (r < d[6]) *state = 1;
                    else *state = 2;
                } else if (flags[2] == 1) {
                    if (r < d[4]) *state = 0;
                    else if (r < d[6]) *state = 1;
                    else *state = 2;
                } else {
                    if (r < d[7]) *state = 0;
                    else if (r < d[8]) *state = 2;
                    else *state = 1;
                }
                break;
            }
            case 2: {
                u8* flags = self->m_18C;
                if (flags[2] == 1) {
                    if (r < d[4]) *state = 2; else *state = 1;
                } else if (flags[1] == 1) {
                    if (r < d[4]) *state = 1; else *state = 2;
                } else {
                    if (r < d[5]) *state = 1; else *state = 2;
                }
                break;
            }
            }
            self->m_154 = obj->m_3C;
        }
        self->setNodeVisibility(true, 0, self->m_178[*self->m_188], true, false);
    }
}
