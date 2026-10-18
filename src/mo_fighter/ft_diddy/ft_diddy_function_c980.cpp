#pragma force_active on
typedef float f32;

extern "C" {
extern const f32 lbl_115_rodata_C;
void* fn_115_8EF8(void* vector, f32 x, f32 y, f32 z);

void* fn_115_C980(void* vector) {
    f32 c = lbl_115_rodata_C;
    return fn_115_8EF8(vector, c, c, c);
}
}
