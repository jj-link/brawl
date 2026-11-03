#include <mu/mu_object.h>
#pragma force_active on

extern "C" {
extern char lbl_28_data_0[];
extern const float lbl_28_rodata_8C;
extern const float lbl_28_rodata_94;
int fn_800B61C0(MuObject*);
void printf__5MuMsgFUlPCce(void* msg, unsigned long index, const char* fmt, ...);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void* a, void* b, char* c);
}

struct AdvMenuNameSlot {
    int m_state;
    char m_pad[0xb8 - 4];
};

struct AdvMenuName {
    char m_pad0[0x40];
    int m_40;
    char m_pad1[0x48 - 0x44];
    int m_48;
    char m_pad2[0x50 - 0x4c];
    int m_50[2];
    char m_pad3[0x124 - 0x58];
    u8 m_124;
    char m_pad4[0x12c - 0x125];
    void* m_msg;
    MuObject* m_130;
    MuObject* m_134;
    MuObject* m_138;
    MuObject* m_13c;
    MuObject* m_140;
    char m_pad5[0x14c - 0x144];
    MuObject* m_14c;
    char m_pad6[0x158 - 0x150];
    void* m_158;
    void* m_15c;
    char m_pad7[0x168 - 0x160];
    int m_168;
    char m_pad8[0x220 - 0x16c];
    AdvMenuNameSlot m_slots[2];
};

extern "C" int fn_28_2640(AdvMenuName* self) {
    char* data = lbl_28_data_0;
    AdvMenuName* p;
    AdvMenuName* q;
    int i;
    MuObject* obj = self->m_14c;
    MuObject* vis = self->m_130;
    vis->setFrameVisible(lbl_28_rodata_94);
    obj->changeClrAnimNIf(data + 0x1a8);
    obj->m_modelAnim->setUpdateRate(lbl_28_rodata_94);
    switch (self->m_48) {
    case 0:
        obj->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(lbl_28_rodata_8C);
        break;
    case 1:
        obj->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(lbl_28_rodata_94);
        break;
    }
    p = self;
    q = self;
    for (i = 0; i < 2; i++) {
        if (p->m_slots[0].m_state == 1) {
            p->m_slots[0].m_state = 2;
            obj->changeNodeAnimNIf(data + 0x1c0);
            obj->m_modelAnim->m_anmObjChrRes->SetUpdateRate(lbl_28_rodata_94);
            obj->setFrameNode(lbl_28_rodata_8C);
        }
        if (p->m_slots[0].m_state == 2) {
            if (fn_800B61C0(obj)) {
                p->m_slots[0].m_state = 3;
            }
        }
        if (p->m_slots[0].m_state == 3) {
            if (q->m_50[0] == 0) {
                self->m_40 = 1;
                self->m_168 = 5;
                printf__5MuMsgFUlPCce(self->m_msg, 0xc, data + 0x1a4);
            } else if (q->m_50[0] == 2) {
                self->m_168 = 3;
                printf__5MuMsgFUlPCce(self->m_msg, 0xa, data + 0x1a4);
                printf__5MuMsgFUlPCce(self->m_msg, 0xb, data + 0x1a4);
                MuObject* a = self->m_138;
                a->changeNodeAnimNIf(data + 0x12c);
                a->changeVisAnimNIf(data + 0x12c);
                Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->m_15c, self->m_140->m_sceneModel, data + 0xec);
                vis->setFrameVisible(lbl_28_rodata_8C);
                if (self->m_124) {
                    MuObject* b = self->m_134;
                    b->changeNodeAnimNIf(data + 0x12c);
                    b->changeVisAnimNIf(data + 0x12c);
                    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->m_158, self->m_13c->m_sceneModel, data + 0xec);
                }
            }
        }
        p = (AdvMenuName*)((char*)p + 0xb8);
        q = (AdvMenuName*)((char*)q + 4);
    }
    return self->m_168;
}
