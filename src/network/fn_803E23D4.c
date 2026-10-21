#pragma force_active on
typedef struct Obj Obj;
struct Obj {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int pad20;
    int pad24;
    int pad28;
    int pad2C;
    Obj* unk30;
};

int fn_803E23D4(Obj* arg0, int arg1) {
    Obj* temp_r5;

    temp_r5 = arg0->unk30;
    arg0->unk8 = arg1;
    arg0->unk0 = 1;
    if (temp_r5 != 0) {
        temp_r5->unk8 = 0;
    }
    arg0->unk18 = 0;
    arg0->unk14 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk1C = 0;
    return 0;
}
