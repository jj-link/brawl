#include <mu/mu_object.h>
#pragma force_active on

struct Menu {
    char pad[0x64c];
    MuObject** models;
};

extern "C" void fn_800B753C(MuObject*, float);
extern "C" void fn_800B798C(MuObject*, float);

extern "C" void fn_18_17B0(Menu* self, unsigned index, unsigned flags, float frame) {
    if (flags == 31) {
        fn_800B753C(self->models[index], frame);
    } else {
        index *= 4;
        gfModelAnimation* anim = (*(MuObject**)((char*)self->models + index))->m_modelAnim;

        if ((flags & 1) && anim->m_anmObjChrRes)
            (*(MuObject**)((char*)self->models + index))->setFrameNode(frame);
        if ((flags & 2) && anim->m_anmObjVisRes)
            (*(MuObject**)((char*)self->models + index))->setFrameVisible(frame);
        if ((flags & 4) && anim->m_anmObjTexPatRes)
            (*(MuObject**)((char*)self->models + index))->setFrameTex(frame);
        if ((flags & 8) && anim->m_anmObjTexSrtRes)
            fn_800B798C((*(MuObject**)((char*)self->models + index)), frame);
        if ((flags & 16) && anim->m_anmObjMatClrRes)
            (*(MuObject**)((char*)self->models + index))->setFrameMatCol(frame);
    }
}
