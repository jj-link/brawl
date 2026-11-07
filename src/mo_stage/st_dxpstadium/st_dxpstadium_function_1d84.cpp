#pragma force_active on
#include <gr/gr_tengan_event.h>
struct Stage {
    char pad[0x488];
    grTenganEvent event;
    char pad1[0x5e0 - 0x534];
    unsigned char kind;
    char pad2[0x615 - 0x5e1];
    unsigned char flag;
    char pad3[0x61c - 0x616];
    grTenganEvent event2;
    char pad4[0x6f8 - 0x6c8];
    unsigned char overrideKind;
};
class Ground {
public:
    char pad[0x3c];
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual void u7();
    virtual void u8();
    virtual void u9();
    virtual void u10();
    virtual void u11();
    virtual void u12();
    virtual void u13();
    virtual void u14();
    virtual void u15();
    virtual void u16();
    virtual void u17();
    virtual void u18();
    virtual void u19();
    virtual void u20();
    virtual void u21();
    virtual void u22();
    virtual void u23();
    virtual void u24();
    virtual void u25();
    virtual void u26();
    virtual void u27();
    virtual void u28();
    virtual void u29();
    virtual void u30();
    virtual void u31();
    virtual void u32();
    virtual void u33();
    virtual void u34();
    virtual void u35();
    virtual void u36();
    virtual void u37();
    virtual void u38();
    virtual void u39();
    virtual void u40();
    virtual void u41();
    virtual void u42();
    virtual void u43();
    virtual void u44();
    virtual void u45();
    virtual void u46();
    virtual void u47();
    virtual void u48();
    virtual void u49();
    virtual void u50();
    virtual void u51();
    virtual void u52();
    virtual void setAnimation(int, int, const char*, int, int);
    char pad2[0x164 - 0x40];
    int value;
};
extern "C" {
extern char lbl_83_data_0[];
extern const float lbl_83_rodata_0;
extern const float lbl_83_rodata_68;
Ground* getGround__5StageFi(Stage*, int);
void playSeBasic__7stMeleeF5SndIDf(void*, int, float);
void setDisplay__15grStadiumVisionFb(Ground*, bool);
void fn_83_1D84(Stage* self, float dt) {
    const char* data = lbl_83_data_0;
    if (self->event.isEvent()) {
        int kind = self->kind;
        int value = 0;
        if (self->overrideKind == 1) kind = 3;
        switch (kind) {
        case 3: value = 4; break;
        case 1: value = 9; break;
        case 2: value = 8; break;
        case 4: value = 11; break;
        case 7: value = 10; break;
        }
        getGround__5StageFi(self, 0)->value = value;
        if (kind != 0) {
            switch (self->event.getPhase()) {
            case 0:
                self->event.m_manualFramesLeft = lbl_83_rodata_68;
                getGround__5StageFi(self, 0)->setAnimation(0, 0, data + 0x4c, 0, 0);
                switch (kind) {
                case 3: getGround__5StageFi(self, 0)->setAnimation(1, 0, data + 0x24, 0, 0); break;
                case 1: getGround__5StageFi(self, 0)->setAnimation(1, 0, data + 0x2c, 0, 0); break;
                case 2: getGround__5StageFi(self, 0)->setAnimation(1, 0, data + 0x34, 0, 0); break;
                case 4: getGround__5StageFi(self, 0)->setAnimation(1, 0, data + 0x3c, 0, 0); break;
                case 7: getGround__5StageFi(self, 0)->setAnimation(1, 0, data + 0x44, 0, 0); break;
                }
                self->event.setPhase(1);
                playSeBasic__7stMeleeF5SndIDf(self, 0x1eed, lbl_83_rodata_0);
                break;
            case 1: {
                float f = self->event.m_manualFramesLeft - dt;
                self->event.m_manualFramesLeft = f;
                if (f < lbl_83_rodata_0) self->event.m_manualFramesLeft = lbl_83_rodata_0;
                if (lbl_83_rodata_0 == self->event.m_manualFramesLeft) {
                    getGround__5StageFi(self, 0)->setAnimation(1, 0, data + 0x4c, 0, 0);
                    switch (kind) {
                    case 3: getGround__5StageFi(self, 0)->setAnimation(0, 0, data + 0x24, 0, 0); break;
                    case 1: getGround__5StageFi(self, 0)->setAnimation(0, 0, data + 0x2c, 0, 0); break;
                    case 2: getGround__5StageFi(self, 0)->setAnimation(0, 0, data + 0x34, 0, 0); break;
                    case 4: getGround__5StageFi(self, 0)->setAnimation(0, 0, data + 0x3c, 0, 0); break;
                    case 7: getGround__5StageFi(self, 0)->setAnimation(0, 0, data + 0x44, 0, 0); break;
                    }
                    self->event.m_manualFramesLeft = lbl_83_rodata_68;
                    self->event.setPhase(2);
                    if (self->event.isReadyEnd() == 1) {
                        self->event.end();
                        self->event2.end();
                        self->flag = 0;
                        getGround__5StageFi(self, 0)->setAnimation(0, 0, data + 0x54, 0, 0);
                        setDisplay__15grStadiumVisionFb(getGround__5StageFi(self, 0), false);
                        self->event2.start();
                    }
                }
                break;
            }
            case 2: {
                float f = self->event.m_manualFramesLeft - dt;
                self->event.m_manualFramesLeft = f;
                if (f < lbl_83_rodata_0) self->event.m_manualFramesLeft = lbl_83_rodata_0;
                if (lbl_83_rodata_0 == self->event.m_manualFramesLeft) self->event.setPhase(0);
                break;
            }
            }
        }
    }
}
}