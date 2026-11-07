#include <snd/snd_system.h>
#include <cm/cm_controller_ai.h>
#pragma force_active on
struct Obj {
    char pad[0xe0];
    unsigned int state;
    char pad2[4];
    int index;
    char pad3[4];
    float x, y;
};
extern "C" {
extern void* lbl_27_bss_5668;
extern float lbl_27_data_4F778[];
extern float lbl_27_rodata_40BC;
void fn_27_2310EC(void*, float, float);
void fn_27_250AAC(Obj* self, int arg) {
    if (arg == 1) {
        if (self->state == 0) {
            g_sndSystem->playSE((SndID)3, -1, 0, 0, -1);
            return;
        }
        g_sndSystem->playSE((SndID)0x1d94, -1, 0, 0, -1);
        self->state = 0;
    } else {
        if (self->state == 1) {
            g_sndSystem->playSE((SndID)3, -1, 0, 0, -1);
            return;
        }
        g_sndSystem->playSE((SndID)0x1d95, -1, 0, 0, -1);
        self->state = 1;
    }
    if (lbl_27_bss_5668) {
        if (self->state == 0) {
            fn_27_2310EC(lbl_27_bss_5668, self->x, self->y);
            ((signed char*)g_cmAIController)[0x95] &= ~0x80;
        } else {
            fn_27_2310EC(lbl_27_bss_5668, lbl_27_data_4F778[self->index], lbl_27_rodata_40BC);
            ((signed char*)g_cmAIController)[0x95] &= ~0x80;
        }
    }
}
}