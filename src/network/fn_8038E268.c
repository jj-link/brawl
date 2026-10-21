#pragma force_active on
extern int fn_80367A60(int, char *, int);
extern char lbl_80491088[];

typedef struct {
    int unk0[3];
    int unkC;
    int unk10[3];
    int unk1C;
} Obj;

int fn_8038E268(Obj *arg0) {
    int var_r3;
    int ret = fn_80367A60(arg0->unk1C, lbl_80491088, arg0->unkC);

    var_r3 = 0;
    if (ret == 0) {
        var_r3 = 5;
    }
    return var_r3;
}
