#include <ai/ai_mgr.h>
#include <ip/ip_human.h>
#include <mt/mt_prng.h>
#include <so/controller/so_controller_impl.h>
#include <st/stage.h>
#include <cstddef>
#include <cmath>

// Local ABI views of externally owned AI storage; offset names do not claim original semantics.
struct AiInput;
struct AiFighterState;
struct AiScript;

struct AiEnvironmentOwnerView {
    u8 pad0[0x1C];
    u32 unk1C;
};

struct AiEnvironmentView {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    u8 pad28[0x18];
    u32 unk40;
    AiEnvironmentOwnerView* unk44;
    u32 unk48;
};

struct AiQueryRecordView {
    s32 unk0;
    u8 pad4[0x24];
    f32 unk28;
    f32 unk2C;
    u8 pad30[0x26];
    s8 unk56;
    u8 pad57[9];
    u32 unk60;
};

struct AiQueryPoolView {
    u8 pad0[0x191C];
    u8 unk191C;
    u8 pad191D[3];
};

struct AiPredictionDataView {
    u8 pad0[0xA];
    u8 unkA;
    u8 padB[0x29];
    f32 unk34;
    f32 unk38;
    f32 unk3C;
};

struct AiPredictionEntryView {
    u8 pad0[8];
    AiPredictionDataView* unk8;
    s32 unkC;
};

struct AiManagerDataView {
    u8 pad0[0x1F];
    s8 unk1F;
};

struct StageAiDataView {
    u8 flag0;
    u8 unk1;
    u8 code2;
    u8 pad3[5];
    u8 unk8;
    u8 unk9;
};

struct AiParameterData;
struct AiAttackData;

struct AiHistory { Vec2f samples[16]; u32 masks[16]; s32 index; };

struct AiParameters {
    /* 0x00 */ AiParameterData* unk0;
    /* 0x04 */ AiAttackData* unk4;
    /* 0x08 */ s8 level;
    /* 0x09 */ char pad9[7];
    /* 0x10 */ f32 unk10;
    /* 0x14 */ char pad14[4];
    /* 0x18 */ f32 unk18;
    /* 0x1C */ char pad1C[0xC];
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ char pad30[0x14];
    /* 0x44 */ u8 unk44;
    /* 0x45 */ u8 unk45;
    /* 0x46 */ u8 unk46;
    /* 0x47 */ u8 unk47;
    /* 0x48 */ char pad48[0x38];
};

struct AiScript {
    /* 0x000 */ char pad0[0x70];
    /* 0x070 */ AiInput *input;
    /* 0x074 */ AiFighterState *fighter;
    /* 0x078 */ u16 action;
    /* 0x07A */ char pad7A[0x26];
    /* 0x0A0 */ f32 unkA0;
    /* 0x0A4 */ char padA4[0x3C];
    /* 0x0E0 */ f32 unkE0;
    /* 0x0E4 */ f32 unkE4;
    /* 0x0E8 */ char padE8[0x10];
    /* 0x0F8 */ s32 unkF8;
    /* 0x0FC */ u32 unkFC;
    /* 0x100 */ char pad100[8];
    /* 0x108 */ s32 unk108;
    /* 0x10C */ s32 unk10C;
    /* 0x110 */ char pad110[4];
};

struct AiFighterState {
    /* 0x000 */ char pad0[4];
    /* 0x004 */ u8 unk4;
    /* 0x005 */ char pad5[0x4B];
    /* 0x050 */ s32 unk50;
    /* 0x054 */ char pad54[8];
    /* 0x05C */ Vec2f vector5C;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06C */ f32 unk6C;
    /* 0x070 */ char pad70[4];
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07C */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ char pad88[4];
    /* 0x08C */ f32 unk8C;
    /* 0x090 */ char pad90[0x10];
    /* 0x0A0 */ f32 unkA0;
    /* 0x0A4 */ char padA4[4];
    /* 0x0A8 */ s16 unkA8;
    /* 0x0AA */ char padAA[2];
    /* 0x0AC */ s32 unkAC;
    /* 0x0B0 */ char padB0[4];
    /* 0x0B4 */ s32 unkB4;
    /* 0x0B8 */ char padB8[4];
    /* 0x0BC */ AiEnvironmentView* unkBC;
    /* 0x0C0 */ u8 unkC0;
    /* 0x0C1 */ char padC1[3];
    /* 0x0C4 */ f32 unkC4;
    /* 0x0C8 */ s32 unkC8;
    /* 0x0CC */ char padCC[0x10];
    /* 0x0DC */ f32 unkDC;
    /* 0x0E0 */ char padE0[4];
    /* 0x0E4 */ AiHistory history;
    /* 0x1A8 */ char pad1A8[4];
    /* 0x1AC */ s32 unk1AC;
    /* 0x1B0 */ s32 unk1B0;
    /* 0x1B4 */ s32 unk1B4;
    /* 0x1B8 */ u8 unk1B8;
    /* 0x1B9 */ u8 unk1B9;
    /* 0x1BA */ u8 unk1BA;
    /* 0x1BB */ char pad1BB[1];
    /* 0x1BC */ u8 unk1BC;
    /* 0x1BD */ u8 unk1BD;
    /* 0x1BE */ char pad1BE[2];
    /* 0x1C0 */ f32 unk1C0;
};

struct AiInput {
    /* 0x000 */ char pad0[0xC];
    /* 0x00C */ u32 buttons;
    /* 0x010 */ Vec2f mainStick;
    /* 0x018 */ char pad18[0x1C];
    /* 0x034 */ AiInput *partner;
    /* 0x038 */ char pad38[4];
    /* 0x03C */ u16 flags;
    /* 0x03E */ u8 unk3E;
    /* 0x03F */ u8 unk3F;
    /* 0x040 */ u8 unk40;
    /* 0x041 */ s8 unk_41;
    /* 0x042 */ s8 fighterId;
    /* 0x043 */ u8 unk43;
    /* 0x044 */ AiScript *script;
    /* 0x048 */ s32 mode;
    /* 0x04C */ char pad4C[4];
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ s16 unk58;
    /* 0x05A */ s16 unk5A;
    /* 0x05C */ char pad5C[2];
    /* 0x05E */ s16 unk5E;
    /* 0x060 */ u8 unk60;
    /* 0x061 */ u8 unk61;
    /* 0x062 */ u8 unk62;
    /* 0x063 */ u8 unk63;
    /* 0x064 */ char pad64[1];
    /* 0x065 */ u8 unk65;
    /* 0x066 */ s8 counter66;
    /* 0x067 */ u8 unk67;
    /* 0x068 */ u16 unk68;
    /* 0x06A */ s16 unk6A;
    /* 0x06C */ char pad6C[4];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ u8 unk74;
    /* 0x075 */ char pad75[1];
    /* 0x076 */ u8 unk76;
    /* 0x077 */ u8 unk77;
    /* 0x078 */ f32 unk78;
    /* 0x07C */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ s32 unk84;
    /* 0x088 */ s16 unk88;
    /* 0x08A */ s16 unk8A;
    /* 0x08C */ f32 unk8C;
    /* 0x090 */ AiParameters parameters;
    /* 0x110 */ s8 targetId;
    /* 0x111 */ s8 targetSelected;
    /* 0x112 */ char pad112[1];
    /* 0x113 */ u8 unk113;
    /* 0x114 */ u8 unk114;
    /* 0x115 */ char pad115[1];
    /* 0x116 */ u16 flags116;
    /* 0x118 */ f32 value118;
};

struct AiManagerView {
    /* 0x000 */ char pad0[0x360];
    /* 0x360 */ f32 unk360;
    /* 0x364 */ f32 unk364;
    /* 0x368 */ char pad368[4];
    /* 0x36C */ f32 unk36C;
    /* 0x370 */ s32 unk370;
    /* 0x374 */ char pad374[0x14];
};

struct AiConstantPool {
    f32 f00[34];
    f64 d88;
    f64 d90;
    f32 f98[48];
    f64 d158;
    f64 d160;
    f32 f168[68];
};

struct LocalPoint3Storage { Vec2f xy; f32 z; };

static_assert(sizeof(AiInput) == 0x11C, "AI update ABI layout");
static_assert(offsetof(AiInput, fighterId) == 0x42, "AI update ABI layout");
static_assert(offsetof(AiInput, script) == 0x44, "AI update ABI layout");
static_assert(offsetof(AiInput, parameters) == 0x90, "AI update ABI layout");
static_assert(offsetof(AiInput, targetId) == 0x110, "AI update ABI layout");
static_assert(offsetof(AiInput, value118) == 0x118, "AI update ABI layout");
static_assert(sizeof(AiFighterState) == 0x1C4, "AI update ABI layout");
static_assert(offsetof(AiFighterState, vector5C) == 0x5C, "AI update ABI layout");
static_assert(offsetof(AiFighterState, unk64) == 0x64, "AI update ABI layout");
static_assert(offsetof(AiFighterState, unkBC) == 0xBC, "AI update ABI layout");
static_assert(offsetof(AiFighterState, history) == 0xE4, "AI update ABI layout");
static_assert(sizeof(AiScript) == 0x114, "AI update ABI layout");
static_assert(sizeof(AiParameters) == 0x80, "AI update ABI layout");
static_assert(sizeof(AiHistory) == 0xC4, "AI update ABI layout");
static_assert(sizeof(AiManagerView) == 0x388, "AI update ABI layout");
static_assert(sizeof(AiEnvironmentView) == 0x4C, "AI update ABI layout");
static_assert(sizeof(AiQueryRecordView) == 0x64, "AI update ABI layout");
static_assert(sizeof(AiQueryPoolView) == 0x1920, "AI update ABI layout");
static_assert(sizeof(AiPredictionEntryView) == 0x10, "AI update ABI layout");
static_assert(sizeof(StageAiDataView) == 0xA, "AI update ABI layout");
static_assert(sizeof(LocalPoint3Storage) == 0xC, "AI update ABI layout");
static_assert(sizeof(AiConstantPool) == 0x278, "AI update ABI layout");
static_assert(offsetof(AiConstantPool, d88) == 0x88, "AI update ABI layout");
static_assert(offsetof(AiConstantPool, d90) == 0x90, "AI update ABI layout");
static_assert(offsetof(AiConstantPool, d158) == 0x158, "AI update ABI layout");
static_assert(offsetof(AiConstantPool, d160) == 0x160, "AI update ABI layout");

extern "C" {
extern const AiConstantPool lbl_27_rodata_2CF0;
extern u8 lbl_27_bss_5520;
extern f32 lbl_805A17F0;
extern Stage* lbl_27_bss_5668;
AiFighterState* fn_27_1F1F58(s8* fighterId);
void fn_27_1F9FBC(AiInput* self, s32 mode, s8* fighterId, u32 script, s32 argument);
s8 fn_27_1FE1C0(AiInput* self, f32* outValue, s32 argument);
s32 fn_27_1E8E3C(void);
s32 fn_27_1E8E58(void);
s32 fn_27_1F1300(aiMgr*, Vec2f*, f32);
s32 fn_27_1F1E90(aiMgr*, s8*);
AiFighterState* fn_27_1F2054(void);
AiManagerDataView* fn_27_1F21B8(void);
StageAiDataView* fn_27_1F2B58(s32);
s32 fn_27_1F2CBC(s8*);
s32 fn_27_1F2E20(AiEnvironmentView*, s32);
AiQueryPoolView* fn_27_1F8A7C(void);
void fn_27_1F8A8C(AiInput*, Vec2f*, u32, s8*, s32);
void fn_27_1FAE10(Vec2f*);
void fn_27_1FAEDC(AiInput*, Vec2f*, u32*, f32, f32, f32);
void fn_27_1FB0A8(AiInput*, Vec2f*, u32*);
s32 fn_27_1FB478(AiInput*, Vec2f*, u32*);
s32 fn_27_1FB964(AiInput*, Vec2f*, u32*);
s32 fn_27_1FBEE0(AiInput*, Vec2f*, u32*);
void fn_27_1FC280(AiInput*, Vec2f*, u32*);
void fn_27_1FC8C4(AiInput*, Vec2f*, u32*);
void fn_27_1FD190(AiInput*);
void fn_27_1FD9EC(AiInput*, Vec2f*, u32*);
void fn_27_1FE5A4(AiInput*, Vec2f*, u32*);
void fn_27_1FE78C(AiInput*, Vec2f*, u32*);
void fn_27_1FF328(AiInput*, Vec2f*, u32*);
void fn_27_1FFDC0(AiInput*, Vec2f*, u32*);
void fn_27_203274(AiInput*, Vec2f*, u32*);
void fn_27_20362C(AiInput*, Vec2f*, u32*);
void fn_27_2037A4(AiInput*, Vec2f*, u32*);
void fn_27_204148(AiInput*, Vec2f*, u32*);
void fn_27_204B64(AiInput*, Vec2f*, u32*);
void fn_27_2051AC(AiInput*, Vec2f*, u32*);
void fn_27_2056D0(AiInput*, Vec2f*, u32*);
void fn_27_205E2C(AiInput*, Vec2f*, u32*);
void fn_27_2061B8(AiInput*, Vec2f*, u32*);
void fn_27_206428(AiInput*, Vec2f*, u32*);
void fn_27_2066D4(AiInput*, Vec2f*, u32*);
void fn_27_206A68(AiInput*, Vec2f*, u32*);
s32 fn_27_20B568(AiFighterState*);
s32 fn_27_20B610(AiFighterState*, Vec2f*);
s32 fn_27_20B63C(AiFighterState*);
s32 fn_27_20B668(AiFighterState*);
s32 fn_27_20B694(AiFighterState*, u32);
s32 fn_27_20B6AC(AiFighterState*, u32, s32);
s32 fn_27_20B6DC(AiFighterState*);
f32 fn_27_20B758(AiFighterState*, s8*, f32);
f32 fn_27_20B898(AiFighterState*, s8*, f32);
void fn_27_20B9E0(AiFighterState*, Vec3f*, s8*, f32);
f32 fn_27_20BC28(AiFighterState*, s8*);
f32 fn_27_20BCBC(AiFighterState*, Vec2f*, f32);
Vec2f fn_27_20BDE8(AiFighterState*);
AiPredictionEntryView* fn_27_20C010(AiFighterState*);
void fn_27_20C77C(AiScript*, Vec2f*, u32*);
void fn_27_20DB40(AiScript*, u32, s8*, u32, u32);
u32 fn_27_20E30C(AiScript*, u32, u8*, u8*, u8*);
s32 fn_27_218BA8(AiQueryPoolView*, Vec2f*, u32, s32, f32);
AiQueryRecordView* fn_27_219188(AiQueryPoolView*);
AiEnvironmentView* fn_27_21A14C(AiQueryRecordView*);
f32 fn_27_21F1BC(s8*);
f32 fn_27_21F244(s8*);
f32 fn_27_21F2CC(s8*);
f32 fn_27_21F434(AiParameters*, AiFighterState*);
f32 fn_27_21F484(AiParameters*, AiFighterState*);
void fn_27_21FFE4(AiHistory*, Vec2f*, u32*);
void fn_27_220034(AiHistory*, s32, Vec2f*, u32*);
Vec2f fn_27_22009C(AiHistory*, s32);
u32 fn_27_2200FC(AiHistory*, s32);
}

extern "C" void fn_27_1F38E4(AiInput* self) {
    const AiConstantPool* constants = &lbl_27_rodata_2CF0;
    LocalPoint3Storage sp1B4;
    LocalPoint3Storage sp1A8;
    Vec3f sp19C;
    LocalPoint3Storage sp190;
    LocalPoint3Storage sp184;
    Vec3f sp178;
    Vec2f sp170;
    Vec2f stick;
    Vec2f sp160;
    f32 sp15C;
    f32 sp158;
    Vec2f sp150;
    Vec2f sp148;
    Vec2f partnerStick;
    Vec2f sp138;
    Vec2f sp130;
    Vec2f sp128;
    Vec2f sp120;
    Vec2f sp118;
    Vec2f sp110;
    Vec2f sp108;
    Vec2f sp100;
    Vec2f spF8;
    Vec2f appliedStick;
    Vec2f forwardedStick;
    Vec2f spE0;
    Vec2f spD8;
    Vec2f spD0;
    Vec2f spC8;
    Vec2f spC0;
    u32 buttons;
    u32 partnerButtons;
    u32 humanButtons;
    s8 spAC;
    s8 spA8;
    s8 spA4;
    s8 spA0;
    s8 sp9C;
    s8 sp98;
    s8 sp94;
    s8 sp90;
    s8 sp8C;
    s8 sp88;
    s8 sp84;
    s8 sp80;
    s8 sp7C;
    s8 sp78;
    s8 sp74;
    s8 sp70;
    s8 sp6C;
    s8 sp68;
    s8 sp64;
    s8 sp60;
    s8 sp5C;
    s8 sp58;
    s8 sp54;
    s8 sp50;
    s8 sp4C;
    s8 sp48;
    s8 sp44;
    s8 sp40;
    s8 sp3C;
    s8 sp38;
    s8 sp34;
    s8 sp30;
    s8 sp2C;
    s8 sp28;
    s8 sp24;
    s8 sp20;
    s8 sp1C;
    s8 sp18;
    s8 sp14;
    s8 sp10;
    s8 spC;
    s8 sp8;
    AiFighterState *partnerState;
    AiFighterState *temp_r21_2;
    AiFighterState *temp_r21_3;
    AiFighterState *fighterState;
    AiFighterState *temp_r3_20;
    AiFighterState *temp_r3_26;
    AiFighterState *temp_r3_31;
    AiFighterState *temp_r3_33;
    AiFighterState *temp_r3_38;
    AiFighterState *temp_r3_46;
    AiFighterState *temp_r3_4;
    AiFighterState *temp_r3_6;
    AiInput *partner;
    AiInput *temp_r3_61;
    aiMgr* temp_r21_12;
    AiScript *temp_r3_17;
    AiScript *temp_r3_25;
    AiScript *temp_r3_42;
    AiScript *temp_r4_4;
    AiScript *temp_r4_5;
    AiScript *temp_r5_6;
    AiScript *temp_r5_7;
    StageAiDataView* temp_r3_55;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f1;
    f32 temp_f1_10;
    f32 temp_f1_11;
    f32 temp_f1_12;
    f32 temp_f1_13;
    f32 temp_f1_14;
    f32 temp_f1_15;
    f32 temp_f1_16;
    f32 temp_f1_17;
    f32 temp_f1_18;
    f32 temp_f1_19;
    f32 temp_f1_20;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f1_8;
    f32 temp_f1_9;
    f32 temp_f29;
    f32 temp_f29_10;
    f32 temp_f29_11;
    f32 temp_f29_12;
    f32 temp_f29_13;
    f32 temp_f29_2;
    f32 temp_f29_3;
    f32 temp_f29_4;
    f32 temp_f29_5;
    f32 temp_f29_6;
    f32 temp_f29_7;
    f32 temp_f29_8;
    f32 temp_f29_9;
    f32 temp_f2;
    f32 temp_f2_10;
    f32 temp_f2_11;
    f32 temp_f2_12;
    f32 temp_f2_13;
    f32 temp_f2_14;
    f32 temp_f2_15;
    f32 temp_f2_16;
    f32 temp_f2_17;
    f32 temp_f2_18;
    f32 temp_f2_19;
    f32 temp_f2_20;
    f32 temp_f2_21;
    f32 temp_f2_22;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 temp_f2_7;
    f32 temp_f2_8;
    f32 temp_f2_9;
    f32 temp_f30;
    f32 temp_f30_2;
    f32 temp_f30_3;
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f31_3;
    f32 temp_f31_4;
    f32 temp_f31_5;
    f32 temp_f31_6;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f3_4;
    f32 temp_f3_5;
    f32 temp_f3_6;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f4_4;
    f32 temp_f5;
    f32 var_f0;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f29;
    f32 var_f29_2;
    f32 var_f29_3;
    f32 var_f29_4;
    f32 var_f29_5;
    f32 var_f29_6;
    f32 var_f29_7;
    f32 var_f29_8;
    f32 var_f31;
    f32 var_f31_2;
    f32 var_f31_3;
    f32 var_f3;
    f32 var_f3_2;
    s16 temp_r0_26;
    s16 temp_r0_32;
    s16 temp_r3_13;
    s16 temp_r3_14;
    s16 temp_r3_28;
    s16 temp_r3_29;
    s16 temp_r3_34;
    s16 temp_r3_36;
    s16 temp_r3_3;
    s16 temp_r3_58;
    s16 temp_r4_3;
    s16 var_r23;
    s32 temp_cr0_lt;
    s32 temp_cr1_eq;
    s32 temp_r0_10;
    s32 temp_r0_11;
    s32 temp_r0_12;
    s32 temp_r0_13;
    s32 temp_r0_14;
    s32 temp_r0_15;
    s32 temp_r0_18;
    s32 temp_r0_20;
    s32 temp_r0_22;
    s32 temp_r0_23;
    s32 temp_r0_24;
    s32 temp_r0_30;
    s32 temp_r0_31;
    s32 temp_r0_33;
    s32 temp_r0_35;
    s32 temp_r0_38;
    s32 temp_r0_39;
    s32 temp_r0_3;
    s32 temp_r0_41;
    s32 temp_r0_43;
    s32 temp_r0_50;
    s32 temp_r0_5;
    s32 temp_r0_6;
    s32 temp_r0_7;
    s32 temp_r0_8;
    s32 temp_r21_14;
    s32 temp_r3_15;
    s32 temp_r3_22;
    s32 temp_r3_2;
    s32 temp_r3_32;
    s32 temp_r3_37;
    s32 temp_r3_41;
    s32 temp_r3_45;
    s32 temp_r3_48;
    s32 temp_r3_7;
    s32 temp_r4;
    s32 temp_r4_10;
    s32 temp_r4_11;
    s32 temp_r4_2;
    s32 temp_r4_7;
    s32 temp_r5_4;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r21;
    s32 var_r21_2;
    s32 var_r21_3;
    s32 var_r21_4;
    s32 var_r21_6;
    s32 var_r22;
    s32 var_r22_3;
    s32 var_r22_4;
    s32 var_r22_5;
    s32 modeCandidate;
    s32 var_r3;
    s32 var_r3_2;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r5;
    s8 temp_r21_13;
    u16 temp_r0_21;
    u16 temp_r0_28;
    u16 temp_r0_29;
    u16 temp_r0_37;
    u16 temp_r0_42;
    u16 temp_r0_46;
    u16 temp_r0_48;
    u16 temp_r0_4;
    u16 temp_r21_15;
    u16 temp_r3;
    u16 temp_r3_11;
    u16 temp_r3_30;
    u16 temp_r4_16;
    u16 temp_r4_17;
    u16 temp_r4_6;
    u16 temp_r4_8;
    u16 temp_r5;
    u32 temp_r22_4;
    u32 temp_r22_5;
    u32 temp_r22_6;
    u32 temp_r22_7;
    u32 temp_r3_47;
    u32 var_r22_2;
    u32 var_r3_3;
    u32 var_r6;
    u32 var_r6_2;
    u8 temp_r0;
    u8 temp_r0_16;
    u8 temp_r0_17;
    u8 temp_r0_19;
    u8 temp_r0_25;
    u8 temp_r0_27;
    u8 temp_r0_2;
    u8 temp_r0_34;
    u8 temp_r0_36;
    u8 temp_r0_40;
    u8 temp_r0_44;
    u8 temp_r0_45;
    u8 temp_r0_47;
    u8 temp_r0_49;
    u8 temp_r0_9;
    u8 temp_r21_10;
    u8 temp_r21_11;
    u8 temp_r21_16;
    u8 temp_r21_17;
    u8 temp_r21_18;
    u8 temp_r21_4;
    u8 temp_r21_5;
    u8 temp_r21_6;
    u8 temp_r21_7;
    u8 temp_r21_8;
    u8 temp_r21_9;
    u8 temp_r22_2;
    u8 temp_r22_3;
    u8 temp_r27;
    u8 temp_r3_21;
    u8 temp_r3_27;
    u8 temp_r3_39;
    u8 temp_r3_40;
    u8 temp_r3_44;
    u8 temp_r3_52;
    u8 temp_r3_53;
    u8 temp_r3_54;
    u8 temp_r3_56;
    u8 temp_r3_57;
    u8 temp_r3_59;
    u8 temp_r3_5;
    u8 temp_r3_60;
    u8 temp_r4_12;
    u8 temp_r4_14;
    u8 temp_r4_15;
    u8 temp_r4_9;
    u8 temp_r5_2;
    u8 temp_r5_3;
    u8 temp_r5_5;
    u8 temp_r6;
    u8 var_r0_3;
    u8 var_r21_5;
    u8 var_r24;
    StageAiDataView* stageData;
    AiEnvironmentView* temp_r3_10;
    AiEnvironmentView* temp_r3_12;
    AiPredictionEntryView* temp_r3_16;
    AiPredictionDataView* temp_r3_18;
    AiPredictionDataView* temp_r3_19;
    AiPredictionEntryView* temp_r3_23;
    AiPredictionEntryView* temp_r3_24;
    AiEnvironmentView* temp_r3_35;
    AiEnvironmentView* temp_r3_43;
    AiEnvironmentView* temp_r3_49;
    AiEnvironmentView* temp_r3_50;
    AiQueryPoolView* temp_r3_8;
    AiQueryRecordView* temp_r3_9;
    AiEnvironmentView* temp_r6_2;
    AiEnvironmentView* temp_r6_3;
    AiEnvironmentOwnerView* temp_r7;
    AiEnvironmentOwnerView* temp_r7_2;
    AiQueryRecordView* var_r25;

    f32 sp19CLengthSq;
    temp_r5 = self->flags;
    if (!(temp_r5 & 0x8000)) {
        if ((fn_27_1F1E90(g_aiMgr, &self->fighterId) != 0) || ((u8) self->unk113 == 0x19)) {
            reinterpret_cast<IpHuman*>(self)->IpHuman::update();
        }
    } else if ((temp_r5 & 8) || (fn_27_1F2CBC(&self->fighterId) <= 0)) {
        fighterState = fn_27_1F1F58(&self->fighterId);
        if (fn_27_1E8E3C() == 0) {
            if ((fn_27_1F1E90(g_aiMgr, &self->fighterId) != 0) || ((u8) self->unk113 == 0x19) || (self->parameters.unk0 == NULL)) {
                reinterpret_cast<IpHuman*>(self)->IpHuman::update();
                return;
            }
            if (fn_27_1E8E58() != 0) {
                temp_f2 = fighterState->vector5C.m_x;
                sp170.m_x = constants->f00[0];
                sp170.m_y = constants->f00[0];
                if (temp_f2 < (constants->f00[1] + reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk360)) {
                    sp170.m_x = constants->f00[2];
                } else if (temp_f2 > (reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk364 - constants->f00[1])) {
                    sp170.m_x = constants->f00[3];
                }
                Vec2f::copy(sp138, sp170);
                partner = self->partner;
                self->mainStick.m_x = sp138.m_x;
                self->mainStick.m_y = sp138.m_y;
                self->buttons = 0x8000;
                if ((partner != NULL) && !(partner->flags & 8)) {
                    partnerState = fn_27_1F1F58(&partner->fighterId);
                    temp_f2_2 = fn_27_1F1F58(&self->fighterId)->vector5C.m_x;
                    temp_f0 = temp_f2_2 - constants->f00[4];
                    temp_f3 = partnerState->vector5C.m_x;
                    spD8.m_x = constants->f00[0];
                    spD8.m_y = constants->f00[0];
                    if (temp_f3 < temp_f0) {
                        spD8.m_x = constants->f00[2];
                    } else if (temp_f3 > (constants->f00[4] + temp_f2_2)) {
                        spD8.m_x = constants->f00[3];
                    }
                    Vec2f::copy(spE0, spD8);
                    partner->mainStick.m_x = spE0.m_x;
                    partner->mainStick.m_y = spE0.m_y;
                    partner->buttons = 0x8000;
                }
            }
        } else if (fighterState->unk50 & 0x80000000) {
            if ((fn_27_1F1E90(g_aiMgr, &self->fighterId) != 0) || ((u8) self->unk113 == 0x19) || (self->parameters.unk0 == NULL)) {
                reinterpret_cast<IpHuman*>(self)->IpHuman::update();
                humanButtons = self->buttons & 0xFFFF7FFF;
                Vec2f::copy(sp130, self->mainStick);
                fn_27_21FFE4(&fighterState->history, &sp130, &humanButtons);
            } else {
                buttons = 0;
                stick.m_x = constants->f00[0];
                stick.m_y = constants->f00[0];
                stageData = fn_27_1F2B58(0);
                lbl_27_bss_5520 = 0;
                if (((s32) self->mode != 4) && ((temp_r0 = fighterState->unk1BA, ((temp_r0 == 4) != 0)) || (temp_r0 == 6) || ((s32) fighterState->unkB4 == 0xBE))) {
                    self->unk62 = 0;
                    temp_r3 = self->flags | 1;
                    self->flags = temp_r3;
                    if (temp_r3 & 1) {
                        self->flags = temp_r3 & 0xFFFE;
                        self->targetId = (s8) (u8) self->fighterId;
                        self->unk6A = 0;
                    }
                    if ((s16) self->unk58 < 0) {
                        self->unk58 = 0;
                    }
                    self->unk5A = 0;
                    spA8 = -1;
                    fn_27_1F9FBC(self, 4, &spA8, 0U, 0);
                }
                if (((s32) self->mode != 9) && ((u8) fighterState->unk1BA == 8)) {
                    spA4 = -1;
                    fn_27_1F9FBC(self, 9, &spA4, 0U, 0);
                }
                if (((s32) self->mode != 0xA) && ((temp_r0_2 = self->unk113, (((s32) temp_r0_2 < 4) == 0)) || ((s32) temp_r0_2 < 1)) && ((u8) fighterState->unk1BA == 9)) {
                    if ((u16) self->script->action == 0x3020) {
                        temp_f1 = self->unk7C - constants->f00[6];
                        self->unk78 = constants->f00[5];
                        self->unk7C = temp_f1;
                        if (temp_f1 < constants->f00[0]) {
                            self->unk7C = constants->f00[0];
                        }
                        temp_f1_2 = self->unk80 + constants->f00[2];
                        self->unk80 = temp_f1_2;
                        if (temp_f1_2 > constants->f00[5]) {
                            self->unk80 = constants->f00[5];
                        }
                    }
                    spA0 = -1;
                    fn_27_1F9FBC(self, 0xA, &spA0, 0U, 0);
                }
                if (((s32) self->mode != 0xE) && ((u8) fighterState->unk1BA == 0xF)) {
                    sp9C = -1;
                    fn_27_1F9FBC(self, 0xE, &sp9C, 0U, 0);
                }
                if (((u16) self->script->action != 0x1100) && (fighterState->unk50 & 0x20) && ((temp_r4 = self->mode, ((temp_r4 == 3) == 0)) || (temp_r0_3 = fighterState->unkAC, ((temp_r0_3 == 0xB) == 0)) || (temp_r0_3 != 0x16))) {
                        switch (temp_r4) {          /* switch 1 */
                        case 0x2:                   /* switch 1 */
                        case 0x5:                   /* switch 1 */
                        case 0x7:                   /* switch 1 */
                        case 0x15:                  /* switch 1 */
                        case 0x16:                  /* switch 1 */
                            sp98 = fn_27_1FE1C0(self, NULL, 0);
                            fn_27_1F9FBC(self, 0x66, &sp98, 0x1100U, 0);
                            break;
                        default:
                    case 0x0:                       /* switch 1 */
                    case 0x1:                       /* switch 1 */
                    case 0x3:                       /* switch 1 */
                    case 0x4:                       /* switch 1 */
                    case 0x6:                       /* switch 1 */
                    case 0x8:                       /* switch 1 */
                    case 0x9:                       /* switch 1 */
                    case 0xA:                       /* switch 1 */
                    case 0xB:                       /* switch 1 */
                    case 0xC:                       /* switch 1 */
                    case 0xD:                       /* switch 1 */
                    case 0xE:                       /* switch 1 */
                    case 0xF:                       /* switch 1 */
                    case 0x10:                      /* switch 1 */
                    case 0x11:                      /* switch 1 */
                    case 0x12:                      /* switch 1 */
                    case 0x13:                      /* switch 1 */
                    case 0x14:                      /* switch 1 */
                        sp94 = fn_27_1FE1C0(self, NULL, 0);
                        fn_27_1F9FBC(self, 0x65, &sp94, 0x1100U, 0);
                    }
                    self->targetSelected = 0;
                }
                temp_r0_4 = self->script->action;
                if ((temp_r0_4 != 0x2010) && (temp_r0_4 != 0x2050) && ((u8) fighterState->unk1BA == 0xE)) {
                    var_r6 = 0x2010;
                    if (fn_27_20B568(fighterState) != 0) {
                        var_r6 = 0x2050;
                    }
                    sp90 = -1;
                    fn_27_1F9FBC(self, 2, &sp90, var_r6, 0);
                }
                if (((s32) self->mode != 0x11) && ((u8) fighterState->unk1BA == 0xA)) {
                    sp8C = -1;
                    fn_27_1F9FBC(self, 0x11, &sp8C, 0U, 0);
                }
                if (((s32) self->mode != 0x12) && ((u8) fighterState->unk1BA == 0xC)) {
                    sp88 = -1;
                    fn_27_1F9FBC(self, 0x12, &sp88, 0U, 0);
                }
                if (((s32) self->mode != 0x13) && ((u8) fighterState->unk1BA == 0x10)) {
                    sp84 = -1;
                    fn_27_1F9FBC(self, 0x13, &sp84, 0U, 0);
                }
                if (((u8) fighterState->unk1BA == 0xD) && (randf() < constants->f00[6])) {
                    buttons |= soController::getButtonMask(soController::Pad_Button_Jump);
                }
                temp_r3_2 = self->mode;
                if ((temp_r3_2 != 7) && (temp_r3_2 != 0x16) && (temp_r3_2 != 3) && (temp_r3_2 != 4) && (temp_r3_2 != 9) && (temp_r3_2 != 0xA) && (temp_r3_2 != 0xE) && (temp_r3_2 != 0x11) && (temp_r3_2 != 0x12) && (temp_r3_2 != 0x13) && (temp_r3_2 != 0x15) && (temp_r3_2 != 0xF)) {
                    temp_r4_2 = fighterState->unk50;
                    if (!(temp_r4_2 & 0x800)) {
                        if ((temp_r3_2 != 0x10) && (temp_r4_2 & 0x1000)) {
                            sp80 = -1;
                            fn_27_1F9FBC(self, 0x10, &sp80, 0U, 0);
                        } else {
                            temp_r3_3 = self->unk5E;
                            if (temp_r3_3 > 0) {
                                self->unk5E = temp_r3_3 - 1;
                                goto block_127;
                            }
                            var_r21 = 1;
                            temp_f2_3 = fighterState->unk68;
                            var_f29 = constants->f00[7] + fn_27_21F1BC(&self->fighterId);
                            if (temp_f2_3 > constants->f00[8]) {
                                var_f29 += constants->f00[9] * (temp_f2_3 - constants->f00[8]);
                            }
                            temp_r3_4 = fn_27_1F2054();
                            if ((temp_r3_4 != NULL) && (fn_27_20B6AC(temp_r3_4, 2U, 0x19) != 0)) {
                                var_r21 = 0;
                            }
                            if (((var_r21 != 0) && (fighterState->unk50 & 0x10000)) || (temp_f2_4 = fighterState->vector5C.m_y, ((temp_f2_4 < (constants->f00[7] + reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk36C)) != 0)) || (temp_f1_3 = fighterState->vector5C.m_x, ((temp_f1_3 < (var_f29 + reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk360)) != 0)) || (temp_f1_3 > (reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk364 - var_f29))) {
                                temp_r21_2 = fn_27_1F1F58(&self->targetId);
                                temp_f2_5 = constants->f00[7] + fn_27_21F1BC(&self->targetId);
                                temp_f1_4 = fighterState->vector5C.m_x;
                                if ((!(temp_f1_4 < (temp_f2_5 + reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk360)) || !(temp_r21_2->vector5C.m_x < temp_f1_4)) && ((temp_f1_5 = fighterState->vector5C.m_x, ((temp_f1_5 > (reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk364 - temp_f2_5)) == 0)) || !(temp_r21_2->vector5C.m_x > temp_f1_5))) {
                                    sp7C = -1;
                                    fn_27_1F9FBC(self, 7, &sp7C, 0U, 0);
                                }
                            } else {
                                temp_r0_5 = reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk370;
                                if (temp_r0_5 != 8) {
                                    if (temp_r0_5 < 8) {
                                        if (temp_r0_5 != 5) {

                                        } else if (temp_f1_3 < self->parameters.unk2C) {
                                            sp74 = -1;
                                            fn_27_1F9FBC(self, 7, &sp74, 0U, 0);
                                        }
                                    } else if (temp_r0_5 != 0x1C) {

                                    } else if (fighterState->unkBC->unk40 & 0x1000) {
                                        sp70 = -1;
                                        fn_27_1F9FBC(self, 7, &sp70, 0U, 0);
                                    }
                                } else if (temp_f2_4 < self->parameters.unk28) {
                                    sp78 = -1;
                                    fn_27_1F9FBC(self, 7, &sp78, 0U, 0);
                                }
                            }
                            if ((s32) self->mode != 7) {
block_127:
                                temp_r3_5 = self->unk63;
                                if ((s8) temp_r3_5 > 0) {
                                    self->unk63 = temp_r3_5 - 1;
                                } else if ((fighterState->unk50 & 0x40) && ((fn_27_20B63C(fighterState) != 0) || (fn_27_20B668(fighterState) != 0) || ((s32) fighterState->unk1AC == 0xD)) && (((s32) self->mode != 0xD) || ((temp_r0_6 = self->unk50, ((temp_r0_6 < 2) == 0)) && (temp_r0_6 < 0xA) && ((s32) self->unk54 > 0x46)))) {
                                    modeCandidate = 0;
                                    if ((s32) fighterState->unk1AC == 0xD) {
                                        modeCandidate = 0xD;
                                    } else {
                                        temp_r3_6 = fn_27_1F1F58(&self->targetId);
                                        temp_r0_7 = self->mode;
                                        temp_r21_3 = temp_r3_6;
                                        if (temp_r0_7 != 6) {
                                            if ((temp_r0_7 < 6) && (temp_r0_7 < 3)) {
                                                if (temp_r0_7 < 1) {

                                                } else {
                                                    temp_r0_8 = fighterState->unk1AC;
                                                    if (temp_r0_8 != 0x21) {
                                                        if (temp_r0_8 < 0x21) {
                                                            if (temp_r0_8 != 0x12) {
                                                                if (temp_r0_8 < 0x12) {
                                                                    if (temp_r0_8 != 4) {
                                                                        goto block_195;
                                                                    }
                                                                    goto block_158;
                                                                }
                                                                if (temp_r0_8 != 0x1F) {
                                                                    goto block_195;
                                                                }
                                                                goto block_158;
                                                            }
                                                            goto block_188;
                                                        }
                                                        if (temp_r0_8 != 0x36) {
                                                            if (temp_r0_8 < 0x36) {
                                                                if (temp_r0_8 != 0x2E) {
                                                                    goto block_195;
                                                                }
                                                                goto block_158;
                                                            }
                                                            if (temp_r0_8 != 0x3A) {
                                                                goto block_195;
                                                            }
                                                            goto block_158;
                                                        }
block_188:
                                                        if (fn_27_20B758(fighterState, &self->targetId, constants->f00[0]) < constants->f00[1]) {
                                                            self->unk63 = 0x14;
                                                            if (randf() < constants->f00[19]) {
                                                                fn_27_1F9FBC(self, 0x66, &self->targetId, 0x31U, 0);
                                                            } else {
                                                                if ((fighterState->unkA0 * fn_27_20BC28(fighterState, &self->targetId)) > constants->f00[0]) {
                                                                    var_r6_2 = 0x72;
                                                                } else {
                                                                    var_r6_2 = 0x71;
                                                                }
                                                                fn_27_1F9FBC(self, 0x66, &self->targetId, var_r6_2, 0);
                                                            }
                                                        } else {
block_195:
                                                            if ((s32) (fighterState->unk1B0 & 6) == 4) {
                                                                var_f29_2 = constants->f00[20];
                                                            } else {
                                                                var_f29_2 = constants->f00[13];
                                                            }
                                                            if (randf() < var_f29_2) {
                                                                modeCandidate = 0xD;
                                                            }
                                                        }
                                                    } else {
block_158:
                                                        if (temp_r0_8 != 0x21) {
                                                            if (temp_r0_8 < 0x21) {
                                                                if (temp_r0_8 != 0x1F) {
                                                                    if (temp_r0_8 < 0x1F) {
                                                                        if (temp_r0_8 != 4) {

                                                                        } else if ((temp_r3_6->unkC4 > constants->f00[11]) && (randf() < constants->f00[12])) {
                                                                            modeCandidate = 0xD;
                                                                        }
                                                                    }
                                                                } else {
                                                                    temp_r22_2 = (u8) self->parameters.level;
                                                                    if (randf() < (constants->f00[10] * (f32) (s8) temp_r22_2)) {
                                                                        modeCandidate = 0xD;
                                                                    }
                                                                }
                                                            } else if (temp_r0_8 != 0x3A) {
                                                                if (temp_r0_8 < 0x3A) {
                                                                    if (temp_r0_8 != 0x2E) {

                                                                    } else if (temp_r3_6->unkC4 > constants->f00[14]) {
                                                                        modeCandidate = 0xD;
                                                                    } else {
                                                                        goto block_178;
                                                                    }
                                                                }
                                                            } else {
block_178:
                                                                if ((s32) fighterState->unk1B4 <= 0) {
                                                                    modeCandidate = 0xD;
                                                                }
                                                            }
                                                        } else if ((temp_r3_6->unkC4 > constants->f00[11]) && (randf() < constants->f00[13])) {
                                                            modeCandidate = 0xD;
                                                        }
                                                        if (modeCandidate == 0xD) {
                                                            temp_r0_9 = (u8) self->parameters.level;
                                                            if ((s8) temp_r0_9 >= 0x14) {
                                                                spD0.m_x = temp_r21_3->unk80 - fighterState->unk80;
                                                                spD0.m_y = temp_r21_3->unk84 - fighterState->unk84;
                                                                Vec2f::copy(sp128, spD0);
                                                                temp_f4 = constants->f00[15] * (f32) ((s8) temp_r0_9 - 0x14);
                                                                sp160.m_y = (sp128.m_y * temp_f4) + temp_r21_3->unk78;
                                                                sp160.m_x = (sp128.m_x * temp_f4) + temp_r21_3->unk74;
                                                            } else {
                                                                sp160.m_x = temp_r21_3->unk74;
                                                                sp160.m_y = temp_r21_3->unk78;
                                                            }
                                                            temp_f29 = fn_27_21F1BC(&self->targetId);
                                                            temp_f1_6 = (fighterState->unkA0 * (sp160.m_x - fighterState->unk74)) - (fn_27_21F1BC(&self->fighterId) + temp_f29);
                                                            if (!(temp_f1_6 < constants->f00[16]) || !(temp_f1_6 > constants->f00[17]) || !(__fabsf(fighterState->unk78 - sp160.m_y) < (constants->f00[18] * temp_r21_3->unk6C))) {
                                                                modeCandidate = 0;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else if (fighterState->unk1B0 & 1) {
                                            temp_r0_10 = fighterState->unk1AC;
                                            if ((temp_r0_10 != 0) && (temp_r0_10 != 0x2A)) {
                                                modeCandidate = 0xD;
                                            }
                                        }
                                    }
                                    if (modeCandidate != 0) {
                                        if (fighterState->unk1B0 & 9) {
                                            self->unk63 = 0x3C;
                                        } else if ((s32) fighterState->unk1AC == 0xD) {
                                            self->unk63 = 0;
                                        } else {
                                            self->unk63 = (u8) (s32) (constants->f00[21] + (constants->f00[7] * randf()));
                                        }
                                        sp6C = -1;
                                        fn_27_1F9FBC(self, 0xD, &sp6C, 0U, 0);
                                    } else {
                                        self->unk63 = (u8) (s32) (constants->f00[16] * randf());
                                    }
                                }
                                if ((s8) self->unk114 > 0) {
                                    temp_r3_7 = fighterState->unk50;
                                    if (!(temp_r3_7 & 0x100) && !(temp_r3_7 & 0x80) && ((temp_r0_11 = fighterState->unkAC, ((temp_r0_11 < 0x36) == 0)) || (temp_r0_11 < 0x32))) {
                                        temp_r3_8 = fn_27_1F8A7C();
                                        if ((s32) temp_r3_8->unk191C != 0) {
                                            temp_r4_3 = self->unk88;
                                            if (temp_r4_3 > 0) {
                                                self->unk88 = temp_r4_3 - 1;
                                            } else {
                                                temp_r0_12 = self->mode;
                                                if ((temp_r0_12 != 0xC) && (temp_r0_12 != 0xB) && (temp_r0_12 != 0xD)) {
                                                    var_f31 = constants->f00[22];
                                                    var_r24 = self->unk114;
                                                    var_r25 = NULL;
                                                    fn_27_218BA8(temp_r3_8, &fighterState->vector5C, 1U, -1, constants->f00[23]);
                                                    if (fighterState->unk50 & 0x40) {
                                                        var_r24 = (u8) (s8) (fighterState->unk1B8 + 1);
                                                    }
                                                    temp_f30 = constants->f00[7];
                                                    temp_f29_2 = constants->f00[4];
loop_226:
                                                    temp_r3_9 = fn_27_219188(temp_r3_8);
                                                    if (temp_r3_9 != NULL) {
                                                        if ((s8) temp_r3_9->unk56 >= (s8) var_r24) {
                                                            temp_r3_10 = fn_27_21A14C(temp_r3_9);
                                                            var_r22 = 0;
                                                            if (temp_r3_10 != NULL) {
                                                                var_r21_2 = 0;
                                                                if ((temp_r3_10->unk40 & 0x1000) || (fn_27_1F2E20(temp_r3_10, fighterState->unkC8) != 0)) {
                                                                    var_r21_2 = 1;
                                                                }
                                                                if (var_r21_2 == 0) {
                                                                    goto block_233;
                                                                }
                                                            } else {
block_233:
                                                                temp_r0_13 = reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk370;
                                                                if (temp_r0_13 != 8) {
                                                                    if (temp_r0_13 < 8) {
                                                                        if (temp_r0_13 != 5) {

                                                                        } else if (temp_r3_9->unk28 < (self->parameters.unk2C - temp_f30)) {
                                                                            var_r22 = 1;
                                                                        }
                                                                    }
                                                                } else if (temp_r3_9->unk2C < (self->parameters.unk28 - temp_f29_2)) {
                                                                    var_r22 = 1;
                                                                }
                                                                if ((var_r22 == 0) && ((s8) (u8) self->targetId != (s8) (u8) self->fighterId) && (fn_27_1F1F58(&self->targetId)->unk50 & 0x800000) && (temp_r3_9->unk60 & 0xB)) {
                                                                    var_r22 = 1;
                                                                }
                                                                if ((var_r22 == 0) && ((temp_f3_2 = temp_r3_9->unk28 - fighterState->vector5C.m_x, temp_f2_6 = temp_r3_9->unk2C - fighterState->vector5C.m_y, sp158 = temp_f3_2, sp15C = temp_f2_6, temp_f0_2 = (temp_f3_2 * temp_f3_2) + (temp_f2_6 * temp_f2_6), ((temp_f0_2 < var_f31) != 0)) || ((s8) temp_r3_9->unk56 > (s8) var_r24))) {
                                                                    var_f31 = temp_f0_2;
                                                                    var_r24 = temp_r3_9->unk56;
                                                                    var_r25 = temp_r3_9;
                                                                }
                                                            }
                                                        }
                                                        goto loop_226;
                                                    }
                                                    self->unk88 = (s16) (s8) (constants->f00[9] + (constants->f00[24] * randf()));
                                                    if ((var_r25 != NULL) && ((temp_r3_11 = self->script->action, (((temp_r3_11 & 0xF000) == 0) != 0)) || (temp_r3_11 == 0x3010) || (temp_r3_11 == 0x3050) || (temp_r3_11 == 0x3080) || (temp_r3_11 == 0x3090) || (temp_r3_11 == 0x30E0) || ((temp_r22_3 = var_r25->unk56, (((s8) temp_r22_3 > 4) != 0)) && (temp_r21_4 = (u8) self->parameters.level, ((randf() < (constants->f00[12] * (f32) ((s8) temp_r22_3 - 4) * (constants->f00[25] * (constants->f00[10] * (f32) (s8) temp_r21_4)))) != 0))))) {
                                                        temp_r3_12 = fn_27_21A14C(var_r25);
                                                        if (temp_r3_12 != NULL) {
                                                            if (temp_r3_12 == fighterState->unkBC) {
                                                                var_f29_3 = constants->f00[26] + (constants->f00[6] * (f32) (s8) var_r25->unk56);
                                                                if ((var_f29_3 < constants->f00[8]) && (var_f31 < constants->f00[27])) {
                                                                    var_f29_3 += constants->f00[13] * (constants->f00[8] - var_f29_3);
                                                                }
                                                                if (randf() < var_f29_3) {
                                                                    sp68 = -1;
                                                                    fn_27_1F9FBC(self, 0xC, &sp68, 0U, 0);
                                                                    temp_r4_4 = self->script;
                                                                    self->unk84 = var_r25->unk0;
                                                                    if ((void *) temp_r3_12->unk44 == NULL) {
                                                                        temp_r4_4->unk108 = 0;
                                                                        temp_r4_4->unk10C = 0;
                                                                    } else {
                                                                        temp_r4_4->unk10C = temp_r3_12->unk48;
                                                                        temp_r4_4->unk108 = temp_r3_12->unk44->unk1C;
                                                                    }
                                                                } else {
                                                                    self->unk88 = (s16) (constants->f00[17] + (constants->f00[16] * randf()));
                                                                }
                                                            } else if ((s32) self->mode != 0xB) {
                                                                if (randf() < (constants->f00[20] + (constants->f00[28] * (f32) (s8) var_r25->unk56))) {
                                                                    sp64 = -1;
                                                                    fn_27_1F9FBC(self, 0xB, &sp64, 0U, 0);
                                                                    temp_r4_5 = self->script;
                                                                    self->unk84 = var_r25->unk0;
                                                                    if ((void *) temp_r3_12->unk44 == NULL) {
                                                                        temp_r4_5->unk108 = 0;
                                                                        temp_r4_5->unk10C = 0;
                                                                    } else {
                                                                        temp_r4_5->unk10C = temp_r3_12->unk48;
                                                                        temp_r4_5->unk108 = temp_r3_12->unk44->unk1C;
                                                                    }
                                                                } else {
                                                                    self->unk88 = (s16) (constants->f00[29] + (constants->f00[30] * randf()));
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            temp_r3_13 = self->unk88;
                                            if (temp_r3_13 < 0x1E) {
                                                self->unk88 = 0x1E;
                                            } else if (temp_r3_13 > 0x1E) {
                                                self->unk88 = temp_r3_13 - 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                temp_r3_14 = self->unk8A;
                if (temp_r3_14 > 0) {
                    self->unk8A = temp_r3_14 - 1;
                } else {
                    temp_r3_15 = fighterState->unk50;
                    if (!(temp_r3_15 & 0x100) && !(temp_r3_15 & 0x20000)) {
                        temp_r0_14 = self->mode;
                        if ((temp_r0_14 != 4) && (temp_r0_14 != 9) && (temp_r0_14 != 0xA) && (temp_r0_14 != 0xE) && (temp_r0_14 != 0x10) && (temp_r0_14 != 0x11) && (temp_r0_14 != 0x12) && (temp_r0_14 != 0x13)) {
                            spAC = -1;
                            var_r22_2 = 0;
                            var_r23 = 0x10;
                            if ((fn_27_20B63C(fighterState) != 0) || ((u8) fighterState->unk1BA == 3)) {
                                temp_r3_16 = fn_27_20C010(fighterState);
                                if ((temp_r3_16 != NULL) && ((s8) (u8) self->parameters.level >= 0x14) && (temp_r0_15 = temp_r3_16->unkC, ((temp_r0_15 < 0) == 0)) && (temp_r0_15 < 0x3C) && (temp_r3_17 = self->script, temp_r4_6 = temp_r3_17->action, ((temp_r4_6 == 0x3010) == 0)) && (temp_r4_6 != 0x30E0) && (temp_r4_6 != 0x80)) {
                                    if ((temp_r0_15 > 0x18) && (temp_f29_3 = temp_r3_17->unkA0, ((randf() > (temp_f29_3 - constants->f00[6])) != 0))) {
                                        var_r22_2 = 0x80;
                                        spAC = fn_27_1FE1C0(self, NULL, 0);
                                    } else if (((s32) temp_r3_16->unkC < 0x14) || (((f32) (0x3C - temp_r3_16->unkC) * constants->f00[31]) > randf())) {
                                        if (((s32) reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk370 == 0x1F) && ((s32) temp_r3_16->unk8->unkA == 2)) {
                                            if (randf() < constants->f00[19]) {
                                                var_r22_2 = 0x3020;
                                            } else if ((u8) fighterState->unk1BA == 3) {
                                                if ((self->flags116 & 2) && (__fabsf(temp_r3_16->unk8->unk38) < constants->f00[32]) && (randf() < constants->f00[2])) {
                                                    buttons |= soController::getButtonMask(soController::Pad_Button_Attack);
                                                } else {
                                                    var_r22_2 = 0x71;
                                                }
                                            } else {
                                                var_r22_2 = 0x30E0;
                                            }
                                        } else if ((self->flags116 & 0x200) && ((u8) fighterState->unk1BA == 3) && (temp_r21_5 = (u8) self->parameters.level, ((randf() < (constants->f00[10] * (f32) (s8) temp_r21_5)) != 0))) {
                                            temp_r3_18 = temp_r3_16->unk8;
                                            temp_f2_7 = temp_r3_18->unk34;
                                            temp_f1_7 = temp_r3_18->unk38;
                                            temp_f3_3 = temp_r3_18->unk3C;
                                            if ((((temp_f3_3 * temp_f3_3) + ((temp_f2_7 * temp_f2_7) + (temp_f1_7 * temp_f1_7))) < constants->f00[12]) && (randf() < constants->f00[25])) {
                                                if (randf() < constants->f00[19]) {
                                                    var_r22_2 = 0x52;
                                                } else {
                                                    var_r22_2 = 0x80;
                                                }
                                            } else if (randf() < constants->f00[13]) {
                                                var_r22_2 = 0x71;
                                            } else {
                                                var_r22_2 = 0x30A0;
                                            }
                                        } else {
                                            var_r22_2 = 0x30E0;
                                        }
                                        spAC = fn_27_1FE1C0(self, NULL, 0);
                                    } else {
                                        temp_r3_19 = temp_r3_16->unk8;
                                        temp_f2_8 = temp_r3_19->unk34;
                                        temp_f1_8 = temp_r3_19->unk38;
                                        temp_f3_4 = temp_r3_19->unk3C;
                                        if ((((temp_f3_4 * temp_f3_4) + ((temp_f2_8 * temp_f2_8) + (temp_f1_8 * temp_f1_8))) < constants->f00[12]) && (temp_r21_6 = (u8) self->parameters.level, ((randf() < (constants->f00[10] * (f32) (s8) temp_r21_6)) != 0))) {
                                            if (randf() < constants->f00[19]) {
                                                var_r22_2 = 0x52;
                                            } else {
                                                var_r22_2 = 0x80;
                                            }
                                            spAC = fn_27_1FE1C0(self, NULL, 0);
                                        } else {
                                            self->unk8A = 2;
                                        }
                                    }
                                } else {
                                    temp_r3_20 = fn_27_1F1F58(&self->targetId);
                                    temp_r6 = (u8) self->parameters.level;
                                    temp_r5_2 = temp_r3_20->unk1BC;
                                    if (((f64) temp_r5_2 > (constants->d88 * (constants->d90 * (f64) (0x64 - (s8) temp_r6)))) && (temp_r5_2 < 0xEU) && ((s8) temp_r6 >= 0x14) && (self->flags116 & 0x200)) {
                                        if ((fn_27_20B898(fighterState, &self->targetId, constants->f00[2] * self->parameters.unk10) < temp_r3_20->unk1C0) && (fn_27_20B758(temp_r3_20, &self->fighterId, constants->f00[0]) > constants->f98[0])) {
                                            temp_r0_16 = (u8) self->parameters.level;
                                            var_f29_4 = (constants->f00[25] + (constants->f98[1] * (constants->f00[10] * (self->unk78 * (f32) (s8) temp_r0_16)))) * (constants->f00[10] * (constants->f00[10] * (f32) ((s8) temp_r0_16 * (s8) temp_r0_16)));
                                            if (var_f29_4 > constants->f98[2]) {
                                                var_f29_4 = constants->f98[2];
                                            }
                                            if (randf() < var_f29_4) {
                                                temp_r5_3 = temp_r3_20->unk1BC;
                                                var_r23 = 0x3C;
                                                if (((s32) (temp_r3_20->unk1BD - temp_r5_3) > 0xE) && ((s8) (u8) self->parameters.level > 0x37)) {
                                                    var_r22_3 = 0;
                                                    if ((temp_r3_20->unk50 & 0x40000) || (randf() < constants->f98[3])) {
                                                        var_r22_3 = 1;
                                                    }
                                                    var_r22_2 = 0x3020;
                                                    if (var_r22_3 != 0) {
                                                        var_r22_2 = 0x71;
                                                    }
                                                } else if (temp_r3_20->unk50 & 0x40000) {
                                                    var_r22_2 = 0x30B0;
                                                } else {
                                                    temp_r4_7 = fighterState->unkAC;
                                                    switch (temp_r4_7) { /* switch 2 */
                                                    case 0xC: /* switch 2 */
                                                    case 0x11: /* switch 2 */
                                                    case 0x16: /* switch 2 */
                                                    case 0x21: /* switch 2 */
                                                    case 0x22: /* switch 2 */
                                                        var_r3 = 0xA;
                                                        if (temp_r4_7 != 0x16) {
                                                            if (temp_r4_7 < 0x16) {
                                                                if (temp_r4_7 != 0x11) {

                                                                } else {
                                                                    var_r3 = 3;
                                                                }
                                                            } else if (temp_r4_7 != 0x21) {

                                                            } else {
                                                                var_r3 = 5;
                                                            }
                                                        } else {
                                                            var_r3 = 0xC;
                                                        }
                                                        if ((self->flags116 & 2) && ((s32) temp_r5_3 > var_r3) && ((fighterState->unkA0 * fn_27_20BC28(fighterState, &self->targetId)) > constants->f00[0]) && (randf() < (constants->f98[4] * var_f29_4))) {
                                                            if ((s32) fighterState->unkAC != 0xC) {
                                                                var_r22_2 = 0x603B;
                                                            } else {
                                                                var_r22_2 = 0x6038;
                                                            }
                                                        } else {
                                                        default: /* switch 2 */
                                                            if (temp_r3_20->unk50 & 0x10) {
                                                                var_r22_2 = 0x30B0;
                                                            } else {
                                                                temp_f2_9 = self->unk80 - self->unk7C;
                                                                if (temp_f2_9 > constants->f00[0]) {
                                                                    var_f29_5 = constants->f98[5] + (constants->f00[2] * temp_f2_9);
                                                                    if (var_f29_5 > constants->f98[6]) {
                                                                        var_f29_5 = constants->f98[6];
                                                                    }
                                                                } else {
                                                                    var_f29_5 = constants->f98[5] + (constants->f00[32] * temp_f2_9);
                                                                    if (var_f29_5 < constants->f00[20]) {
                                                                        var_f29_5 = constants->f00[20];
                                                                    }
                                                                }
                                                                temp_f29_4 = var_f29_5 * (constants->f00[8] - (constants->f98[7] * (f32) (0x64 - (s8) (u8) self->parameters.level)));
                                                                if (randf() < temp_f29_4) {
                                                                    temp_f1_9 = randf();
                                                                    if (temp_f1_9 < constants->f00[32]) {
                                                                        var_r22_2 = 0x30A0;
                                                                    } else if (temp_f1_9 < constants->f98[3]) {
                                                                        var_r22_2 = 0x71;
                                                                    } else {
                                                                        var_r22_2 = 0x72;
                                                                    }
                                                                } else {
                                                                    var_r22_2 = 0x3020;
                                                                }
                                                            }
                                                        }
                                                        break;
                                                    }
                                                }
                                            } else {
                                                temp_r21_7 = (u8) self->parameters.level;
                                                self->unk8A = (s16) (constants->f98[8] + (constants->f00[4] * (constants->f00[10] * (f32) (0x64 - (s8) temp_r21_7)) * randf()));
                                            }
                                        } else {
                                            self->unk8A = 6;
                                        }
                                    } else {
                                        temp_r3_21 = temp_r3_20->unk1BA;
                                        if ((temp_r3_21 == 3) && ((s8) temp_r6 >= 0x14)) {
                                            temp_f30_2 = fn_27_20B898(fighterState, &self->targetId, constants->f00[32] * self->parameters.unk10);
                                            temp_f1_10 = fn_27_20BC28(fighterState, &self->targetId);
                                            if ((temp_f30_2 < constants->f98[9]) && ((temp_f1_10 * temp_r3_20->unk80) < constants->f00[0]) && ((temp_f1_10 * fighterState->unkA0) > constants->f00[0])) {
                                                temp_r0_17 = (u8) self->parameters.level;
                                                temp_f29_5 = constants->f98[1] * (constants->f00[10] * (constants->f00[10] * (f32) ((s8) temp_r0_17 * (s8) temp_r0_17)));
                                                if (randf() < temp_f29_5) {
                                                    temp_f1_11 = randf();
                                                    if (temp_f1_11 < constants->f00[6]) {
                                                        var_r22_2 = 0x3020;
                                                    } else if (temp_f1_11 < constants->f00[26]) {
                                                        var_r22_2 = 0x56;
                                                    } else if (temp_f1_11 < constants->f00[12]) {
                                                        var_r22_2 = 0x80;
                                                    } else if (temp_f1_11 < constants->f00[32]) {
                                                        var_r22_2 = 0x6032;
                                                    } else if (temp_f1_11 < constants->f98[10]) {
                                                        var_r22_2 = 0x71;
                                                    } else if (temp_f1_11 < constants->f98[5]) {
                                                        var_r22_2 = 0x72;
                                                    } else if (temp_f1_11 < constants->f00[13]) {
                                                        var_r22_2 = 0x1040;
                                                    } else {
                                                        var_r22_2 = 0x1010;
                                                    }
                                                    if (!(self->flags116 & 2) || (temp_r3_20->unk50 & 0x100)) {
                                                        temp_r0_18 = var_r22_2 & 0xF000;
                                                        if (temp_r0_18 != 0x6000) {
                                                            if (temp_r0_18 < 0x6000) {
                                                                if (temp_r0_18 != 0x1000) {

                                                                } else {
                                                                    goto block_416;
                                                                }
                                                            }
                                                        } else {
block_416:
                                                            if (fn_27_20BCBC(fighterState, &fighterState->vector5C, -fighterState->unkA0) < constants->f00[4]) {
                                                                var_r22_2 = 0x71;
                                                            } else {
                                                                var_r22_2 = 0x56;
                                                            }
                                                        }
                                                    }
                                                    var_r23 = 0x1E;
                                                } else {
                                                    temp_r21_8 = (u8) self->parameters.level;
                                                    self->unk8A = (s16) (constants->f98[11] + (constants->f00[4] * (constants->f00[10] * (f32) (0x64 - (s8) temp_r21_8)) * randf()));
                                                }
                                            } else {
                                                self->unk8A = 2;
                                            }
                                        } else if (temp_r3_21 == 0x13) {
                                            temp_r0_19 = (u8) self->parameters.level;
                                            temp_f30_3 = fn_27_20B898(fighterState, &self->targetId, constants->f00[0]);
                                            temp_f29_6 = constants->f98[1] * (constants->f00[10] * (constants->f00[10] * (f32) ((s8) temp_r0_19 * (s8) temp_r0_19)));
                                            if ((randf() < (constants->f00[26] + temp_f29_6)) && ((s8) (u8) self->parameters.level >= 0x14)) {
                                                temp_f1_12 = randf();
                                                temp_f31 = temp_f1_12;
                                                var_r23 = 0x1E;
                                                if (temp_f30_3 < constants->f00[17]) {
                                                    temp_r3_22 = fighterState->unkAC;
                                                    switch (temp_r3_22) { /* switch 3 */
                                                    case 0xC: /* switch 3 */
                                                    case 0x11: /* switch 3 */
                                                    case 0x16: /* switch 3 */
                                                    case 0x21: /* switch 3 */
                                                    case 0x22: /* switch 3 */
                                                        if ((self->flags116 & 2) && (fn_27_20B568(fighterState) != 0) && (randf() < (constants->f98[1] * temp_f29_6))) {
                                                            var_r22_2 = 0x1160;
                                                        } else {
                                                        default: /* switch 3 */
                                                            if (temp_f31 < constants->f00[6]) {
                                                                var_r22_2 = 0x1010;
                                                            } else if (temp_f31 < constants->f98[12]) {
                                                                var_r22_2 = 0x1040;
                                                            } else if (temp_f31 < constants->f98[1]) {
                                                                var_r22_2 = 0x3020;
                                                            } else if (temp_f31 < constants->f00[19]) {
                                                                var_r22_2 = 0x71;
                                                            } else if (temp_f31 < constants->f98[4]) {
                                                                var_r22_2 = 0x72;
                                                            } else {
                                                                var_r22_2 = 0x30B0;
                                                            }
                                                        }
                                                        break;
                                                    }
                                                } else if (temp_f30_3 < constants->f98[9]) {
                                                    if (temp_f1_12 < constants->f00[19]) {
                                                        var_r22_2 = 0x72;
                                                    } else if (temp_f1_12 < constants->f98[13]) {
                                                        var_r22_2 = 0x56;
                                                    } else if (temp_f1_12 < constants->f98[6]) {
                                                        var_r22_2 = 0x30B0;
                                                    } else {
                                                        var_r22_2 = 0x1040;
                                                    }
                                                } else if (temp_f30_3 < constants->f00[14]) {
                                                    if (temp_f1_12 < constants->f00[32]) {
                                                        var_r22_2 = 0x30B0;
                                                    } else if (temp_f1_12 < constants->f98[1]) {
                                                        var_r22_2 = 0x80;
                                                    } else if (temp_f1_12 < constants->f00[19]) {
                                                        var_r22_2 = 0x56;
                                                    } else if (temp_f1_12 < constants->f00[2]) {
                                                        var_r22_2 = 0x72;
                                                    } else {
                                                        self->unk8A = (s16) (s8) (constants->f98[8] + (constants->f98[14] * randf()));
                                                    }
                                                } else {
                                                    self->unk8A = (s16) (s8) (constants->f00[21] + (constants->f00[21] * randf()));
                                                }
                                                if (!(self->flags116 & 2) || (temp_r3_20->unk50 & 0x100)) {
                                                    temp_r0_20 = var_r22_2 & 0xF000;
                                                    if (temp_r0_20 != 0x6000) {
                                                        if (temp_r0_20 < 0x6000) {
                                                            if (temp_r0_20 != 0x1000) {

                                                            } else {
                                                                goto block_468;
                                                            }
                                                        }
                                                    } else {
block_468:
                                                        if (fn_27_20BCBC(fighterState, &fighterState->vector5C, -fighterState->unkA0) < constants->f00[4]) {
                                                            var_r22_2 = 0x71;
                                                        } else {
                                                            var_r22_2 = 0x72;
                                                        }
                                                    }
                                                }
                                            } else if (((s8) (u8) self->parameters.level < 0x1E) && (randf() > (constants->f00[19] + temp_f29_6))) {
                                                if (randf() < constants->f00[25]) {
                                                    var_r22_2 = 0x24;
                                                } else {
                                                    var_r22_2 = 0x71;
                                                }
                                                var_r23 = 0x1E;
                                            } else {
                                                temp_r21_9 = (u8) self->parameters.level;
                                                self->unk8A = (s16) (constants->f00[8] + (constants->f98[15] * (constants->f00[10] * (f32) (0x64 - (s8) temp_r21_9)) * randf()));
                                            }
                                        }
                                    }
                                }
                                if (((u16) var_r22_2 == 0) && (self->flags116 & 0x200) && ((u8) fighterState->unk1BA == 3) && ((s8) (u8) self->parameters.level >= 0x14)) {
                                    temp_r0_21 = self->script->action;
                                    if ((temp_r0_21 != 0x3010) && (temp_r0_21 != 0x30E0) && (temp_r0_21 != 0x51) && (temp_r0_21 != 0x52) && (randf() < constants->f00[32])) {
                                        temp_r3_23 = fn_27_20C010(fighterState);
                                        if (temp_r3_23 != NULL) {
                                            temp_r0_22 = temp_r3_23->unkC;
                                            if ((temp_r0_22 >= 0) && (temp_r0_22 < 0x1E)) {
                                                var_f1 = randf();
                                                if ((s32) temp_r3_23->unkC < 0xA) {
                                                    var_f1 = constants->f00[0];
                                                }
                                                if (var_f1 < constants->f00[26]) {
                                                    var_r22_2 = 0x30E0;
                                                } else {
                                                    if (var_f1 < (constants->f00[26] + (constants->f00[10] * (constants->f00[2] * (f32) (s8) (u8) self->parameters.level)))) {
                                                        var_r22_2 = 0x51;
                                                    } else {
                                                        var_r22_2 = 0x52;
                                                    }
                                                    var_r23 = 3;
                                                }
                                                spAC = -1;
                                            }
                                        }
                                    }
                                }
                            } else if ((self->flags116 & 0x200) && ((s8) (u8) self->parameters.level >= 0x14) && (fn_27_20B668(fighterState) != 0) && ((u16) self->script->action != 0x3060)) {
                                temp_r3_24 = fn_27_20C010(fighterState);
                                if ((temp_r3_24 != NULL) && (fn_27_20B694(fighterState, 0x2000U) != 0) && (temp_r0_23 = temp_r3_24->unkC, ((temp_r0_23 < 4) == 0)) && (temp_r0_23 < 0x18)) {
                                    var_r21_3 = 1;
                                    if ((s32) self->mode != 3) {

                                    } else if (fn_27_20B568(fighterState) == 0) {
                                        if (fn_27_20BCBC(fighterState, &fighterState->vector5C, fighterState->unkA0) > constants->f98[16]) {
                                            sp1B4.xy.m_x = fighterState->vector5C.m_x;
                                            sp1B4.xy.m_y = fighterState->vector5C.m_y;
                                            sp1B4.z = fighterState->unk64;
                                            temp_f4_2 = constants->f00[26] * (f32) (s8) (u8) self->parameters.level;
                                            temp_f3_5 = sp1B4.xy.m_x + (fighterState->unk80 * temp_f4_2);
                                            sp1B4.xy.m_x = temp_f3_5;
                                            temp_f2_10 = sp1B4.xy.m_y + (fighterState->unk84 * temp_f4_2);
                                            sp1B4.xy.m_y = temp_f2_10;
                                            sp1B4.xy.m_x = temp_f3_5 + (constants->f98[17] * fighterState->unk8C * temp_f4_2);
                                            sp1B4.xy.m_y = temp_f2_10 + (constants->f98[17] * fighterState->unk8C * temp_f4_2);
                                            if (fn_27_20B610(fighterState, &sp1B4.xy) == 0) {
                                                var_r21_3 = 0;
                                            }
                                        } else {
                                            var_r21_3 = 0;
                                        }
                                    }
                                    if (var_r21_3 != 0) {
                                        var_r22_2 = 0x3060;
                                        spAC = -1;
                                    }
                                } else {
                                    temp_r3_25 = self->script;
                                    temp_r4_8 = temp_r3_25->action;
                                    if (((s32) (temp_r4_8 & 0x7FF0) != 0x6040) && (temp_r4_8 != 0x30D0)) {
                                        temp_r0_24 = self->mode;
                                        var_r21_4 = 0;
                                        if (temp_r0_24 != 4) {
                                            if (temp_r0_24 < 4) {
                                                if (temp_r0_24 < 3) {
                                                    if (temp_r0_24 < 1) {

                                                    } else {
                                                        var_r21_4 = 1;
                                                    }
                                                } else if (fn_27_20B568(fighterState) != 0) {
                                                    var_r21_4 = 1;
                                                } else if (fn_27_20BCBC(fighterState, &fighterState->vector5C, fighterState->unkA0) > constants->f98[16]) {
                                                    sp1A8.xy.m_x = fighterState->vector5C.m_x;
                                                    sp1A8.xy.m_y = fighterState->vector5C.m_y;
                                                    sp1A8.z = fighterState->unk64;
                                                    temp_f4_3 = constants->f00[26] * (f32) (s8) (u8) self->parameters.level;
                                                    temp_f3_6 = sp1A8.xy.m_x + (fighterState->unk80 * temp_f4_3);
                                                    sp1A8.xy.m_x = temp_f3_6;
                                                    temp_f2_11 = sp1A8.xy.m_y + (fighterState->unk84 * temp_f4_3);
                                                    sp1A8.xy.m_y = temp_f2_11;
                                                    sp1A8.xy.m_x = temp_f3_6 + (constants->f98[17] * fighterState->unk8C * temp_f4_3);
                                                    sp1A8.xy.m_y = temp_f2_11 + (constants->f98[17] * fighterState->unk8C * temp_f4_3);
                                                    if (fn_27_20B610(fighterState, &sp1A8.xy) != 0) {
                                                        var_r21_4 = 1;
                                                    }
                                                }
                                            } else if (temp_r0_24 < 6) {
                                                if (fighterState->vector5C.m_y >= (constants->f98[8] + temp_r3_25->unkE4)) {
                                                    var_r21_4 = 1;
                                                }
                                            }
                                        }
                                        if (var_r21_4 != 0) {
                                            temp_r3_26 = fn_27_1F1F58(&self->targetId);
                                            temp_r4_9 = temp_r3_26->unk1BA;
                                            if ((temp_r4_9 == 5) || (temp_r4_9 == 4) || (temp_r4_9 == 6) || (temp_r4_9 == 7) || (temp_r5_4 = temp_r3_26->unk50, (((temp_r5_4 & 0x40000000) == 0) == 0)) || (temp_r4_9 == 9) || (temp_r5_4 & 0x400000) || (temp_r4_9 == 0xE)) {
                                                self->unk8A = 0xA;
                                            } else {
                                                temp_r27 = temp_r3_26->unk4;
                                                if (temp_r27 >= 4U) {
                                                    self->unk8A = 0xA;
                                                } else if ((temp_r27 <= 1U) && ((u8) temp_r3_26->unk1BC >= 0xEU)) {
                                                    self->unk8A = 4;
                                                } else {
                                                    fn_27_20B9E0(fighterState, &sp19C, &self->targetId, constants->f98[4] * self->parameters.unk10);
                                                    temp_f1_13 = sp19C.m_x;
                                                    sp19CLengthSq = (sp19C.m_z * sp19C.m_z) + ((temp_f1_13 * temp_f1_13) + (sp19C.m_y * sp19C.m_y));
                                                    temp_f31_2 = fn_27_21F1BC(&self->targetId);
                                                    temp_f0_3 = constants->f98[18] + fn_27_21F1BC(&self->fighterId) + temp_f31_2;
                                                    if (sp19CLengthSq < (temp_f0_3 * temp_f0_3)) {
                                                        temp_r3_27 = temp_r3_26->unk1BA;
                                                        if (temp_r3_27 == 0x13) {
                                                            var_f31_2 = constants->f98[6];
                                                        } else {
                                                            var_f31_2 = constants->f98[13];
                                                            if ((s32) temp_r27 != 3) {
                                                                if ((s32) temp_r27 < 3) {
                                                                    if ((s32) temp_r27 < 2) {

                                                                    } else {
                                                                        var_f31_2 += constants->f98[5];
                                                                    }
                                                                }
                                                            } else {
                                                                var_f31_2 += constants->f00[12];
                                                            }
                                                        }
                                                        temp_r0_25 = (u8) self->parameters.level;
                                                        var_f31_3 = (var_f31_2 * (constants->f00[10] * (constants->f00[10] * (f32) ((s8) temp_r0_25 * (s8) temp_r0_25)))) + constants->f00[20];
                                                        if (temp_r3_27 != 0x13) {
                                                            temp_f2_12 = fighterState->unkC4;
                                                            if (temp_f2_12 < constants->f98[19]) {
                                                                var_f31_3 *= constants->f00[2] + (constants->f98[20] * temp_f2_12);
                                                            }
                                                            if (fighterState->unk84 >= constants->f98[21]) {
                                                                var_f31_3 *= constants->f00[20];
                                                            }
                                                            if ((s32) self->script->action != 0x80) {

                                                            } else {
                                                                var_f31_3 *= constants->f00[32];
                                                            }
                                                        }
                                                        if ((s32) self->script->action != 0x2060) {

                                                        } else {
                                                            var_f31_3 *= constants->f00[0];
                                                        }
                                                        if (randf() < var_f31_3) {
                                                            temp_r4_10 = fighterState->unkAC;
                                                            switch (temp_r4_10) { /* switch 4 */
                                                            case 0xC: /* switch 4 */
                                                            case 0x11: /* switch 4 */
                                                            case 0x16: /* switch 4 */
                                                            case 0x21: /* switch 4 */
                                                            case 0x22: /* switch 4 */
                                                                var_r3_2 = 0xA;
                                                                if (temp_r4_10 != 0x16) {
                                                                    if (temp_r4_10 < 0x16) {
                                                                        if (temp_r4_10 != 0x11) {

                                                                        } else {
                                                                            var_r3_2 = 3;
                                                                        }
                                                                    } else if (temp_r4_10 != 0x21) {

                                                                    } else {
                                                                        var_r3_2 = 5;
                                                                    }
                                                                } else {
                                                                    var_r3_2 = 0xC;
                                                                }
                                                                if (((u8) (temp_r27 + 0xFF) <= 1U) && ((s32) temp_r3_26->unk1BC > var_r3_2) && (self->flags116 & 2) && (fn_27_20B568(fighterState) != 0) && ((fighterState->unkA0 * fn_27_20BC28(fighterState, &self->targetId)) > constants->f00[0]) && (randf() < (constants->f00[19] * var_f31_3))) {
                                                                    if ((s32) fighterState->unkAC != 0xC) {
                                                                        var_r22_2 = 0x6049;
                                                                    } else {
                                                                        var_r22_2 = 0x6046;
                                                                    }
                                                                } else {
                                                                default: /* switch 4 */
                                                                    if ((temp_r27 <= 1U) && ((s16) fighterState->unkA8 > 0) && (randf() < constants->f00[2])) {
                                                                        var_r22_2 = 0x2060;
                                                                    } else {
                                                                        if ((u8) temp_r3_26->unk1BA == 0x13) {
                                                                            var_f3 = constants->f98[2];
                                                                        } else {
                                                                            var_f3 = constants->f00[13];
                                                                        }
                                                                        temp_f29_7 = constants->f00[10] * (var_f3 * (f32) (s8) (u8) self->parameters.level);
                                                                        if (randf() < temp_f29_7) {
                                                                            var_r22_2 = 0x30D0;
                                                                        } else {
                                                                            var_r22_2 = 0x3060;
                                                                        }
                                                                    }
                                                                }
                                                                break;
                                                            }
                                                        } else {
                                                            temp_r21_10 = (u8) self->parameters.level;
                                                            temp_r0_26 = (s16) (constants->f98[11] + (constants->f00[4] * (constants->f00[10] * (f32) (0x64 - (s8) temp_r21_10)) * randf()));
                                                            self->unk8A = temp_r0_26;
                                                            if (fighterState->unk84 > constants->f00[0]) {
                                                                self->unk8A = temp_r0_26 + 8;
                                                            }
                                                        }
                                                    } else if ((fighterState->unk84 < constants->f00[0]) && ((u16) self->script->action != 0x80) && (__fabsf(fn_27_20B758(fighterState, &self->targetId, constants->f00[0])) < (constants->f98[22] * self->parameters.unk18))) {
                                                        fn_27_20B9E0(fighterState, &sp19C, &self->targetId, constants->f00[2] * self->parameters.unk10);
                                                        if ((sp19C.m_y > constants->f98[23]) && (sp19C.m_y < constants->f98[0])) {
                                                            temp_r21_11 = (u8) self->parameters.level;
                                                            if (randf() < (constants->f98[24] * (constants->f00[10] * (f32) (s8) temp_r21_11))) {
                                                                var_r22_2 = fn_27_20E30C(self->script, 0x602DU, NULL, NULL, NULL);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (((u16) var_r22_2 == 0x3060) && (fn_27_20B694(fighterState, 0x2000U) == 0)) {
                                            var_r22_2 = 0;
                                        }
                                    }
                                }
                            }
                            if ((u16) var_r22_2 != 0) {
                                sp190.xy.m_x = fighterState->unk74;
                                sp190.xy.m_y = fighterState->unk78;
                                sp190.z = fighterState->unk7C;
                                sp190.xy.m_x += constants->f00[7] * fighterState->unk80;
                                if (stageData != NULL) {
                                    temp_r0_27 = stageData->code2;
                                    if ((s32) temp_r0_27 != 8) {
                                        if ((s32) temp_r0_27 < 8) {
                                            if ((s32) temp_r0_27 != 3) {

                                            } else if ((s32) (u16) var_r22_2 < 0x73) {
                                                if ((s32) (u16) var_r22_2 < 0x71) {

                                                } else {
                                                    var_r22_2 = 0x30A0;
                                                }
                                            }
                                        }
                                    } else {
                                        self->counter66 = -1;
                                    }
                                }
                                if ((s32) (u16) var_r22_2 < 0x73) {
                                    if ((s32) (u16) var_r22_2 < 0x71) {

                                    } else {
                                        if ((u16) var_r22_2 == 0x71) {
                                            var_f3_2 = fighterState->unkA0;
                                        } else {
                                            var_f3_2 = -fighterState->unkA0;
                                        }
                                        temp_f2_13 = constants->f98[9] * fighterState->unk68;
                                        if (var_f3_2 > constants->f00[0]) {
                                            if (fighterState->vector5C.m_x > (reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk364 - temp_f2_13)) {
                                                temp_r0_28 = (u16) var_r22_2;
                                                var_r22_2 = 0x71;
                                                if (temp_r0_28 == 0x71) {
                                                    var_r22_2 = 0x72;
                                                }
                                            }
                                        } else if (fighterState->vector5C.m_x < (temp_f2_13 + reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk360)) {
                                            temp_r0_29 = (u16) var_r22_2;
                                            var_r22_2 = 0x71;
                                            if (temp_r0_29 == 0x71) {
                                                var_r22_2 = 0x72;
                                            }
                                        }
                                    }
                                }
                                if ((fighterState->unk84 < constants->f00[32]) && (fn_27_20B610(fighterState, &sp190.xy) != 0)) {
                                    fn_27_1F9FBC(self, 2, &spAC, (u32) (u16) var_r22_2, 0);
                                    self->unk8A = var_r23;
                                    self->targetSelected = 0;
                                } else {
                                    self->unk8A = 0xA;
                                }
                            }
                        }
                    }
                }
                temp_r3_28 = self->unk5A;
                if (temp_r3_28 > 0) {
                    temp_r3_29 = temp_r3_28 - 1;
                    self->unk5A = temp_r3_29;
                    if (temp_r3_29 == 0) {
                        temp_r3_30 = self->flags;
                        self->unk62 = 0;
                        if (temp_r3_30 & 1) {
                            self->flags = temp_r3_30 & 0xFFFE;
                            self->targetId = (s8) (u8) self->fighterId;
                            self->unk6A = 0;
                        }
                        if ((s16) self->unk58 < 0) {
                            self->unk58 = 0;
                        }
                        if (stageData != NULL) {
                            if ((s32) stageData->code2 != 3) {

                            } else {
                                self->counter66 = -1;
                            }
                        }
                    }
                    if ((((s8) self->unk74 > 0xC) || (fighterState->unk50 & 0x400000)) && ((s32) self->mode != 0x15)) {
                        sp60 = -1;
                        fn_27_1F9FBC(self, 0x15, &sp60, 0U, 0);
                    } else if ((s16) self->unk5A == 0) {
                        if (fn_27_20B568(fighterState) == 0) {
                            temp_r0_30 = self->mode;
                            if (temp_r0_30 != 0x11) {
                                if (temp_r0_30 < 0x11) {
                                    if (temp_r0_30 < 0x10) {
                                        goto block_664;
                                    }
                                    sp5C = -1;
                                    fn_27_1F9FBC(self, 0x10, &sp5C, 0U, 0);
                                } else if (temp_r0_30 < 0x13) {
                                    sp58 = -1;
                                    fn_27_1F9FBC(self, 0x12, &sp58, 0U, 0);
                                } else {
                                    goto block_664;
                                }
                            } else {
block_664:
                                temp_r3_31 = fn_27_1F1F58(&self->targetId);
                                if (((s32) fighterState->unkB4 == 0x44) && ((s32) temp_r3_31->unk1AC == 0x2C) && ((s32) temp_r3_31->unk1B4 > 0)) {
                                    stick.m_y = constants->f00[8];
                                    sp54 = fn_27_1FE1C0(self, NULL, 0);
                                    fn_27_1F9FBC(self, 1, &sp54, 0x80U, 0);
                                    self->unk58 = -0x1E;
                                } else {
                                    sp50 = -1;
                                    fn_27_1F9FBC(self, 3, &sp50, 0U, 0);
                                }
                            }
                        } else {
                            temp_r3_32 = self->mode;
                            if (temp_r3_32 != 0x15) {
                                if ((fighterState->unk50 & 1) && ((u8) fighterState->unk1BA == 5)) {
                                    if ((s32) fighterState->unkB4 != 0x44) {
                                        sp4C = fn_27_1FE1C0(self, NULL, 0);
                                        fn_27_1F9FBC(self, 1, &sp4C, 0x2050U, 0);
                                    } else {
                                        var_f29_6 = randf();
                                        temp_r3_33 = fn_27_1F1F58(&self->targetId);
                                        if (((s32) temp_r3_33->unk1AC == 0x2C) && ((s32) temp_r3_33->unk1B4 > 0)) {
                                            var_f29_6 = constants->f00[19];
                                            if (fn_27_20B568(fighterState) == 0) {
                                                self->unk58 = -0x1E;
                                            }
                                        }
                                        if (var_f29_6 < constants->f00[32]) {
                                            if (var_f29_6 < constants->f00[6]) {
                                                stick.m_y = constants->f00[8];
                                            } else if (var_f29_6 < constants->f00[26]) {
                                                stick.m_y = constants->f98[25];
                                            }
                                            sp48 = fn_27_1FE1C0(self, NULL, 0);
                                            fn_27_1F9FBC(self, 1, &sp48, 0x2050U, 0);
                                        } else if (var_f29_6 < constants->f00[2]) {
                                            stick.m_y = constants->f00[8];
                                            sp44 = fn_27_1FE1C0(self, NULL, 0);
                                            fn_27_1F9FBC(self, 1, &sp44, 0x80U, 0);
                                        } else if (var_f29_6 < constants->f00[25]) {
                                            sp40 = -1;
                                            fn_27_1F9FBC(self, 0x15, &sp40, 0U, 0);
                                        } else {
                                            sp3C = -1;
                                            fn_27_1F9FBC(self, 1, &sp3C, 0U, 0);
                                        }
                                    }
                                    self->targetSelected = 0;
                                } else if ((temp_r3_32 == 1) && (fn_27_20B668(fighterState) != 0) && (randf() > constants->f00[19])) {
                                    sp38 = fn_27_1FE1C0(self, NULL, 0);
                                    fn_27_1F9FBC(self, 1, &sp38, 0x1080U, 0);
                                    self->targetSelected = 0;
                                } else {
                                    sp34 = -1;
                                    fn_27_1F9FBC(self, 1, &sp34, 0U, 0);
                                }
                            }
                        }
                        if ((s8) self->unk74 < 0xC) {
                            self->unk74 = 0xC;
                        }
                    }
                }
                if ((s8) self->unk74 > 0) {
                    if (fn_27_20B568(fighterState) != 0) {
                        self->unk74 -= 1;
                    } else {
                        self->unk74 = 0;
                    }
                }
                temp_r0_31 = self->mode;
                if ((temp_r0_31 != 3) && (temp_r0_31 != 0xF) && (temp_r0_31 != 0xA) && (temp_r0_31 != 0x11) && (temp_r0_31 != 9) && (temp_r0_31 != 0x13) && (temp_r0_31 != 0x12) && (temp_r0_31 != 0xE) && (temp_r0_31 != 0x10)) {
                    temp_r3_34 = self->unk58;
                    if (temp_r3_34 < 0) {
                        if ((temp_r3_34 < -1) || (temp_r0_31 != 6) || (temp_r21_12 = g_aiMgr, ((fighterState->vector5C.m_y < (constants->f00[16] + reinterpret_cast<const AiManagerView*>(temp_r21_12)->unk36C)) != 0)) || (temp_f31_3 = fn_27_21F434(&self->parameters, fighterState), ((fn_27_1F1300(temp_r21_12, &fighterState->vector5C, fn_27_21F484(&self->parameters, fighterState) / temp_f31_3) == 0) != 0))) {
                            self->unk58 += 1;
                        }
                    } else if (fn_27_20B568(fighterState) == 0) {
                        temp_r3_35 = fighterState->unkBC;
                        if (fighterState->vector5C.m_x < (constants->f00[19] * (temp_r3_35->unk18 + temp_r3_35->unk20))) {
                            var_f1_2 = temp_r3_35->unk1C;
                        } else {
                            var_f1_2 = temp_r3_35->unk24;
                        }
                        temp_f29_8 = var_f1_2 - constants->f00[17];
                        if ((s16) self->unk58 == 0) {
                            if (randi(0x64) < (s32) self->parameters.unk47) {
                                var_r21_5 = self->parameters.unk46;
                            } else {
                                var_r21_5 = 0;
                            }
                            temp_r0_32 = (s16) (self->parameters.unk44 + (var_r21_5 + randi(self->parameters.unk45 + 1))) + 1;
                            self->unk58 = temp_r0_32;
                            if (fighterState->unk84 > constants->f00[6]) {
                                self->unk58 = temp_r0_32 + 0x14;
                            }
                        }
                        if ((fighterState->vector5C.m_y > temp_f29_8) && ((u16) self->script->action == 0x1140)) {
                            self->unk58 = 0x1E;
                        } else if ((fighterState->vector5C.m_y > temp_f29_8) && ((u16) self->script->action == 0x10A0)) {
                            self->unk58 = 2;
                        } else {
                            if ((fighterState->vector5C.m_y < temp_f29_8) && ((s16) self->unk58 > 4)) {
                                self->unk58 = (s16) (constants->f00[8] + (constants->f98[11] * randf()));
                            }
                            temp_r3_36 = self->unk58 - 1;
                            self->unk58 = temp_r3_36;
                            if (temp_r3_36 == 0) {
                                if (!(fighterState->unk50 & 1)) {
                                    if ((fighterState->unk80 * fighterState->unkA0) > constants->f00[6]) {
                                        sp30 = -1;
                                        fn_27_1F9FBC(self, 1, &sp30, 0x52U, 0);
                                    } else {
                                        sp2C = -1;
                                        fn_27_1F9FBC(self, 1, &sp2C, 0x54U, 0);
                                    }
                                } else {
                                    sp28 = -1;
                                    fn_27_1F9FBC(self, 3, &sp28, 0U, 0);
                                }
                            }
                        }
                    } else {
                        self->unk58 = 0;
                    }
                }
                if ((s32) self->mode == 0) {
                    sp24 = -1;
                    fn_27_1F9FBC(self, 1, &sp24, 0U, 0);
                }
                if ((s32) self->mode != 3) {

                } else {
                    temp_r3_37 = fighterState->unk50;
                    if (!(temp_r3_37 & 0x02000000)) {
                        if (!(temp_r3_37 & 1)) {
                            sp20 = -1;
                            fn_27_1F9FBC(self, 1, &sp20, 0U, 0);
                        } else if (((s32) reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk370 != 8) && (fn_27_20B568(fighterState) != 0) && ((__fabsf(fighterState->vector5C.m_x - self->script->unkE0) < constants->f00[4]) || (fn_27_20BCBC(fighterState, &fighterState->vector5C, -fighterState->unkA0) > constants->f00[7]))) {
                            fn_27_1FD190(self);
                            sp1C = -1;
                            fn_27_1F9FBC(self, 2, &sp1C, 0x2050U, 0);
                        }
                    }
                }
                if (self->flags116 & 2) {
                    if (((s32) fighterState->unkAC != 0x2E) || (fn_27_1FBEE0(self, &stick, &buttons) == 0)) {
                        fn_27_1FC280(self, &stick, &buttons);
                        goto block_758;
                    }
                } else {
block_758:
                    if ((!(self->flags116 & 0x40) || ((s8) self->unk65 > 0) || (fn_27_1FB478(self, &stick, &buttons) == 0)) && (!(self->flags116 & 0x80) || (fn_27_1FB964(self, &stick, &buttons) == 0))) {
                        temp_r0_33 = self->mode;
                        if ((u32) temp_r0_33 <= 0x16U) {
                            switch (temp_r0_33) {   /* switch 5 */
                            case 0x1:               /* switch 5 */
                                fn_27_1FC8C4(self, &stick, &buttons);
                                break;
                            case 0x2:               /* switch 5 */
                                fn_27_1FD9EC(self, &stick, &buttons);
                                break;
                            case 0x3:               /* switch 5 */
                                fn_27_1FE5A4(self, &stick, &buttons);
                                break;
                            case 0x4:               /* switch 5 */
                                fn_27_1FE78C(self, &stick, &buttons);
                                break;
                            case 0x5:               /* switch 5 */
                            case 0x7:               /* switch 5 */
                            case 0x16:              /* switch 5 */
                                fn_27_1FF328(self, &stick, &buttons);
                                break;
                            case 0x6:               /* switch 5 */
                            case 0xB:               /* switch 5 */
                                fn_27_1FFDC0(self, &stick, &buttons);
                                break;
                            case 0x8:               /* switch 5 */
                                self->targetId = (s8) self->unk43;
                                temp_r3_38 = fn_27_1F1F58((s8 *) &self->unk43);
                                if (fighterState->unkBC != temp_r3_38->unkBC) {
                                    fn_27_1FFDC0(self, &stick, &buttons);
                                } else {
                                    temp_f2_14 = temp_r3_38->vector5C.m_x - fighterState->vector5C.m_x;
                                    temp_f2_15 = __fabsf(temp_f2_14) - constants->f00[18];
                                    if (temp_f2_14 > constants->f00[0]) {
                                        var_f1_3 = constants->f00[8];
                                    } else {
                                        var_f1_3 = constants->f98[25];
                                    }
                                    if (temp_f2_15 > constants->f00[1]) {
                                        stick.m_x = var_f1_3;
                                    } else if (temp_f2_15 > constants->f00[4]) {
                                        stick.m_x = constants->f98[4] * var_f1_3;
                                    } else if (temp_f2_15 > constants->f00[21]) {
                                        stick.m_x = constants->f00[19] * var_f1_3;
                                    } else {
                                        temp_f2_16 = temp_r3_38->unkA0;
                                        if ((temp_f2_16 * fighterState->unkA0) > constants->f00[0]) {
                                            stick.m_x = constants->f00[3] * temp_f2_16;
                                        }
                                        sp18 = -1;
                                        fn_27_1F9FBC(self, 2, &sp18, 0U, 0);
                                    }
                                }
                                break;
                            case 0x9:               /* switch 5 */
                                fn_27_203274(self, &stick, &buttons);
                                break;
                            case 0xA:               /* switch 5 */
                                fn_27_20362C(self, &stick, &buttons);
                                break;
                            case 0xC:               /* switch 5 */
                                fn_27_2037A4(self, &stick, &buttons);
                                break;
                            case 0xD:               /* switch 5 */
                                fn_27_204148(self, &stick, &buttons);
                                break;
                            case 0xE:               /* switch 5 */
                                fn_27_204B64(self, &stick, &buttons);
                                break;
                            case 0x10:              /* switch 5 */
                                fn_27_2056D0(self, &stick, &buttons);
                                break;
                            case 0xF:               /* switch 5 */
                                fn_27_2051AC(self, &stick, &buttons);
                                break;
                            case 0x11:              /* switch 5 */
                                fn_27_205E2C(self, &stick, &buttons);
                                break;
                            case 0x12:              /* switch 5 */
                                fn_27_2061B8(self, &stick, &buttons);
                                break;
                            case 0x13:              /* switch 5 */
                                fn_27_206428(self, &stick, &buttons);
                                break;
                            case 0x14:              /* switch 5 */
                                fn_27_2066D4(self, &stick, &buttons);
                                break;
                            case 0x15:              /* switch 5 */
                                fn_27_206A68(self, &stick, &buttons);
                                break;
                            }
                        }
                    }
                }
                fn_27_20C77C(self->script, &stick, &buttons);
                if (((s32) lbl_27_bss_5520 != 0) && (fighterState->unk50 & 8)) {
                    buttons |= soController::getButtonMask(soController::Pad_Button_Guard);
                }
                if (!(self->flags116 & 1) || ((s8) (u8) self->parameters.level < 0x19) || (((s32) fighterState->unkAC == 0x2F) && (fn_27_20B6DC(fn_27_1F1F58(&self->targetId)) != 0))) {
                    if (((s32) buttons == 0) && !(fighterState->unk50 & 1) && (__fabsf(stick.m_x) > constants->f00[19])) {
                        sp120 = fn_27_22009C(&fighterState->history, 1);
                        if ((stick.m_x * sp120.m_x) < constants->f98[26]) {
                            self->unk3E = 0;
                        }
                        temp_f1_14 = ((stick.m_x - constants->f98[25]) >= constants->f00[0]) ? stick.m_x : constants->f98[25];
                        stick.m_x = ((temp_f1_14 - constants->f00[8]) >= constants->f00[0]) ? constants->f00[8] : temp_f1_14;
                        temp_r3_39 = self->unk3E;
                        if (temp_r3_39 < 8U) {
                            temp_r3_40 = temp_r3_39 + 1;
                            self->unk3E = temp_r3_40;
                            temp_f0_4 = constants->f00[19] + ((__fabsf(stick.m_x) - constants->f00[19]) * (constants->f98[27] * (f32) temp_r3_40));
                            if (stick.m_x > constants->f00[0]) {
                                stick.m_x = temp_f0_4;
                            } else {
                                stick.m_x = -temp_f0_4;
                            }
                        }
                    } else {
                        self->unk3E = 0;
                    }
                }
                if (fn_27_20B6AC(fighterState, 2U, 0x12) != 0) {
                    temp_r3_41 = self->unk70;
                    if (temp_r3_41 <= 0) {
                        buttons |= soController::getButtonMask(soController::Pad_Button_Attack);
                        self->unk70 = (0x68 - (s8) (u8) self->parameters.level) * 2;
                    } else {
                        self->unk70 = temp_r3_41 - 1;
                    }
                }
                if (((u8) fighterState->unk1BA == 0x11) || (fn_27_20B6AC(fighterState, 1U, 0xB) != 0) || (fn_27_20B6AC(fighterState, 1U, 0x30) != 0)) {
                    fn_27_1FAEDC(self, &stick, &buttons, constants->f00[1], constants->f00[18], constants->f98[11]);
                } else if ((fn_27_20B6AC(fighterState, 2U, 0x16) != 0) && (temp_r0_34 = (u8) self->parameters.level, (((s8) temp_r0_34 > 0x1E) != 0))) {
                    fn_27_1FAEDC(self, &stick, &buttons, constants->f98[9], constants->f00[4], constants->f98[28] * (f32) ((s8) temp_r0_34 - 0x1E));
                } else if (((s32) buttons == 0) && (temp_r0_35 = self->mode, ((temp_r0_35 == 0x15) == 0)) && (temp_r0_35 != 3) && (temp_r0_35 != 0xE) && (temp_r5_5 = (u8) self->parameters.level, (((s8) temp_r5_5 > 0x14) != 0)) && (temp_r3_42 = self->script, (((s32) temp_r3_42->unkF8 == 0) != 0)) && (temp_r4_11 = fighterState->unk50, (((temp_r4_11 & 1) == 0) == 0)) && (temp_r0_36 = fighterState->unk1BA, ((temp_r0_36 == 6) == 0)) && (temp_r0_36 != 7) && (temp_r0_36 != 0x10) && (temp_r0_37 = temp_r3_42->action, ((temp_r0_37 == 0x10A0) == 0)) && (temp_r0_37 != 0x1140) && (temp_r0_37 != 0x90) && (fighterState->unk84 < constants->f98[1])) {
                    temp_r0_38 = fighterState->unkAC;
                    if (temp_r0_38 != 0x1B) {
                        if (temp_r0_38 < 0x1B) {
                            if (temp_r0_38 < 5) {
                                if (temp_r0_38 != 2) {
                                    if ((temp_r0_38 < 2) && (temp_r0_38 < 1)) {
                                        goto block_853;
                                    }
                                    goto block_852;
                                }
                                goto block_853;
                            }
                            if (temp_r0_38 != 7) {
                                goto block_853;
                            }
                            goto block_852;
                        }
                        if (temp_r0_38 != 0x2F) {
                            if (temp_r0_38 < 0x2F) {
                                if (temp_r0_38 != 0x21) {
                                    goto block_853;
                                }
                                goto block_852;
                            }
                            goto block_853;
                        }
                        goto block_852;
                    }
block_852:
                    if (!(temp_r4_11 & 0x800)) {
block_853:
                        fn_27_1FAEDC(self, &stick, &buttons, constants->f00[1], constants->f00[4], constants->f98[29] * (f32) ((s8) temp_r5_5 - 0x14));
                    }
                } else {
                    temp_r0_39 = fighterState->unkAC;
                    if (temp_r0_39 != 0x13) {
                        if (temp_r0_39 < 0x13) {
                            if (temp_r0_39 != 6) {
                                goto block_872;
                            }
                            goto block_860;
                        }
                        if (temp_r0_39 != 0x2C) {
block_872:
                            self->unk8C = constants->f00[0];
                        } else {
                            goto block_860;
                        }
                    } else {
block_860:
                        if ((fighterState->unk50 & 0x800) && (fn_27_20B568(fighterState) != 0) && (temp_r0_40 = (u8) self->parameters.level, (((s8) temp_r0_40 > 0x1E) != 0))) {
                            temp_r0_41 = reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk370;
                                switch (temp_r0_41) { /* switch 6 */
                                case 0x1:           /* switch 6 */
                                case 0x2:           /* switch 6 */
                                case 0x3:           /* switch 6 */
                                case 0x4:           /* switch 6 */
                                case 0x9:           /* switch 6 */
                                case 0xC:           /* switch 6 */
                                case 0xD:           /* switch 6 */
                                case 0xE:           /* switch 6 */
                                case 0x13:          /* switch 6 */
                                case 0x14:          /* switch 6 */
                                case 0x15:          /* switch 6 */
                                case 0x16:          /* switch 6 */
                                case 0x17:          /* switch 6 */
                                case 0x19:          /* switch 6 */
                                case 0x1E:          /* switch 6 */
                                case 0x21:          /* switch 6 */
                                case 0x24:          /* switch 6 */
                                case 0x2B:          /* switch 6 */
                                case 0x2E:          /* switch 6 */
                                case 0x32:          /* switch 6 */
                                    fn_27_1FAEDC(self, &stick, &buttons, constants->f00[1], constants->f00[4], constants->f98[30] * (f32) ((s8) temp_r0_40 - 0x14));
                                    break;
                                default:
                            case 0x0:               /* switch 6 */
                            case 0x5:               /* switch 6 */
                            case 0x6:               /* switch 6 */
                            case 0x7:               /* switch 6 */
                            case 0x8:               /* switch 6 */
                            case 0xA:               /* switch 6 */
                            case 0xB:               /* switch 6 */
                            case 0xF:               /* switch 6 */
                            case 0x10:              /* switch 6 */
                            case 0x11:              /* switch 6 */
                            case 0x12:              /* switch 6 */
                            case 0x18:              /* switch 6 */
                            case 0x1A:              /* switch 6 */
                            case 0x1B:              /* switch 6 */
                            case 0x1C:              /* switch 6 */
                            case 0x1D:              /* switch 6 */
                            case 0x1F:              /* switch 6 */
                            case 0x20:              /* switch 6 */
                            case 0x22:              /* switch 6 */
                            case 0x23:              /* switch 6 */
                            case 0x25:              /* switch 6 */
                            case 0x26:              /* switch 6 */
                            case 0x27:              /* switch 6 */
                            case 0x28:              /* switch 6 */
                            case 0x29:              /* switch 6 */
                            case 0x2A:              /* switch 6 */
                            case 0x2C:              /* switch 6 */
                            case 0x2D:              /* switch 6 */
                            case 0x2F:              /* switch 6 */
                            case 0x30:              /* switch 6 */
                            case 0x31:              /* switch 6 */
                                temp_r3_43 = fn_27_1F1F58(&self->targetId)->unkBC;
                                spC8.m_x = temp_r3_43->unk18 + temp_r3_43->unk20;
                                spC8.m_y = temp_r3_43->unk1C + temp_r3_43->unk24;
                                Vec2f::copy(sp110, spC8);
                                spC0.m_x = sp110.m_x * constants->f00[19];
                                spC0.m_y = sp110.m_y * constants->f00[19];
                                Vec2f::copy(sp150, spC0);
                                temp_f5 = sp150.m_x - fighterState->unk74;
                                Vec2f::copy(sp118, spC0);
                                temp_f4_4 = sp150.m_y - fighterState->unk78;
                                sp150.m_x = temp_f5;
                                sp150.m_y = temp_f4_4;
                                if ((fighterState->unkBC == temp_r3_43) || (temp_f2_17 = fighterState->vector5C.m_x + (constants->f98[9] * fighterState->unk80), ((temp_f2_17 < (constants->f00[14] + reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk360)) != 0)) || (temp_f2_17 > (reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk364 - constants->f00[14])) || (((temp_f5 * temp_f5) + (temp_f4_4 * temp_f4_4)) < constants->f98[31])) {
                                    fn_27_1FAEDC(self, &stick, &buttons, constants->f98[32], constants->f00[1], constants->f00[25] + (constants->f98[33] * (f32) (s8) (u8) self->parameters.level));
                                }
                            }
                        } else {
                            self->unk8C = constants->f00[0];
                        }
                    }
                }
                if (((s8) (u8) self->parameters.level >= 0x32) && (__fabsf(self->unk8C) < constants->f00[6])) {
                    temp_r0_42 = self->script->action;
                    if ((temp_r0_42 != 0x10A0) && (temp_r0_42 != 0x1140) && (fn_27_20B6AC(fighterState, 2U, 0x20) == 0)) {
                        if ((s32) fighterState->unk1B9 != 0) {
                            temp_r3_44 = self->unk3F;
                            if ((s32) temp_r3_44 != 0) {
                                self->unk3F = temp_r3_44 - 1;
                            } else {
                                temp_r3_45 = self->mode;
                                var_r22_4 = 1;
                                switch (temp_r3_45) { /* switch 7 */
                                case 0x5:           /* switch 7 */
                                case 0x6:           /* switch 7 */
                                case 0x7:           /* switch 7 */
                                case 0xB:           /* switch 7 */
                                case 0x16:          /* switch 7 */
                                    temp_r6_2 = fighterState->unkBC;
                                    temp_r5_6 = self->script;
                                    temp_r7 = temp_r6_2->unk44;
                                    if (temp_r7 == NULL) {
                                        var_r4 = 0;
                                    } else {
                                        var_r4 = 0;
                                        if (((u32) temp_r5_6->unkFC == (u32) temp_r6_2->unk48) && ((u32) temp_r5_6->unkF8 == (u32) temp_r7->unk1C)) {
                                            var_r4 = 1;
                                        }
                                    }
                                    if (var_r4 == 0) {
                                        var_r22_4 = 0;
                                    }
                                    break;
                                case 0x8:           /* switch 7 */
                                    temp_r6_3 = fighterState->unkBC;
                                    if (temp_r6_3 != fn_27_1F1F58((s8 *) &self->unk43)->unkBC) {
                                        temp_r7_2 = temp_r6_3->unk44;
                                        temp_r5_7 = self->script;
                                        if (temp_r7_2 == NULL) {
                                            var_r4_2 = 0;
                                        } else {
                                            var_r4_2 = 0;
                                            if (((u32) temp_r5_7->unkFC == (u32) temp_r6_3->unk48) && ((u32) temp_r5_7->unkF8 == (u32) temp_r7_2->unk1C)) {
                                                var_r4_2 = 1;
                                            }
                                        }
                                        if (var_r4_2 == 0) {
                                            var_r22_4 = 0;
                                        }
                                    }
                                    break;
                                case 0xF:           /* switch 7 */
                                case 0x10:          /* switch 7 */
                                    var_r22_4 = 0;
                                    break;
                                default:            /* switch 7 */
                                    if (((u16) self->script->action == 0x1080) && (fn_27_20B668(fighterState) != 0)) {
                                        var_r22_4 = 0;
                                    } else {
                                        temp_r3_46 = fn_27_1F1F58(&self->targetId);
                                        if ((temp_r3_46->vector5C.m_y > fighterState->vector5C.m_y) && (fn_27_20B568(temp_r3_46) != 0) && (fn_27_20B898(fighterState, &self->targetId, constants->f00[0]) < constants->f98[9])) {
                                            var_r22_4 = 0;
                                        } else if ((fighterState->unk50 & 1) && (fn_27_20B668(fighterState) == 0) && (randf() < constants->f00[2])) {
                                            var_r22_4 = 0;
                                        }
                                    }
                                    break;
                                }
                                if (var_r22_4 != 0) {
                                    if ((s32) fighterState->unkAC != 0x2E) {

                                    } else if (fn_27_20B6AC(fighterState, 0x10U, -1) != 0) {
                                        var_r22_4 = 0;
                                    }
                                }
                                if ((var_r22_4 == 0) || (randf() < constants->f00[26])) {
                                    self->unk3F = (u8) (s32) (constants->f98[14] + (constants->f00[21] * randf()));
                                } else {
                                    if (fn_27_20B568(fighterState) != 0) {
                                        var_r0 = buttons == 0;
                                        if (var_r0 != 0) {
                                            var_r0 = __fabsf(stick.m_y) < constants->f00[10];
                                        }
                                        if (var_r0 != 0) {
                                            sp108 = fn_27_22009C(&fighterState->history, 0);
                                            var_r0 = __fabsf(sp108.m_y) < constants->f00[10];
                                        }
                                        if (var_r0 != 0) {
                                            temp_r21_13 = (s8) (u8) self->parameters.level;
                                            if (randf() < (constants->f00[10] * (f32) (temp_r21_13 - 0xA))) {
                                                stick.m_y = constants->f98[25];
                                            }
                                        }
                                    }
                                    self->unk3F = 0x14;
                                }
                            }
                        } else {
                            temp_r4_12 = self->unk3F;
                            temp_r3_47 = 0x64 - (s8) (u8) self->parameters.level;
                            temp_r21_14 = (s32) ((temp_r3_47 >> 0x1FU) + temp_r3_47) >> 1;
                            if (((s32) temp_r4_12 < temp_r21_14) || ((s32) temp_r4_12 > (s32) (temp_r21_14 + 8))) {
                                self->unk3F = (u8) (s32) ((f32) temp_r21_14 + (constants->f98[15] * randf()));
                            }
                        }
                    }
                }
                fn_27_1FB0A8(self, &stick, &buttons);
                temp_r0_43 = fighterState->unkAC;
                if (temp_r0_43 != 0x13) {
                    if (temp_r0_43 < 0x13) {
                        if (temp_r0_43 != 0xC) {
                            if (temp_r0_43 < 0xC) {
                                if (temp_r0_43 != 6) {

                                } else {
                                    goto block_999;
                                }
                            }
                        } else {
                            temp_r0_44 = (u8) self->parameters.level;
                            if ((s8) temp_r0_44 >= 0x37) {
                                temp_r3_48 = self->mode;
                                if (temp_r3_48 == 3) {
                                    if (fn_27_20B6AC(fighterState, 1U, -1) != 0) {
                                        temp_r3_49 = fighterState->unkBC;
                                        if (fighterState->vector5C.m_x < temp_r3_49->unk18) {
                                            var_f29_7 = temp_r3_49->unk1C;
                                        } else {
                                            var_f29_7 = temp_r3_49->unk24;
                                        }
                                        temp_f1_15 = fn_27_20BCBC(fighterState, &fighterState->vector5C, fighterState->unkA0);
                                        if (__fabsf(temp_f1_15) > constants->f98[9]) {
                                            buttons |= soController::getButtonMask(soController::Pad_Button_Jump);
                                        } else if (fn_27_20B898(fighterState, &self->targetId, constants->f00[0]) > constants->f00[17]) {
                                            temp_f29_9 = constants->f00[6] + (constants->f98[34] * (fighterState->vector5C.m_y - (var_f29_7 - constants->f00[4])));
                                            if (randf() > temp_f29_9) {
                                                buttons |= soController::getButtonMask(soController::Pad_Button_Jump);
                                            }
                                        } else if ((fighterState->vector5C.m_y > (var_f29_7 - constants->f00[4])) || (temp_f1_15 > constants->f98[35]) || (temp_f1_15 < constants->f98[16])) {
                                            buttons |= soController::getButtonMask(soController::Pad_Button_Jump);
                                        }
                                    }
                                } else if ((temp_r3_48 != 2) && ((s8) temp_r0_44 >= 0x46) && ((s8) (u8) self->targetId != (s8) (u8) self->fighterId) && !(buttons & soController::getButtonMask(soController::Pad_Button_Guard))) {
                                    temp_f29_10 = __fabsf(fn_27_1F1F58(&self->targetId)->unk78 - (fighterState->unk78 - constants->f00[21]));
                                    if (temp_f29_10 < (constants->f98[8] + (constants->f00[19] * fn_27_21F244(&self->targetId)))) {
                                        temp_r21_15 = self->script->action;
                                        if (fn_27_20B6AC(fighterState, 1U, -1) != 0) {
                                            if ((temp_r21_15 != 0x2050) && (((u8) fighterState->unk4 != 3) || (fn_27_20B898(fighterState, &self->targetId, constants->f00[0]) > constants->f00[7]))) {
                                                buttons |= soController::getButtonMask(soController::Pad_Button_Jump);
                                            }
                                        } else if ((fn_27_20B668(fighterState) != 0) && (fn_27_20B6AC(fighterState, 2U, -1) == 0)) {
                                            if ((s32) temp_r21_15 != 0x56) {
                                                if ((s32) temp_r21_15 < 0x56) {
                                                    if ((s32) temp_r21_15 != 0x52) {
                                                        if ((s32) temp_r21_15 < 0x52) {
                                                            if ((s32) temp_r21_15 < 0x51) {

                                                            } else {
                                                                goto block_977;
                                                            }
                                                        } else if ((s32) temp_r21_15 < 0x54) {
                                                            goto block_977;
                                                        }
                                                    }
                                                } else if ((s32) temp_r21_15 != 0x1080) {

                                                } else {
                                                    goto block_977;
                                                }
                                            } else {
block_977:
                                                temp_f1_16 = fn_27_20B758(fighterState, &self->targetId, constants->f00[0]);
                                                if (((s32) buttons == 0) && (__fabsf(temp_f1_16) < constants->f98[32]) && (randf() < constants->f00[26])) {
                                                    stick.m_y = constants->f98[25];
                                                    buttons |= soController::getButtonMask(soController::Pad_Button_Jump);
                                                    if (temp_r21_15 != 0x1080) {
                                                        sp14 = -1;
                                                        fn_27_1F9FBC(self, 1, &sp14, 0x1080U, 0);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if (temp_r0_43 != 0x2C) {
                        if (temp_r0_43 < 0x2C) {
                            if (temp_r0_43 != 0x20) {

                            } else if ((fn_27_20B6AC(fighterState, 4U, -1) != 0) && ((s8) (u8) self->parameters.level >= 0x14) && ((fn_27_20B568(fighterState) == 0) || (__fabsf(fn_27_20BCBC(fighterState, &fighterState->vector5C, fighterState->unkA0)) < constants->f00[4]))) {
                                var_r21_6 = 0;
                                if (fighterState->unk84 > constants->f00[0]) {
                                    sp184.xy.m_x = fighterState->vector5C.m_x;
                                    sp184.xy.m_y = fighterState->vector5C.m_y;
                                    sp184.z = fighterState->unk64;
                                    sp184.xy.m_x += constants->f98[9] * fighterState->unk80;
                                    if (fn_27_20B610(fighterState, &sp184.xy) != 0) {
                                        var_r21_6 = 1;
                                    }
                                } else if (fn_27_20B568(fighterState) != 0) {
                                    var_r21_6 = 1;
                                }
                                var_r0_2 = var_r21_6 == 0;
                                if (var_r0_2 != 0) {
                                    var_r0_2 = buttons == 0;
                                }
                                if (var_r0_2 != 0) {
                                    var_r0_2 = __fabsf(stick.m_y) < constants->f00[10];
                                }
                                if (var_r0_2 != 0) {
                                    sp100 = fn_27_22009C(&fighterState->history, 0);
                                    var_r0_2 = __fabsf(sp100.m_y) < constants->f00[10];
                                }
                                if (var_r0_2 != 0) {
                                    stick.m_y = constants->f98[25];
                                }
                            }
                        }
                    } else {
                        goto block_999;
                    }
                } else {
block_999:
                    if (((s8) (u8) self->parameters.level >= 0x32) && ((fn_27_20B6AC(fighterState, 1U, 6) != 0) || (fn_27_20B6AC(fighterState, 1U, 0x13) != 0) || (fn_27_20B6AC(fighterState, 1U, 0x2C) != 0))) {
                        temp_f31_4 = fn_27_20BCBC(fighterState, &fighterState->vector5C, fighterState->unkA0);
                        if (fn_27_20B568(fighterState) != 0) {
                            if (temp_f31_4 < constants->f00[29]) {
                                temp_f29_11 = constants->f00[26] + (constants->f98[36] * (f32) ((s8) (u8) self->parameters.level - 0x32));
                                if (randf() < temp_f29_11) {
                                    buttons |= soController::getButtonMask(soController::Pad_Button_Special);
                                }
                            }
                        } else if (temp_f31_4 > constants->f98[37]) {
                            temp_r3_50 = fighterState->unkBC;
                            temp_f1_17 = fighterState->vector5C.m_x;
                            temp_f0_5 = temp_r3_50->unk18;
                            if (temp_f1_17 < temp_f0_5) {
                                var_f0 = temp_r3_50->unk20 - temp_f1_17;
                            } else {
                                var_f0 = temp_f0_5 - temp_f1_17;
                            }
                            if (__fabsf(var_f0) < constants->f00[29]) {
                                var_f29_8 = constants->f00[26] + (constants->f98[36] * (f32) ((s8) (u8) self->parameters.level - 0x32));
                            } else {
                                var_f29_8 = constants->f00[12];
                            }
                            if (randf() < var_f29_8) {
                                buttons |= soController::getButtonMask(soController::Pad_Button_Special);
                            }
                        }
                    }
                }
                if (((s32) buttons == 0) && (fn_27_20B694(fighterState, 0x8000U) != 0)) {
                    temp_r0_45 = (u8) self->parameters.level;
                    if ((s8) temp_r0_45 >= 0x28) {
                        var_r22_5 = 0;
                        if ((s16) fighterState->unkA8 == 0) {
                            var_r22_5 = 1;
                        } else if (((s8) temp_r0_45 > 0x2D) && (fn_27_20B694(fighterState, 0x20000U) != 0)) {
                            temp_r0_46 = self->script->action;
                            if ((temp_r0_46 != 0x10A0) && (temp_r0_46 != 0x1140) && (fn_27_20B568(fn_27_1F1F58(&self->targetId)) == 0)) {
                                spF8 = fn_27_20BDE8(fighterState);
                                Vec2f::copy(sp148, spF8);
                                if ((fighterState->vector5C.m_y > sp148.m_y) && (__fabsf(fighterState->vector5C.m_x - sp148.m_x) < constants->f98[38])) {
                                    fn_27_20B9E0(fighterState, &sp178, &self->targetId, constants->f00[0]);
                                    temp_f29_12 = __fabsf(sp178.m_x);
                                    if ((temp_f29_12 < fn_27_21F1BC(&self->fighterId)) && (sp178.m_y < constants->f98[39])) {
                                        temp_f31_5 = constants->f98[1] * fn_27_21F2CC(&self->fighterId);
                                        if (sp178.m_y > -(fn_27_21F244(&self->targetId) + temp_f31_5)) {
                                            temp_r21_16 = (u8) self->parameters.level;
                                            if (randf() < (constants->f98[40] * (f32) ((s8) temp_r21_16 - 0x28))) {
                                                var_r22_5 = 1;
                                                self->unk76 = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (var_r22_5 != 0) {
                            temp_r3_52 = self->unk76 - 1;
                            self->unk76 = temp_r3_52;
                            if ((s8) temp_r3_52 <= 0) {
                                temp_f29_13 = constants->f00[10] * (f32) (0x64 - (s8) (u8) self->parameters.level);
                                if (fn_27_20B568(fighterState) != 0) {
                                    self->unk76 = (u8) (s32) (constants->f98[41] + (constants->f98[42] * temp_f29_13));
                                } else {
                                    self->unk76 = (u8) (s32) (constants->f98[11] + (constants->f98[43] * temp_f29_13));
                                }
                                buttons |= soController::getButtonMask(soController::Pad_Button_Jump);
                            }
                        }
                    }
                }
                if (((s32) buttons == 0) && ((u8) fighterState->unk1BA == 0xE)) {
                    temp_r21_17 = (u8) self->parameters.level;
                    if (randf() < (constants->f00[19] * (constants->f00[10] * (f32) (s8) temp_r21_17))) {
                        stick.m_y = constants->f00[13];
                    }
                }
                temp_r3_53 = self->unk40;
                if ((s32) temp_r3_53 != 0) {
                    if (temp_r3_53 > 2U) {
                        temp_r3_54 = temp_r3_53 - 1;
                        self->unk40 = temp_r3_54;
                        if (temp_r3_54 <= 2U) {
                            if (__fabsf(fighterState->vector5C.m_y - fn_27_1F1F58(&self->targetId)->vector5C.m_y) < constants->f00[4]) {
                                temp_f1_18 = self->value118 - (constants->f00[5] * (constants->f98[8] + randf()));
                                self->value118 = temp_f1_18;
                                if (temp_f1_18 < constants->f98[16]) {
                                    self->value118 = constants->f00[4];
                                }
                            }
                            self->unk_41 = -1;
                            self->unk40 = 0;
                        }
                    } else if (temp_r3_53 == 2) {
                        temp_r22_4 = soController::getButtonMask(soController::Pad_Button_Special);
                        if (!(buttons & (soController::getButtonMask(soController::Pad_Button_Attack) | temp_r22_4))) {
                            self->unk40 = 0x20;
                        }
                    } else if (fn_27_20B63C(fighterState) != 0) {
                        temp_r22_5 = soController::getButtonMask(soController::Pad_Button_Special);
                        if (buttons & (soController::getButtonMask(soController::Pad_Button_Attack) | temp_r22_5)) {
                            self->unk40 = 2;
                        }
                    }
                }
                if (stageData != NULL) {
                    temp_r4_14 = (u8) self->counter66;
                    temp_cr1_eq = (s8) temp_r4_14 == 0;
                    self->unk67 = stageData->code2;
                    if ((s8) temp_r4_14 > 0) {
                        self->counter66 = temp_r4_14 - 1;
                    } else if (temp_cr1_eq != 0) {
                        temp_r0_47 = stageData->code2;
                        temp_f31_6 = constants->f00[10] * (f32) (s8) (u8) self->parameters.level;
                        if ((s32) temp_r0_47 != 8) {
                            if ((s32) temp_r0_47 < 8) {
                                if ((s32) temp_r0_47 != 5) {
                                    if ((s32) temp_r0_47 < 5) {
                                        if ((s32) temp_r0_47 < 4) {

                                        } else if (!(self->flags & 0x10)) {
                                            if ((fn_27_20B694(fighterState, 0x20040U) != 0) && (!(fighterState->unk50 & 1) || (fighterState->unk84 < constants->f98[26]))) {
                                                temp_r22_6 = soController::getButtonMask(soController::Pad_Button_Jump);
                                                if (!(fn_27_2200FC(&fighterState->history, 0) & temp_r22_6)) {
                                                    if (randf() < (constants->f98[4] * temp_f31_6)) {
                                                        buttons = soController::getButtonMask(soController::Pad_Button_Jump);
                                                    } else {
                                                        self->counter66 = (s8) (constants->f98[8] + (constants->f98[14] * randf()));
                                                    }
                                                }
                                            }
                                        } else if ((s32) stageData->unk9 != 0) {
                                            if (randf() < (constants->f98[8] * temp_f31_6)) {
                                                buttons = soController::getButtonMask(soController::Pad_Button_Jump);
                                                self->flags &= 0xFFFFFFEF;
                                            }
                                        } else if (((s32) stageData->unk8 != 0) && (!(fighterState->unk50 & 1) || (fighterState->unk84 < constants->f98[26])) && (randf() < (constants->f00[10] * temp_f31_6))) {
                                            buttons = soController::getButtonMask(soController::Pad_Button_Jump);
                                        }
                                    } else if (self->flags & 0x10) {
                                        temp_f2_18 = constants->f98[32] * randf();
                                        self->flags &= 0xFFFFFFEF;
                                        self->unk5A = (s16) (constants->f00[21] + ((constants->f00[8] - temp_f31_6) * temp_f2_18));
                                    }
                                }
                            } else if ((s32) temp_r0_47 < 0xA) {
                                if (self->flags & 0x10) {
                                    temp_f1_19 = constants->f98[9] * randf();
                                    self->flags &= 0xFFFFFFEF;
                                    self->counter66 = (s8) ((constants->f00[8] - temp_f31_6) * temp_f1_19);
                                } else if (fn_27_20B63C(fighterState) != 0) {
                                    temp_f2_19 = randf() * (constants->f00[8] - (constants->f00[32] * temp_f31_6));
                                    if (temp_f2_19 < constants->f00[2]) {
                                        stick.m_x = constants->f00[0];
                                        stick.m_y = constants->f00[0];
                                        if (temp_f2_19 < constants->f00[26]) {
                                            buttons = soController::getButtonMask(soController::Pad_Button_Appeal_Hi);
                                        } else {
                                            if (temp_f2_19 < constants->f98[1]) {
                                                var_r3_3 = soController::getButtonMask(soController::Pad_Button_Appeal_Lw);
                                            } else {
                                                var_r3_3 = soController::getButtonMask(soController::Pad_Button_Appeal_S);
                                            }
                                            buttons = var_r3_3;
                                        }
                                        self->counter66 = -1;
                                    } else {
                                        self->counter66 = (s8) (constants->f00[21] + (constants->f98[44] * (constants->f00[8] - temp_f31_6)));
                                    }
                                }
                            }
                        } else if (temp_cr1_eq != 0) {
                            buttons = 0;
                            stick.m_x = constants->f00[0];
                            stick.m_y = constants->f00[0];
                        }
                    }
                    self->unk68 = 0;
                } else if ((s32) reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk370 == 0x1C) {
                    if (lbl_27_bss_5668 != NULL) {
                        temp_r3_55 = static_cast<StageAiDataView*>(lbl_27_bss_5668->getMadeinAiData());
                        if ((temp_r3_55 != NULL) && ((s32) temp_r3_55->flag0 != 0)) {
                            if ((s32) temp_r3_55->code2 != 8) {

                            } else if ((s32) self->unk68 > (s32) (0x82 - (s8) (u8) self->parameters.level)) {
                                buttons = 0;
                                stick.m_x = constants->f00[0];
                                stick.m_y = constants->f00[0];
                            }
                            self->unk68 += 1;
                        } else {
                            self->unk68 = 0;
                        }
                    }
                    if (((s32) self->unk68 == 0) && ((s32) self->unk67 == 8)) {
                        if ((s8) (u8) self->counter66 <= 0) {
                            temp_r21_18 = (u8) self->parameters.level;
                            self->counter66 = (s8) (constants->f00[8] + (constants->f98[4] * (f32) (0x64 - (s8) temp_r21_18) * (constants->f00[32] + (constants->f00[13] * randf()))));
                        }
                        temp_r3_56 = (u8) self->counter66;
                        if ((s8) temp_r3_56 > 0) {
                            temp_r3_57 = temp_r3_56 - 1;
                            self->counter66 = (s8) temp_r3_57;
                            if ((s8) temp_r3_57 == 0) {
                                self->unk67 = -1U;
                            } else {
                                buttons = 0;
                                stick.m_x = constants->f00[0];
                                stick.m_y = constants->f00[0];
                            }
                        }
                    } else {
                        self->counter66 = 0;
                        self->flags |= 0x10;
                    }
                }
                if ((s32) reinterpret_cast<const AiManagerView*>(g_aiMgr)->unk370 != 0x31) {

                } else if (((s32) fighterState->unkC0 != 0) && ((fn_27_20B694(fighterState, 0x40U) != 0) || ((u8) fighterState->unk1BA == 0x16))) {
                    buttons = 0;
                    stick.m_x = constants->f00[8];
                    stick.m_y = constants->f00[8];
                }
                if (((s8) (u8) self->parameters.level >= 0x14) && (buttons & soController::getButtonMask(soController::Pad_Button_Guard)) && ((u8) fighterState->unk1BA == 0x15) && (fighterState->unkDC < constants->f98[15])) {
                    temp_f1_20 = randf();
                    if (temp_f1_20 < constants->f98[1]) {
                        stick.m_x = constants->f00[8];
                    } else {
                        temp_cr0_lt = temp_f1_20 < constants->f98[4];
                        if (temp_cr0_lt != 0) {
                            stick.m_x = constants->f98[25];
                        }
                        if (temp_cr0_lt == 0) {
                            buttons &= ~soController::getButtonMask(soController::Pad_Button_Guard);
                        }
                    }
                    if ((u16) self->script->action == 0x3020) {
                        sp10 = -1;
                        fn_27_20DB40(self->script, 0U, &sp10, 0U, 0U);
                    }
                }
                if ((fighterState->unk50 & 0x100000) && ((s32) buttons == 0) && ((stick.m_x * fighterState->unkA0) > constants->f00[26])) {
                    stick.m_x *= constants->f00[26];
                }
                if ((s32) self->mode == 3) {
                    temp_r22_7 = soController::getButtonMask(soController::Pad_Button_Special);
                    if (buttons & (soController::getButtonMask(soController::Pad_Button_Attack) | temp_r22_7)) {
                        if (stick.m_x > constants->f00[6]) {
                            self->unk60 = 1;
                        } else if (stick.m_x < constants->f98[26]) {
                            self->unk60 = -1U;
                        } else {
                            if (fighterState->unkA0 > constants->f00[0]) {
                                var_r0_3 = 1;
                            } else {
                                var_r0_3 = -1U;
                            }
                            self->unk60 = var_r0_3;
                        }
                        self->unk61 = 6;
                    }
                }
                if ((s8) self->unk61 > 0) {
                    if ((s8) self->unk60 > 0) {
                        if (stick.m_x < constants->f00[0]) {
                            stick.m_x = constants->f00[0];
                        }
                    } else if (stick.m_x > constants->f00[0]) {
                        stick.m_x = constants->f00[0];
                    }
                    self->unk61 -= 1;
                }
                stick.m_x *= lbl_805A17F0;
                stick.m_y *= lbl_805A17F0;
                fn_27_1FAE10(&stick);
                Vec2f::copy(appliedStick, stick);
                self->mainStick.m_x = appliedStick.m_x;
                self->mainStick.m_y = appliedStick.m_y;
                self->buttons = (u32) (u16) (buttons | 0x8000);
                fn_27_21FFE4(&fighterState->history, &stick, &buttons);
                temp_r3_58 = self->unk6A;
                if (temp_r3_58 > 0) {
                    self->unk6A = temp_r3_58 - 1;
                }
                temp_r3_59 = self->unk77;
                if ((s32) temp_r3_59 != 0) {
                    self->unk77 = temp_r3_59 - 1;
                }
                temp_r0_48 = self->script->action;
                if ((s32) temp_r0_48 != 0x30A0) {
                    if ((s32) temp_r0_48 < 0x30A0) {
                        if ((s32) temp_r0_48 < 0x73) {
                            if ((s32) temp_r0_48 < 0x71) {

                            } else {
                                goto block_1171;
                            }
                        }
                    } else if ((s32) temp_r0_48 != 0x30B0) {

                    } else {
                        goto block_1171;
                    }
                } else {
block_1171:
                    self->unk77 = 0xA;
                }
                temp_r0_49 = fighterState->unk1BA;
                if ((temp_r0_49 != 5) && (temp_r0_49 != 9)) {
                    temp_f2_20 = self->unk78;
                    if (temp_f2_20 > constants->f00[0]) {
                        temp_f0_6 = temp_f2_20 - constants->f98[45];
                        self->unk78 = temp_f0_6;
                        if (temp_f0_6 < constants->f00[0]) {
                            self->unk78 = constants->f00[0];
                        }
                    }
                    temp_f2_21 = self->unk7C;
                    if (temp_f2_21 > constants->f00[0]) {
                        temp_f0_7 = temp_f2_21 - constants->f98[46];
                        self->unk7C = temp_f0_7;
                        if (temp_f0_7 < constants->f00[0]) {
                            self->unk7C = constants->f00[0];
                        }
                    }
                    temp_f2_22 = self->unk80;
                    if (temp_f2_22 > constants->f00[0]) {
                        temp_f0_8 = temp_f2_22 - constants->f98[46];
                        self->unk80 = temp_f0_8;
                        if (temp_f0_8 < constants->f00[0]) {
                            self->unk80 = constants->f00[0];
                        }
                    }
                }
                temp_r3_60 = self->unk62;
                if ((s32) temp_r3_60 != 0) {
                    self->unk62 = temp_r3_60 - 1;
                }
                self->unk54 += 1;
            }
            temp_r3_61 = self->partner;
            if (temp_r3_61 != NULL) {
                temp_r4_15 = fighterState->unk1BA;
                var_r5 = 0;
                if ((temp_r4_15 == 9) && ((s32) temp_r3_61->mode <= 0x79)) {
                    temp_r0_50 = fighterState->unkB4;
                    if (temp_r0_50 != 0x5B) {
                        if (temp_r0_50 < 0x5B) {
                            if (temp_r0_50 < 0x56) {
                                goto block_1195;
                            }
                        } else if (temp_r0_50 < 0x5E) {

                        } else {
                            goto block_1195;
                        }
                    } else {
block_1195:
                        var_r5 = 1;
                    }
                } else if ((temp_r4_15 == 0xF) || (fighterState->unk50 & 0x8000) || (temp_r4_15 == 0x11) || (temp_r4_15 == 0x17)) {
                    var_r5 = 1;
                }
                if (var_r5 != 0) {
                    temp_r4_16 = temp_r3_61->flags;
                    if (!(temp_r4_16 & 8)) {
                        temp_r3_61->flags = temp_r4_16 | 8;
                        if ((s32) temp_r3_61->mode >= 0x79) {
                            spC = -1;
                            fn_27_1F9FBC(temp_r3_61, 0, &spC, 0U, 0);
                        }
                    }
                } else {
                    temp_r4_17 = temp_r3_61->flags;
                    if (temp_r4_17 & 8) {
                        temp_r3_61->flags = temp_r4_17 & 0xFFFFFFF7;
                        if ((s32) temp_r3_61->mode < 0x79) {
                            sp8 = -1;
                            fn_27_1F9FBC(temp_r3_61, 0x79, &sp8, 0U, 0);
                        }
                    }
                }
                if (!(self->partner->flags & 8)) {
                    partnerButtons = 0;
                    partnerStick.m_x = constants->f00[0];
                    partnerStick.m_y = constants->f00[0];
                    fn_27_220034(&fighterState->history, (s32) (s8) fn_27_1F21B8()->unk1F, &partnerStick, &partnerButtons);
                    Vec2f::copy(forwardedStick, partnerStick);
                    fn_27_1F8A8C(self->partner, &forwardedStick, partnerButtons, &self->fighterId, ((u32) self->buttons >> 0xFU) & 1);
                }
            }
        }
    }
}
