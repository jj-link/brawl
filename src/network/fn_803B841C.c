#pragma force_active on
typedef int s32;

typedef struct Fn841CObj Fn841CObj;
struct Fn841CObj {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    Fn841CObj* unk30;
};

s32 fn_803B841C(Fn841CObj* arg0, s32 arg1) {
    Fn841CObj* temp_r5;

    if (arg0 == 0) {
        return 0xA;
    }
    if (arg1 == 0) {
        return 0xA;
    }
    temp_r5 = arg0->unk30;
    arg0->unk08 = arg1;
    arg0->unk00 = 1;
    if (temp_r5 != 0) {
        temp_r5->unk08 = 0;
    }
    arg0->unk18 = 0;
    arg0->unk14 = 0;
    arg0->unk0C = 0;
    arg0->unk10 = 0;
    arg0->unk1C = 0;
    return 0;
}
