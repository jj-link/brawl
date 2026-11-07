#include <mu/mu_object.h>
#include <mu/mu_msg.h>
#pragma force_active on

extern "C" {
extern char lbl_28_data_0[];
extern const float lbl_28_rodata_8C;
void printf__5MuMsgFUlPCce(void* msg, unsigned long index, const char* fmt, ...);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void* a, void* b, char* c);
}

struct AdvMenuName {
    char m_pad0[0x40];
    int m_40;
    char m_pad1[0x124 - 0x44];
    u8 m_124;
    char m_pad2[0x12c - 0x125];
    MuMsg* m_msg;
    MuObject* m_130;
    MuObject* m_134;
    MuObject* m_138;
    MuObject* m_13c;
    MuObject* m_140;
    char m_pad3[0x158 - 0x144];
    nw4r::g3d::ScnMdl* m_158;
    nw4r::g3d::ScnMdl* m_15c;
    char m_pad4[0x168 - 0x160];
    int m_168;
    char m_pad5[0x352 - 0x16c];
    u8 m_352;
    u8 m_353;
};

extern "C" int fn_28_288C(AdvMenuName* self) {
    char* data = lbl_28_data_0;
    if (self->m_352) {
        if (self->m_353) {
            self->m_40 = 2;
        } else {
            self->m_40 = 0;
            MuObject* a = self->m_130;
            self->m_168 = 3;
            printf__5MuMsgFUlPCce(self->m_msg, 0xa, data + 0x1a4);
            printf__5MuMsgFUlPCce(self->m_msg, 0xb, data + 0x1a4);
            MuObject* b = self->m_138;
            b->changeNodeAnimNIf(data + 0x12c);
            b->changeVisAnimNIf(data + 0x12c);
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->m_15c, self->m_140->m_sceneModel, data + 0xec);
            a->setFrameVisible(lbl_28_rodata_8C);
            if (self->m_124) {
                MuObject* c = self->m_134;
                c->changeNodeAnimNIf(data + 0x12c);
                c->changeVisAnimNIf(data + 0x12c);
                Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->m_158, self->m_13c->m_sceneModel, data + 0xec);
            }
        }
        self->m_352 = 0;
    }
    return self->m_168;
}
