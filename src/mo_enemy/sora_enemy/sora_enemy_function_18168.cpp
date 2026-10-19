#pragma force_active on
typedef int s32;
typedef float f32;
extern float lbl_41_rodata_C3C;
extern "C" s32 fn_41_15FD4(s32 a, s32 b);
extern "C" f32 fn_41_1F340(void* self);

extern "C" f32 fn_41_18168(s32 a, s32 b) {
    if (b == -1) {
        return lbl_41_rodata_C3C;
    }
    return fn_41_1F340((void*)fn_41_15FD4(a, b));
}
