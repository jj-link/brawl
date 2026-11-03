#pragma force_active on
#include <gf/gf_model.h>

extern "C" int lbl_8059C648[2];

extern "C" void setLoop__16gfModelAnimationFd(gfModelAnimation* self, bool loop) {
    int v = loop ? lbl_8059C648[1] : lbl_8059C648[0];
    if (self->m_anmObjChrRes) *(int*)((char*)self->m_anmObjChrRes + 0x28) = v;
    if (self->m_anmObjVisRes) *(int*)((char*)self->m_anmObjVisRes + 0x28) = v;
    if (self->m_anmObjTexPatRes) *(int*)((char*)self->m_anmObjTexPatRes + 0x28) = v;
    if (self->m_anmObjTexSrtRes) *(int*)((char*)self->m_anmObjTexSrtRes + 0x28) = v;
    if (self->m_anmObjMatClrRes) *(int*)((char*)self->m_anmObjMatClrRes + 0x28) = v;
    if (self->m_anmObjShpRes) *(int*)((char*)self->m_anmObjShpRes + 0x28) = v;
}