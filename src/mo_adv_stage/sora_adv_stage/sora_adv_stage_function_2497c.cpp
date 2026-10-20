#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_40_2497C(void* p) {
    int x = *(int*)((char*)p + 8);
    return (int)((((u32)x >> 25) & 7u) << 29) >> 30;
}
}
