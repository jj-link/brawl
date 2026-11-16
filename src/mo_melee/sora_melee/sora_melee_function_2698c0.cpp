#include <gr/gr_yakumono_punch_slider.h>
#include <gr/gr_gimmick_motion_path.h>
#include <snd/snd_system.h>
#include <st/st_trigger.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_42E8[9];
extern "C" char lbl_27_data_56078[];
extern "C" void fn_27_26399C(void* self);
extern "C" void fn_27_26C314(void* self, void* data, u32 flag);
extern sndSystem* g_sndSystem;
extern stTriggerMng* g_stTriggerMng;

void grYakumonoPunchSlider::onDamage(int index, soDamage* damage, soDamageAttackerInfo* attackerInfo) {
    const float* k = lbl_27_rodata_42E8;
    if (grYakumono::isEnableAttackPersonAttacked((u32)damage, (u32)attackerInfo, (u32)((char*)m_sliderData + 0x10)) != 0) {
        float frame = *(float*)((char*)damage + 4);
        fn_27_26399C(m_yakumono);
        grYakumono::setTeamYakumono((u32)(s32)(s8)*((char*)damage + 0x30), (u32)-1);
        grYakumono::setTeamYakumonoOwnerId(*(u32*)((char*)attackerInfo + 0x14));
        if (m_280 == 1) {
            if (frame < k[3]) {
                frame = k[3];
            }
            ((char*)m_sliderData)[0xEA] = (u8)(((char*)m_sliderData)[0xEA] | 1);
            g_stTriggerMng->setTriggerFlag((stTriggerData*)((char*)m_sliderData + 0xE8));
            *(int*)((char*)this + 0x180) = g_sndSystem->playSE((SndID)0x226A, -1, 0, 0, -1);
            m_sliderMotionPath->startMove();
            m_sliderMotionPath->setFrameUpdate(k[8] * (*(float*)((char*)m_sliderData + 8) * frame));
            u32 nodeIdx = *(u32*)((char*)this + 0x160);
            struct {
                s32 a;
                u8 b;
                u8 e;
                s32 c;
                float d;
            } det;
            det.a = 0x3FF;
            det.b = 0;
            det.c = 0;
            det.d = k[4];
            det.e = 1;
            grYakumono::setAttackGimmick(0, 0, nodeIdx, (AttackData*)((char*)m_sliderData + 0x34), (AttackDetails*)&det);
            fn_27_26C314(this, lbl_27_data_56078, 0xFF);
            disableHit(0, 0);
            m_280 = 2;
        }
    }
}
