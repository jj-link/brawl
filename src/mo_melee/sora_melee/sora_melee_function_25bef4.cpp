#include <types.h>
#pragma force_active on

extern "C" void* g_stTriggerMng;
extern "C" void* g_GameGlobal;
extern "C" u16 fn_27_23345C(void*, u32);

struct stDestroyBossParamCommon {
    int f0;
    int f4;
    float f8;
    int fC;
    int f10;
    int f14;
};

struct AdvFlags {
    u8 a : 1;
    u8 flag : 1;
    u8 rest : 6;
};

struct StageBase { char pad[0x3c]; };
class StageObj : public StageBase {
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
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual stDestroyBossParamCommon slot111(u32);
    virtual void slot112();
    virtual void slot113(int);

    char _pad40[4];
    int unk44;
    char _pad48[0x19a - 0x48];
    u8 unk19a;
};

extern "C" StageObj* lbl_27_bss_5668;

struct Self {
    char pad[0x48];
    int unk48;
    int unk4C;
    u8 unk50;
    bool unk51;
    char pad52[2];
    stDestroyBossParamCommon param;
};

static inline StageObj* getStage() {
    StageObj* s;
    if (lbl_27_bss_5668 != 0 && lbl_27_bss_5668->unk44 == 0x3d) {
        s = lbl_27_bss_5668;
    } else {
        s = 0;
    }
    return s;
}

extern "C" void fn_27_25BEF4(Self* self) {
    u32 i = 0;
    u32 count = *(u32*)((char*)g_stTriggerMng + 0x50);
    s8 flag;
    while (i < count) {
        if ((s32)fn_27_23345C(g_stTriggerMng, i) == 0x3a) {
            flag = 1;
            goto done;
        }
        i++;
    }
    flag = 0;
done:
    self->unk50 = flag;

    AdvFlags* adv = (AdvFlags*)((u8*)(*(void**)((char*)g_GameGlobal + 0x30)) + 0x4924);
    self->unk51 = adv->flag;

    if (flag != 0) {
        self->param = getStage()->slot111(1);
    } else if (self->unk51) {
        self->param = getStage()->slot111(2);
    } else {
        self->param = getStage()->slot111(0);
    }
    self->unk4C = 0;

    StageObj* s = lbl_27_bss_5668;
    if (s != 0) {
        if (s->unk19a == 0) {
            self->unk48 = 2;
        } else {
            self->unk48 = 8;
        }
        s->slot113(1);
    }
}
