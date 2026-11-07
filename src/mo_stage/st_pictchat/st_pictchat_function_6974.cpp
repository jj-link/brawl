#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#include <snd/snd_3d_generator.h>
#include <types.h>
#pragma force_active on

extern f32 lbl_73_rodata_C8;

struct GroundBase {
    char pad000[0x3C];
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
    virtual void fn_73_6834();
    virtual void fn_73_363C();
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
    virtual void fn_73_33D0();
    virtual void startup();
    virtual void setNode();
    virtual void fn_73_8DC();
    virtual void fn_73_33C8();
    virtual void fn_73_33C4();
    virtual void fn_73_2C5C();
    virtual void fn_73_33BC();
    virtual void fn_73_33B0();
    virtual void fn_73_33A0();
    virtual void fn_73_3390();
    virtual void getNodeIndex();
    virtual void getNodePosition(Vec3f* pos, u32 a, u32 b);

    char pad040[0x150 - 0x40];
    u8 state;                 // 0x150
    char pad151[0x294 - 0x151];
    u32 field294;             // 0x294
    u8 flag298;               // 0x298
    char pad299[0x29C - 0x299];
    Vec3f cur;                // 0x29C
};

extern "C" void fn_73_6974(Ground* self) {
    Vec3f pos;
    switch ((s32)self->state) {
    case 3:
        break;
    case 4:
    default:
        return;
    }
    self->getNodePosition(&pos, 0, self->field294);

    u32 nearZero = 0;
    s32 flag = 0;
    if ((float)(double)nw4r::ut::Abs(self->cur.m_x) < lbl_73_rodata_C8) {
        flag = 1;
    }
    if (flag != 0) {
        flag = 0;
        if ((float)(double)nw4r::ut::Abs(self->cur.m_y) < lbl_73_rodata_C8) {
            flag = 1;
        }
        if (flag != 0) {
            flag = 0;
            if ((float)(double)nw4r::ut::Abs(self->cur.m_z) < lbl_73_rodata_C8) {
                flag = 1;
            }
            if (flag != 0) {
                nearZero = 1;
            }
        }
    }

    if (nearZero == 1) {
        self->cur.m_x = pos.m_x;
        self->cur.m_y = pos.m_y;
        self->cur.m_z = pos.m_z;
        ((snd3DGenerator*)((char*)self + 0x2A8))->playSE((SndID)0x1D23, 0, 0, -1);
        self->flag298 = 1;
    } else {
        if (self->flag298 == 1 && self->cur.m_x > pos.m_x) {
            ((snd3DGenerator*)((char*)self + 0x2A8))->playSE((SndID)0x1D23, 0, 0, -1);
            self->flag298 = 0;
        } else if (self->flag298 == 0 && self->cur.m_x < pos.m_x) {
            ((snd3DGenerator*)((char*)self + 0x2A8))->playSE((SndID)0x1D23, 0, 0, -1);
            self->flag298 = 1;
        }
        self->cur.m_x = pos.m_x;
        self->cur.m_y = pos.m_y;
        self->cur.m_z = pos.m_z;
    }
    ((snd3DGenerator*)((char*)self + 0x2A8))->setPos(&self->cur);
}
