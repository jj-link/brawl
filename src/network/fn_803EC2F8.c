#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern void OSReport(const char *fmt, ...);
extern void fn_801E02D4(s32 arg0, u32 arg1);
extern void fn_801E032C(s32 arg0);
extern char lbl_804930F4[];

typedef struct {
    u32 unk0;
    u32 unk4;
    s32 unk8;
} FnObj;

s32 fn_803EC2F8(FnObj *arg0) {
    s32 var_r31;
    s32 temp_r5;

    if (arg0 == 0 ||
        (temp_r5 = arg0->unk8, temp_r5 == 0) ||
        arg0->unk0 > arg0->unk4) {
        OSReport(lbl_804930F4);
        return 0;
    }

    fn_801E02D4(temp_r5, arg0->unk4);
    var_r31 = arg0->unk4 - arg0->unk0;

    while (var_r31 != 0) {
        fn_801E032C(arg0->unk8);
        var_r31--;
    }

    return arg0->unk8;
}
