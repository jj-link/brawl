#include <types.h>
#pragma force_active on

struct Self_base { char pad[0x3c]; };

class Self : public Self_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    char _pad[0x1a4 - 0x40];
    char* m_triggerBase;
    char _pad2[0x1b1 - 0x1a8];
    u8 m_flag;
    char _pad3[0x1b4 - 0x1b2];
    float m_value;
};

extern "C" unsigned int getTriggerFlag__12stTriggerMngFP13stTriggerDatab(void* mng, void* data, unsigned int defaultFlag);
extern "C" void* g_stTriggerMng;
extern "C" const float lbl_40_rodata_818[7];

extern "C" void fn_40_3BB24(Self* self) {
    const float* rodata = lbl_40_rodata_818;
    self->m_flag = 1;
    self->m_value = rodata[1];
    int off;
    int i = 0;
    off = 0;
    for (; i < 0x28; i++, off += 4) {
        if (getTriggerFlag__12stTriggerMngFP13stTriggerDatab(g_stTriggerMng, self->m_triggerBase + off + 0x90, 1) == 0) {
            self->m_flag = 0;
            break;
        }
    }
    if ((u32)self->m_flag == 1) {
        self->m_value = rodata[6];
        self->slot99();
    } else {
        float add = rodata[3];
        for (int j = 0; j < 0x28; j++) {
            if (getTriggerFlag__12stTriggerMngFP13stTriggerDatab(g_stTriggerMng, self->m_triggerBase + j * 4 + 0x90, 0) == 1) {
                self->m_value += add;
            }
        }
    }
}
