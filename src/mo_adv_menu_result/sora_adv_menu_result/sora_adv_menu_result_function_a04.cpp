#include <gf/gf_pad_system.h>
#include <gf/gf_model.h>
#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_800B753C(void*, float);
extern "C" void fn_80075F1C(sndSystem*, u32, int);
extern "C" float getFrame__16gfModelAnimationFd(gfModelAnimation*);
extern float lbl_34_rodata_40;
extern float lbl_34_rodata_44;

extern "C" void fn_34_A04(char* self) {
    char* p = *(char**)(self + 0x59c);
    if (p) {
        char* obj = *(char**)(p + 0x268);
        if (*(int*)(self + 0x48) > 0) {
            if (--*(int*)(self + 0x48) > 0)
                return;
        }
        gfPadStatus status;
        g_gfPadSystem->getSysPadStatus(*(int*)(self + 0x44), &status);
        if ((status.m_buttonsPressedThisFrame.bits & 0x100) ||
            (status.m_buttonsPressedThisFrame.bits & 0x200) ||
            (status.m_buttonsPressedThisFrame.bits & 0x1000)) {
            if (obj) {
                g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
                if (getFrame__16gfModelAnimationFd(*(gfModelAnimation**)(obj + 0x14)) < lbl_34_rodata_40) {
                    fn_800B753C(obj, lbl_34_rodata_44);
                    *(int*)(self + 0x598) = 120;
                } else {
                    if (*(u32*)(self + 0x5a0) != 0xffffffff) {
                        fn_80075F1C(g_sndSystem, *(u32*)(self + 0x5a0), 0);
                        *(u32*)(self + 0x5a0) = 0xffffffff;
                    }
                    *(int*)(self + 0x40) = 1;
                }
            }
        }
    }
}