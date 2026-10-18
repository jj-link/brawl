#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void fn_109_9200(u8* self, u32 index) {
    u32* arr = *(u32**)(self + 0x1c);
    arr[index] = 0;
}
