#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_104_AB30(u8* self, u32 value, u32 index) {
    u32* arr = *(u32**)(self + 0xc);
    arr[index] += value;
}
