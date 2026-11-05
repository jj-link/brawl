#pragma force_active on

#include <gr/gr_tengan_event.h>

extern "C" {

struct Stage {
    char pad[0x48c];
    grTenganEvent event;
    char pad1[0x6a9 - 0x538];
    unsigned char flag;
    char pad2[2];
    signed int state;
    char pad3[8];
    unsigned char flag2;
    char pad4[0x6e8 - 0x6b9];
    grTenganEvent event2;
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
    signed int unk164;
};

extern const float lbl_59_rodata_0;
extern const float lbl_59_rodata_3C[];
extern char lbl_59_data_224[];
extern char lbl_59_data_234[];

Ground* getGround__5StageFi(Stage*, int);
void startEntity__8grMadeinFv(Ground*);
void endEntity__8grMadeinFv(Ground*);
void setPhase__13grTenganEventFl(grTenganEvent*, signed int);
void setDisplay__15grStadiumVisionFb(Ground*, bool);
void playSeBasic__7stMeleeF5SndIDf(void*, int, float);

void fn_59_2328(Stage* self, float dt) {
    if (self->event.isEvent()) {
        signed int r31 = 0;
        signed int r30 = 0;
        switch (self->flag) {
        case 10:
            r31 = 1;
            r30 = 0;
            break;
        case 13:
            r31 = 2;
            r30 = 1;
            break;
        case 12:
            r31 = 3;
            r30 = 2;
            break;
        case 14:
            r31 = 4;
            r30 = 3;
            break;
        default:
            break;
        }
        if (self->flag2 == 1) {
            r31 = 5;
            r30 = 4;
        }
        Ground* g0 = getGround__5StageFi(self, 0);
        g0->unk164 = r30;
        if (r31 != 0) {
            switch (self->event.getPhase()) {
            case 0:
                self->event.m_manualFramesLeft = lbl_59_rodata_3C[0];
                startEntity__8grMadeinFv(getGround__5StageFi(self, r31));
                self->event.setPhase(1);
                playSeBasic__7stMeleeF5SndIDf(self, 0x1c39, lbl_59_rodata_0);
                break;
            case 1: {
                float f = self->event.m_manualFramesLeft - dt;
                self->event.m_manualFramesLeft = f;
                if (f < lbl_59_rodata_0)
                    self->event.m_manualFramesLeft = lbl_59_rodata_0;
                if (lbl_59_rodata_0 == self->event.m_manualFramesLeft) {
                    endEntity__8grMadeinFv(getGround__5StageFi(self, r31));
                    self->event.m_manualFramesLeft = lbl_59_rodata_3C[0];
                    self->event.setPhase(2);
                    if (self->event.isReadyEnd() == 1) {
                        self->event.end();
                        self->event2.end();
                        self->state = 0;
                        getGround__5StageFi(self, 0)->setAnimation(0, 0, lbl_59_data_224, 0, 0);
                        getGround__5StageFi(self, 0)->setAnimation(0, 0, lbl_59_data_234, 0, 0);
                        setDisplay__15grStadiumVisionFb(getGround__5StageFi(self, 0), 0);
                        self->event2.start();
                    }
                }
                break;
            }
            case 2: {
                float f = self->event.m_manualFramesLeft - dt;
                self->event.m_manualFramesLeft = f;
                if (f < lbl_59_rodata_0)
                    self->event.m_manualFramesLeft = lbl_59_rodata_0;
                if (lbl_59_rodata_0 == self->event.m_manualFramesLeft) {
                    self->event.setPhase(0);
                }
                break;
            }
            default:
                break;
            }
        }
    }
}

}
