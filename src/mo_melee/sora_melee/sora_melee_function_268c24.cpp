#include <types.h>
#include <gr/gr_yakumono_punch_slider.h>
#include <snd/snd_system.h>
#include <st/st_trigger.h>
#pragma force_active on

extern "C" {
void fn_27_263750(void*, u32);
void fn_27_267914(void*, int, float);
void fn_27_26C314(void*, void*, u32);
void fn_80075F1C(sndSystem*, u32, int);
int playSE__9sndSystemF5SndIDiiii(sndSystem*, int, int, int, int, int);
extern const float lbl_27_rodata_42E8[9];
extern char lbl_27_data_56078[];
}
extern sndSystem* g_sndSystem;
extern stTriggerMng* g_stTriggerMng;

struct S3 {
    float x, y, z;
    S3(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

void grYakumonoPunchSlider::update(float deltaFrame) {
    const float* k = lbl_27_rodata_42E8;
    grGimmick::update(deltaFrame);
    updateMove(deltaFrame);
    float* f = (float*)((char*)this + 0x168);
    switch (m_280) {
    case 0:
        enableHit(0, 0);
        m_280 = 1;
        break;
    case 2:
        if (m_sliderMotionPath->isMoveEnd() == 1) {
            m_280 = 3;
            if (*(int*)((char*)this + 0x180) >= 0) {
                fn_80075F1C(g_sndSystem, *(int*)((char*)this + 0x180), 0);
                *(int*)((char*)this + 0x180) = -1;
            }
            if (((u8*)m_sliderData)[0xD] != 1) {
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x226B, -1, 0, 0, -1);
            }
        } else {
            float v = k[2] + *(float*)((char*)m_sliderMotionPath + 0x158) / k[3];
            if (v > k[4]) {
                v = k[4];
            }
            S3 t(v, v, v);
            f[2] += k[5];
            *(S3*)(f + 3) = t;
            fn_27_267914(this, 0, *(float*)((char*)m_sliderData + 0x44) * v);
        }
        break;
    case 3:
        if (f[3] > k[6]) {
            f[2] += k[5];
            f[3] = f[3] - k[7];
            if (f[3] < k[8]) {
                f[3] = k[1];
                fn_27_263750(m_yakumono, 0);
                fn_27_26C314(this, lbl_27_data_56078, 0);
                grYakumono::setTeamYakumono(0x10, -1);
            }
            f[5] = f[3];
            f[4] = f[3];
        } else {
            if (m_sliderMotionPath->isReturnEnd() == 1) {
                m_280 = 0;
                ((u8*)m_sliderData)[0xEA] = (u8)(((u8*)m_sliderData)[0xEA] & 0xFE);
                g_stTriggerMng->setTriggerFlag((stTriggerData*)((char*)m_sliderData + 0xE8));
                if (*(int*)((char*)this + 0x184) >= 0) {
                    fn_80075F1C(g_sndSystem, *(int*)((char*)this + 0x184), 0);
                    *(int*)((char*)this + 0x184) = -1;
                }
            }
        }
        if ((int)*(u8*)((char*)m_sliderMotionPath + 0x14C) == 3 && *(int*)((char*)this + 0x184) == -1) {
            *(int*)((char*)this + 0x184) = playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x226C, -1, 0, 0, -1);
        }
        break;
    }
    if (*(int*)((char*)this + 0xD8) >= 2) {
        char* p = *(char**)((char*)this + 0xD4) + (m_292 << 7);
        *(float*)(p + 0x14) = f[0];
        *(float*)(p + 0x18) = f[1];
        *(float*)(p + 0x1C) = f[2];
        p = *(char**)((char*)this + 0xD4) + (m_292 << 7);
        *(float*)(p + 0x20) = f[3];
        *(float*)(p + 0x24) = f[4];
        *(float*)(p + 0x28) = f[5];
    }
    grGimmick::updateCallback(0);
}
