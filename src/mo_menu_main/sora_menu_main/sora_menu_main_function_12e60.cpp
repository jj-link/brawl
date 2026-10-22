#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#pragma force_active on

struct MenuMain {
    char pad0[0x108];
    int unk108;
    char pad10C[0x200];
    unsigned int unk30C;
    unsigned char b310;
    char pad311[0x5164 - 0x311];
    unsigned char b5164;
};

extern "C" void fn_2_12C6C(MenuMain* self, gfPadStatus* output);

extern "C" int fn_2_12E60(MenuMain* self) {
    gfPadStatus status;
    if (self->b5164 == 0) {
        return 0;
    }
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    fn_2_12C6C(self, &status);
    int v = self->unk108;
    if (v == 0) {
        goto ret1;
    }
    if (self->b310 != 0 && self->unk30C <= (unsigned)(v + 2)) {
    ret1:
        return 1;
    }
    if (status.m_buttonsCurrentFrame2.bits & 0x20) {
        return 0;
    }
    if (status.m_buttonsCurrentFrame2.bits & 0x40) {
        return 0;
    }
    if (status.m_buttonsCurrentFrame2.bits & 0x400) {
        return 0;
    }
    return (status.m_buttonsCurrentFrame2.bits & 0x800) == 0;
}
