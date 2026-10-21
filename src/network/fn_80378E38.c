#pragma force_active on
typedef struct Obj {
    char pad[0xA4];
    int unkA4;
} Obj;

extern Obj *lbl_8059F9A8;

void fn_80378E38(Obj *arg0, int arg1) {
    Obj *var_r3;

    var_r3 = arg0;
    if (var_r3 == 0) {
        var_r3 = lbl_8059F9A8;
    }
    var_r3->unkA4 = arg1;
}
