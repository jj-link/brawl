#include <gf/gf_pad_status.h>
#include <gf/gf_pad_system.h>
#include <mu/mu_object.h>
#pragma force_active on
extern "C" {
void fn_10_14A2C(void*);
void fn_10_19E3C(int);
void fn_800B9804(void*, unsigned char);
extern unsigned char lbl_10_rodata_738[];
extern float lbl_10_rodata_6D8;
}
inline void update(char* self) {
    MuObject* object;
    int padType = *(int*)(self + 0x1E0);
    int textureIndex = *(int*)(self + 0x1DC);
    int mode = *(int*)(self + 0x1B4);
    object = *(MuObject**)(self + 0xD0);
    int frame = 0;
    if (padType != 4) frame = textureIndex % 4;
    object->setFrameTex((float)frame);
    float visible = (float)lbl_10_rodata_738[padType];
    if (mode == 2) visible += lbl_10_rodata_6D8;
    object->setFrameVisible(visible);
}
extern "C" void fn_10_148E8(char* self, unsigned int selection)
{
    unsigned int shouldQuery = ((int)selection >= 0) & ((int)selection < 8);
    *(unsigned int*)(self + 0x1DC) = selection;
    if (shouldQuery) {
        gfPadStatus status;
        g_gfPadSystem->getSysPadStatus((int)selection, &status);
        *(int*)(self + 0x1E0) = status.m_controllerType;
    } else {
        *(int*)(self + 0x1E0) = 4;
    }
    update(self);
    if ((int)selection < 0) fn_10_14A2C(self);
    if ((int)selection >= 0) fn_800B9804(self + 4, (unsigned char)selection);
    fn_10_19E3C(*(int*)(self + 0x1A8));
}