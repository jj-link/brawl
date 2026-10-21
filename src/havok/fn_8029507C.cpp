#pragma force_active on
typedef float f32;

extern "C" {
void fn_8029507C(void* arg0, f32 farg0, f32 farg1) {
    *(f32*)((char*)arg0 + 0x1C) = farg0 * farg1;
}
}
