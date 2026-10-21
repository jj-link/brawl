#include <types.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#pragma force_active on

extern "C" {

void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(gfPadSystem* this_, int padNum, gfPadStatus* dest);

int fn_10_6BC8(void* self) {
    int padNum = 4;
    while (padNum < 8) {
        gfPadStatus status;
        getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, padNum, &status);
        if (status.m_error == 0 && status.m_controllerType != 0) {
            void* p = self;
            int count = *(int*)((char*)self + 0x648);
            int i = 0;
            while (i < count) {
                if (padNum == *(int*)((char*)(*(void**)((char*)p + 0x44)) + 0x1DC)) break;
                p = (void*)((char*)p + 4);
                i++;
            }
            if (i >= count) return padNum;
        }
        padNum++;
    }
    return -1;
}

}
