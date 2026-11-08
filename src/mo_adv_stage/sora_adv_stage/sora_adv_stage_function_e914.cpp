#include <types.h>
#pragma force_active on

class Object_vptr_3c_base { public: char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
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
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115(s32);
};

struct Params {
    f32 f0;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
};

struct Ctl {
    char pad[0x18];
    u8 b18;
};

struct StageMgr {
    char pad0[0xC];
    Object_vptr_3c* unkC;
    Params* unk10;
    s8 unk14;
    u8 unk15;
    char pad16[2];
    void* unk18;
    Ctl* unk1C;
};

extern "C" {
void* getInstance__9emManagerFv();
void removeEnemyAll__9emManagerFv(void*);
void fn_40_50DC(void* self, u8 id);
void fn_40_51F4(void* self, u8 id);
void fn_40_7CAC(void* self);
void fn_27_109294(void* self, s32 val);
void* fn_27_232338(void* self, void* key);
void fn_27_2346EC(void* self, u8 val);
void fn_27_2323A0(void* self, StageMgr* p);
void fn_27_2344E8(void* self, f32 f);
void fn_27_234660(void* self, void* p);
void playSE__9sndSystemF5SndIDiiii(void* snd, s32 id, s32 a, s32 b, s32 c, s32 d);
extern u32 lbl_41_bss_30;
extern void* g_ftManager;
extern void* g_stTriggerMng;
extern void* g_sndSystem;

void fn_40_E914(StageMgr* self) {
    void* r30;
    self->unk14 = 1;
    if (lbl_41_bss_30 != 0) {
        removeEnemyAll__9emManagerFv(getInstance__9emManagerFv());
    }
    if (self->unk15 == 0) {
        fn_40_50DC(self->unkC, self->unk10->b4);
    } else {
        fn_40_51F4(self->unkC, self->unk10->b4);
    }
    self->unkC->slot115(0);
    if (self->unk10->b6 != 0) {
        fn_27_109294(g_ftManager, 0);
    }
    r30 = fn_27_232338(g_stTriggerMng, (char*)self->unk10 + 8);
    if (r30 != 0) {
        fn_27_2346EC(r30, 1);
    }
    fn_27_2323A0(g_stTriggerMng, self);
    if (self->unk10->b7 == 0) {
        fn_27_2344E8(self->unk18, self->unk10->f0);
    } else if (self->unk10->b7 == 1) {
        fn_27_234660(self->unk18, r30);
    }
    if (self->unk10->b5 != 0) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x227B, -1, 0, 0, -1);
    }
    self->unk1C->b18 = 0;
    fn_40_7CAC(self->unkC);
}
}
