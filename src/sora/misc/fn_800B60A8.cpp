#pragma force_active on
extern "C" void* fn_800B60A8(void* arg) {
    void* a = *(void**)((char*)arg + 0x14);
    void* b = *(void**)((char*)a + 0xc);
    if (b == 0) {
        return 0;
    }
    void* c = *(void**)((char*)b + 0x2c);
    int d = *(int*)((char*)c + 0x14);
    if (d != 0) {
        return (void*)((char*)c + d);
    }
    return 0;
}
