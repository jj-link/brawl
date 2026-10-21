#pragma force_active on
typedef float f32;

void fn_801F22CC(void* arg0, f32* arg1, f32* arg2, f32* arg3) {
    f32 a = *(f32*)((char*)arg0 + 0x34);
    f32 b = *(f32*)((char*)arg0 + 0x38);
    f32 c = *(f32*)((char*)arg0 + 0x3C);
    *arg1 = -a;
    *arg2 = -b;
    *arg3 = -c;
}
