#pragma force_active on

struct MuObject {
    void changeNodeAnimNIf(const char* name);
    void changeVisAnimNIf(const char* name);
    void setFrameNode(float frame);
    void setFrameVisible(float frame);
};

extern "C" {
extern const char lbl_28_data_18C[];
extern const float lbl_28_rodata_8C;
extern const float lbl_28_rodata_94;
int fn_800B61C0(void*);
void fn_28_175C(void* self, int arg, void* p);
}

struct AdvMenuName {
    char m_pad0[0x40];
    int m_40;
    char m_pad1[0x50 - 0x44];
    int m_50;
    char m_pad2[0x58 - 0x54];
    int m_58;
    char m_pad3[0x130 - 0x5c];
    MuObject* m_130;
    char m_pad4[0x138 - 0x134];
    MuObject* m_138;
    char m_pad5[0x140 - 0x13c];
    void* m_140;
    char m_pad6[0x168 - 0x144];
    int m_168;
    char m_pad7[0x21c - 0x16c];
    int m_state;
};

extern "C" int fn_28_2B94(AdvMenuName* self) {
    MuObject* a = self->m_130;
    MuObject* b = self->m_138;
    fn_28_175C(self, 0, self->m_140);
    if (self->m_state == 1) {
        self->m_state = 2;
        if (self->m_50 == 2) {
            b->changeNodeAnimNIf(lbl_28_data_18C);
            b->changeVisAnimNIf(lbl_28_data_18C);
        }
    }
    if (self->m_state == 2) {
        if (fn_800B61C0(b)) {
            self->m_state = 3;
            if (self->m_50 == 2) {
                if (self->m_58 == 0) {
                    self->m_40 = 2;
                } else if (self->m_58 == 2) {
                    self->m_40 = 3;
                }
                a->setFrameNode(lbl_28_rodata_8C);
                a->setFrameVisible(lbl_28_rodata_94);
            }
        }
    }
    return self->m_168;
}
