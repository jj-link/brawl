#pragma force_active on
typedef float f32;
typedef double f64;
typedef signed int s32;
typedef unsigned char u8;

typedef struct FnStruct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s32 unk14;
    s32 unk18;
    u8 unk1C;
} FnStruct;

void fn_80278BFC(FnStruct *arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2) {
    f32 var_f0;

    arg0->unk18 = arg1;
    arg0->unk4 = farg0;
    arg0->unk8 = farg1;
    arg0->unk10 = farg2;
    arg0->unk14 = 0;
    arg0->unk1C = 0;
    if (arg1 == 1) {
        var_f0 = (f64) farg0;
    } else {
        var_f0 = (f64) farg1;
    }
    arg0->unkC = var_f0;
}
