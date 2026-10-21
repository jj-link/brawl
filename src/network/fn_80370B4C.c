#pragma force_active on
typedef struct fn_80370B4C_data {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
} fn_80370B4C_data;

int fn_80370B4C(fn_80370B4C_data *arg0) {
    int var_r4;

    var_r4 = 0;
    if (arg0 != 0 && arg0->unkC == 0 && arg0->unk8 == 0 && arg0->unk18 == 0 && arg0->unk10 == 0) {
        var_r4 = 1;
    }
    return var_r4 != 0;
}
