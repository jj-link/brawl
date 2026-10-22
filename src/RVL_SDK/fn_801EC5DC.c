#pragma force_active on
typedef signed char s8;
typedef int s32;
typedef float f32;
typedef double f64;

f64 sin(f64);
f64 cos(f64);
void fn_801EC658(s32, s8, f32, f32);

void fn_801EC5DC(s32 arg0, s8 arg1, f32 farg0) {
    f32 temp_f31;

    temp_f31 = (f32) sin(farg0);
    fn_801EC658(arg0, arg1, temp_f31, (f32) cos(farg0));
}
