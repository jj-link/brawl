#pragma force_active on
extern "C" char* fn_80111BD4(void* a, void* b, int index) {
    char* ptr = *(char**)((char*)a + 0x10);
    unsigned short count = *(unsigned short*)((char*)b + 0x4A);
    return ptr + count * 16 + index * 16;
}
