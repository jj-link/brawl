#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_122_F6F8(char* self, u32 index) {
    u32* work = *(u32**)(self + 0x1c);
    work[index] = 0;
}
