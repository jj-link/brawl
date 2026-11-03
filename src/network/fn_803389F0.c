#pragma force_active on

typedef void (*ObjFn)(int, int, void *);

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    ObjFn unk14;
    void *unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
} Obj;

extern int fn_80335638(int, const char *, ...);
extern void fn_8033524C(int, int);
extern Obj *lbl_805A0F80;
extern char lbl_80489AD8[];

int fn_803389F0(int arg0) {
    int var_r31;
    int var_r3;
    ObjFn fn;
    Obj *obj;

    if (arg0 == 0) {
        return 0;
    }
    var_r3 = fn_80335638(2, lbl_80489AD8, arg0);
    switch (arg0) {
    case 1:
        var_r31 = 9;
        var_r3 = -1;
        break;
    case 2:
        var_r31 = 9;
        var_r3 = -2;
        break;
    case 3:
        var_r31 = 6;
        var_r3 = -10;
        break;
    case 4:
        var_r31 = 6;
        var_r3 = -20;
        break;
    }
    if (lbl_805A0F80 != 0 && var_r31 != 0) {
        fn_8033524C(var_r31, var_r3 - 0xEE48);
        obj = lbl_805A0F80;
        fn = obj->unk14;
        if (fn != 0) {
            fn(var_r31, 0, obj->unk18);
        }
        if (lbl_805A0F80 != 0) {
            lbl_805A0F80->unk4 = 0;
            lbl_805A0F80->unk30 = 0;
        }
    }
    return arg0;
}
