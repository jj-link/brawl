#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} lbl_80534638_t;

extern lbl_80534638_t lbl_80534638;

void fn_8035DFCC(int arg0, int arg1, int arg2, int arg3) {
    lbl_80534638.unk0 = arg0;
    lbl_80534638.unk4 = arg1;
    lbl_80534638.unk8 = arg2;
    lbl_80534638.unkC = arg3;
}
