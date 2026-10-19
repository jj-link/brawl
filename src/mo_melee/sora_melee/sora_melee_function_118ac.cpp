#pragma force_active on
typedef unsigned long u32;

extern "C" {
void* fn_27_118AC(char* self) {
    void* a = *(void**)(self + 0x28);
    if (a != 0) {
        return *(void**)((char*)a + 0x4);
    }
    void* b = *(void**)(self + 0x2C);
    if (b != 0) {
        return *(void**)((char*)(*(void**)b) + 0x4);
    }
    return 0;
}
}
