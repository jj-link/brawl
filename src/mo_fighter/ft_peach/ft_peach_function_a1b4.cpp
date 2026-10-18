#pragma force_active on
typedef float f32;
typedef int s32;

extern "C" void fn_103_A1B4(char* self, s32 index, f32 scale)
{
    f32* arr = *(f32**)(self + 0x14);
    arr[index] *= scale;
}
