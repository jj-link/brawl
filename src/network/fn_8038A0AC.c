#pragma force_active on
typedef struct {
    int unk0;
    int *unk4;
} Fn8038A0AC_Arg;

extern int *fn_8035A598(int *);

int fn_8038A0AC(Fn8038A0AC_Arg *arg0) {
    return *fn_8035A598(arg0->unk4);
}
