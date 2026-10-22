#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_stTriggerMng;
void setTriggerFlag__12stTriggerMngFP13stTriggerData(void*, void*);
extern const float lbl_27_rodata_3920;
extern float lbl_27_data_547E0;

void fn_27_2372F4(void* arg0) {
    char* base = (char*)arg0;
    char* ptr = *(char**)(base + 0x10);

    if (*(float*)(base + 0xc) >= *(float*)ptr) {
        setTriggerFlag__12stTriggerMngFP13stTriggerData(g_stTriggerMng, ptr + 8);
        char* ptr2 = *(char**)(base + 0x10);
        u16 sp[2];
        sp[0] = *(u16*)(ptr2 + 8);
        sp[1] = *(u16*)(ptr2 + 0xA);
        bool flag;
        if (*(u16*)(ptr2 + 4) == sp[0] && *(u8*)(ptr2 + 7) == *(u8*)((char*)sp + 3)) {
            flag = true;
        } else {
            flag = false;
        }
        if (flag) {
            *(float*)(base + 0xc) = lbl_27_rodata_3920;
        }
    }
    float step = lbl_27_data_547E0;
    *(float*)(base + 0xc) = *(float*)(base + 0xc) + step;
}
}
