#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void fn_104_AAC8(u8* self, u32 index) {
    u32* arr = *(u32**)(self + 0xc);
    arr[index]++;
}
