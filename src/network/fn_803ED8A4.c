#pragma force_active on
extern char lbl_8041F398[];

typedef struct fn_803ED8A4_obj {
    char *unk0;
    int unk4;
} fn_803ED8A4_obj;

int fn_803ED8A4(fn_803ED8A4_obj *arg0, int arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = lbl_8041F398;
    return 0;
}
