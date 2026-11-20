// Best candidate so far: 17 of ~1000 lines differ (99.4%), NOT an exact match.
// Remaining differences are register assignment only (no instruction count or
// branch differences): case 1 first loads, case 3 fsel destination, case 5 FSelect constants.
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <nw4r/math/math_arithmetic.h>
#include <revolution/OS/OSFastCast.h>
#pragma force_active on

extern "C" float fn_801622C4(float);
extern "C" const float lbl_66_rodata_138[13];

struct Ret {
    char pad0[0x78];
    float f78;
    float f7c;
    char pad80[4];
    float f84;
};

struct Ground_base {
    char pad[0x3c];
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
    virtual void fn_66_5A34();
    virtual void fn_66_5A9C();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_66_6498();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_66_2D00();
    virtual void startup();
    virtual void setNode();
    virtual void fn_66_6BC();
    virtual Ret* fn_66_2CF8();
    virtual void fn_66_2CF4();
    virtual void fn_66_2BF4();
    virtual void fn_66_2CEC();
    virtual void fn_66_2CE0();
    virtual void fn_66_2CD0();
    virtual void fn_66_BBC();
    virtual void getNodeIndex();
    virtual void getNodePosition(Vec3f* out, u32 a, u32 b);

    char pad40[0x80];
    u32 arg0c0;
    u32 arg0c4;
    char pad_c8[0x159 - 0xc8];
    u8 state;
    u8 flag;
    float timer;
    float f160;
    float f164;
    float f168;
    float f16c;
    float f170;
    float f174;
    float f178;
    char pad17c[4];
    float f180;
    Vec3f* pos;
    float f188;
    float f18c;
    float f190;
    char pad194[4];
    snd3DGenerator gen;
};

inline float clamp01(float x, float low, float high) {
    float y = nw4r::math::FSelect(x - low, x, low);
    return nw4r::math::FSelect(y - high, high, y);
}

extern "C" void fn_66_5B40(Ground* self, float delta) {
    const float* lbl = lbl_66_rodata_138;
    Vec3f spC;
    u16 spA;
    u16 sp8;

    if (self->pos != 0) {
        Ret* r = self->fn_66_2CF8();
        if (r != 0) {
            self->timer -= delta;
            if (self->timer < lbl[0]) {
                self->timer = lbl[0];
            }

            switch (self->state) {
            case 1: {
                Vec3f* pos = self->pos;
                float y = pos->m_y;
                self->f164 = y + lbl[1] * (self->f160 - y);
                self->f178 = lbl[0];
                self->f16c = r->f7c;
                self->f170 = r->f84;
                self->flag = 0;
                self->f188 = pos->m_x;
                self->f18c = pos->m_y;
                self->f190 = pos->m_z;
                self->getNodePosition(&spC, self->arg0c0, self->arg0c4);
                self->gen.setPos(&spC);
                self->gen.playSE((SndID)0x1cd4, 0, 0, -1);
                self->state = 2;
                self->timer = lbl[2];
                break;
            }
            case 2: {
                float w = lbl[3] - self->timer * lbl[4];
                if (w < lbl[0]) {
                    w = lbl[0];
                }
                if (w > lbl[3]) {
                    w = lbl[3];
                }
                if (w >= lbl[1]) {
                    self->state = 3;
                    self->timer = lbl[5];
                }
                spA = (u16)(s32)(lbl[6] * w);
                self->pos->m_y = self->f18c + lbl[8] * self->f164 * fn_801622C4(lbl[7] * __OSu16tof32(&spA));
                if (self->pos->m_y < self->f160) {
                    self->pos->m_y = self->f160;
                }
                break;
            }
            case 3: {
                float t1 = lbl[3] - self->timer / lbl[5];
                float t3 = clamp01(t1, lbl[0], lbl[3]);
                if (lbl[3] == t3) {
                    self->state = 4;
                    self->timer = lbl[9];
                }
                sp8 = (u16)(s32)(lbl[10] + lbl[10] * t3);
                self->pos->m_y = self->f18c + lbl[8] * self->f164 * fn_801622C4(lbl[7] * __OSu16tof32(&sp8));
                if (self->pos->m_y < self->f160) {
                    self->pos->m_y = self->f160;
                }
                break;
            }
            case 4:
                if (lbl[0] == self->timer) {
                    self->state = 5;
                }
                break;
            case 5: {
                if (self->pos->m_y <= lbl[4] * self->f164 + self->f164) {
                    self->f174 = self->f174 - r->f78 * delta;
                    if (self->f174 < lbl[0]) {
                        self->f174 = lbl[0];
                    }
                } else {
                    float d = self->f180 - lbl[11];
                    if (d < lbl[0]) {
                        d = lbl[0];
                    }
                    float q = d / lbl[12];
                    float c2 = clamp01(q, lbl[0], lbl[3]);
                    self->f174 = self->f174 + delta * (r->f78 * (c2 + lbl[1]));
                }
                self->pos->m_y = self->pos->m_y - self->f174;
                if (self->pos->m_y < self->f160) {
                    self->pos->m_y = self->f160;
                }
                self->f168 = self->pos->m_y;
                break;
            }
            }
        }
    }
}
