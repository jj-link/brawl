#include <gf/gf_pad_system.h>
#include <mu/mu_object.h>
#include <snd/snd_system.h>
#include <string.h>
#pragma force_active on

struct Self {
    int active;
    char* text;
    char pad[0x3c];
    MuObject* obj;
    char pad2[0x48];
    int padIndex;
};
extern "C" int fn_16_E18(Self*, const gfPadStatus*, int);
extern "C" void fn_16_BBC(Self*, const gfPadStatus*);
extern unsigned char lbl_16_rodata_58[];
extern float lbl_16_rodata_30;

extern "C" int fn_16_998(Self* self, const gfPadStatus* input, char* out, int arg, int sound) {
    if (!self->active)
        return 3;
    int type;
    gfPadStatus status;
    if (self->padIndex >= 0 && self->padIndex < 8) {
        g_gfPadSystem->getSysPadStatus(self->padIndex, &status);
        type = status.m_controllerType;
    } else {
        type = 4;
    }
    unsigned int frame;
    if (type >= 0 && type < 4)
        frame = lbl_16_rodata_58[type];
    else
        frame = 4;
    self->obj->setFrameTex((float)frame);
    self->obj->m_modelAnim->m_anmObjTexPatRes->SetUpdateRate(lbl_16_rodata_30);
    int result = fn_16_E18(self, input, arg);
    if (result == 0) {
        strcpy(out, self->text);
        if (sound)
            g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
    }
    if (result != 2)
        return result;
    fn_16_BBC(self, input);
    return 2;
}