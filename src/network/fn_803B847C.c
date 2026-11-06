#pragma force_active on
typedef struct S S;
struct S {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S* unk30;
    int unk34;
};

int fn_803B847C(S* arg0, S* arg1, int arg2, int arg3) {
    if (arg0 == 0) {
        return 0xA;
    }
    if (arg3 == 0) {
        return 0xA;
    }
    arg0->unk30 = arg1;
    arg0->unk34 = arg2;
    if (arg0 != 0 && arg3 != 0) {
        arg0->unk08 = arg3;
        arg0->unk00 = 1;
        if (arg1 != 0) {
            arg1->unk08 = 0;
        }
        arg0->unk18 = 0;
        arg0->unk14 = 0;
        arg0->unk0C = 0;
        arg0->unk10 = 0;
        arg0->unk1C = 0;
    }
    return 0;
}