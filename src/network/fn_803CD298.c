#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} Struct_805A1250;

extern Struct_805A1250 *lbl_805A1250;
int fn_80204818(int arg0, int arg1);

int fn_803CD298(int arg0) {
    return fn_80204818(lbl_805A1250->unkC, arg0);
}
