#pragma force_active on

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

struct muSelCharPlayerArea {
    char pad0[0xAC];
    void* unkAC;
    char padB0[0x24];
    void* unkD4;
    char padD8[0xD0];
    s32 unk1A8;
    s32 unk1AC;
    char pad1B0[4];
    s32 unk1B4;
    s32 unk1B8;
    char pad1BC[4];
    s32 unk1C0;
    char pad1C4[4];
    s32 unk1C8;
    char pad1CC[4];
    s32 unk1D0;
    s32 unk1D4;
    s32 unk1D8;
    s32 unk1DC;
    char pad1E0[0x224];
    s32 unk404;
};

struct GGSub {
    char pad[4];
    u8 unk4;
};

struct GG {
    char pad[0x10];
    GGSub* unk10;
};

class VIface {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(s32, s32);
};

extern GG* g_GameGlobal;
extern u8 lbl_10_rodata_574[];
extern f32 lbl_10_rodata_578;

extern "C" {
void fn_10_145C0(void* self, s32 idx);
void fn_10_14858(void* self, s32 v);
void fn_10_14DB0(void* self, s32 v);
void fn_10_14E5C(void* self, s32 v);
void fn_10_14EE8(void* self, s32 v);
void fn_10_14F38(void* self, s32 a, s32 b);
s32 fn_10_14618(void* self);
s32 fn_10_15168(void* self);
void fn_10_16158(void* self);
void fn_10_16930(void* self, s32 a, s32 b, s32 c);
void fn_10_169F0(void* self, s32 a);
void fn_10_16AD4(void* self, s32 a);
void fn_10_16B5C(void* self, s32 a, s32 b, s32 c);
void fn_10_16C1C(void* self, s32 a, u8 b);
void fn_10_16CA8(void* self, s32 a, s32 b);
void fn_10_16CDC(void* self, s32 a, u8 b);
void fn_10_16D74(void* self, s32 a, s32 b, s32 c);
void fn_10_16DD8(void* self, s32 a, s32 b, s32 c);
void fn_10_16E90(void* self, s32 a);
void fn_10_16F24(void* self, u32 idx);
void fn_10_18908(void* self, s32 a, s32 b, s32 c, s32 d);
void fn_10_19D74(s32 a);
void fn_10_19DD4(s32 a);
void fn_10_19E3C(s32 a);
void fn_10_1BC70(s32 a);
s32 isTeamBattle__19muSelCharPlayerAreaFv(void* self);
void setFrameVisible__8MuObjectFf(void* self, float f);
}

extern "C" void fn_10_11C50(muSelCharPlayerArea* arg0) {
    s32 temp_r30;
    s32 temp_r30_2;
    s32 temp_r30_3;
    s32 temp_r30_4;
    s32 temp_r30_5;
    s32 temp_r29;
    s32 temp_r29_2;
    u8* var_r29;
    s32 var_r28;
    void* temp_r3;

    var_r29 = lbl_10_rodata_574;
    var_r28 = 0;
    temp_r30 = arg0->unk404;
    do {
        fn_10_16F24(arg0, *var_r29);
        var_r28 += 1;
        var_r29 += 1;
    } while (var_r28 < 4);
    setFrameVisible__8MuObjectFf(arg0->unkD4, lbl_10_rodata_578);
    fn_10_15168(arg0);
    fn_10_14DB0(arg0, arg0->unk1D0);
    if ((fn_10_15168(arg0) == 1) || (fn_10_15168(arg0) == 2)) {
        fn_10_14E5C(arg0, 1);
    }
    temp_r3 = arg0->unkAC;
    ((VIface*)temp_r3)->v11(*(s32*)((u8*)temp_r3 + 0xE4), temp_r30);
    fn_10_145C0(arg0, 8);
    temp_r30_2 = arg0->unk1B4;
    fn_10_16930(arg0, temp_r30_2, isTeamBattle__19muSelCharPlayerAreaFv(arg0), arg0->unk1C0);
    fn_10_169F0(arg0, arg0->unk1B4 != 0);
    fn_10_16AD4(arg0, arg0->unk1B4);
    fn_10_14858(arg0, arg0->unk1B8);
    temp_r30_3 = arg0->unk1B4;
    fn_10_16B5C(arg0, temp_r30_3, isTeamBattle__19muSelCharPlayerAreaFv(arg0), arg0->unk1C0);
    fn_10_16C1C(arg0, arg0->unk1B4, g_GameGlobal->unk10->unk4);
    fn_10_16CA8(arg0, isTeamBattle__19muSelCharPlayerAreaFv(arg0), arg0->unk1C0);
    fn_10_16CDC(arg0, arg0->unk1B4, g_GameGlobal->unk10->unk4);
    temp_r30_4 = arg0->unk1B4;
    fn_10_16D74(arg0, temp_r30_4, isTeamBattle__19muSelCharPlayerAreaFv(arg0), arg0->unk1C0);
    temp_r30_5 = arg0->unk1B4;
    temp_r29 = arg0->unk1C8;
    fn_10_18908(arg0, temp_r29, temp_r30_5, isTeamBattle__19muSelCharPlayerAreaFv(arg0), arg0->unk1C0);
    fn_10_16E90(arg0, arg0->unk1B4);
    fn_10_14EE8(arg0, arg0->unk1D4);
    fn_10_16158(arg0);
    temp_r29_2 = arg0->unk1B4;
    fn_10_16DD8(arg0, temp_r29_2, fn_10_14618(arg0), arg0->unk1DC);
    fn_10_14F38(arg0, arg0->unk1D8, arg0->unk1B4);
    fn_10_1BC70(arg0->unk1AC);
    fn_10_19D74(arg0->unk1A8);
    fn_10_19DD4(arg0->unk1A8);
    fn_10_19E3C(arg0->unk1A8);
}
