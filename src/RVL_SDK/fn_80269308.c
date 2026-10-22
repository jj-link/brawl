#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u8 *unk0;
    u8 *unk4;
    char pad8[4];
    u8 unkC;
    char padD[3];
    u32 unk10;
    s32 unk14;
};

void fn_80269308(struct Obj *arg0, u32 arg1) {
    u32 temp_r5_4;
    u32 temp_r6;
    u8 *temp_r4;
    u8 *temp_r5;
    u8 *temp_r5_2;
    u8 *temp_r5_3;
    u8 *temp_r6_2;
    u8 *temp_r7;

    temp_r5 = arg0->unk4;
    *temp_r5 = (u8)(arg1 >> 8);
    temp_r5_2 = temp_r5 + 1;
    temp_r7 = arg0->unk0;
    temp_r6 = temp_r5_2 - temp_r7;
    arg0->unk4 = temp_r5_2;
    if (temp_r6 >= arg0->unk10) {
        arg0->unkC = 1;
        arg0->unk14 = arg0->unk14 + temp_r6;
        arg0->unk4 = temp_r7;
    }
    temp_r5_3 = arg0->unk4;
    *temp_r5_3 = (u8)arg1;
    temp_r4 = temp_r5_3 + 1;
    temp_r6_2 = arg0->unk0;
    temp_r5_4 = temp_r4 - temp_r6_2;
    arg0->unk4 = temp_r4;
    if (temp_r5_4 >= arg0->unk10) {
        arg0->unkC = 1;
        arg0->unk14 = arg0->unk14 + temp_r5_4;
        arg0->unk4 = temp_r6_2;
    }
    *arg0->unk4 = 0;
}
