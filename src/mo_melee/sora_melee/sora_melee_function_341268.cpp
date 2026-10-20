#pragma force_active on
typedef unsigned int u32;

extern "C" {
void* fn_27_341268(char* self, u32 unused, u32 idx) {
    return *(void**)(self + ((idx - *(u32*)(self + 0x18)) << 2) + 0x30);
}
}
