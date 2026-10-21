#pragma force_active on
typedef struct Obj {
    int unk00[4];
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
} Obj;

int fn_802812A8(Obj* arg0, int arg1) {
    arg0->unk20 = arg1;
    arg0->unk1C = arg0->unk10;
    return arg0->unk18 < arg1;
}
