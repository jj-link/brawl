#pragma force_active on
extern "C" void* fn_803010E4(void* p) {
    void* next;
    while ((next = *(void**)((char*)p + 0xc)) != 0) {
        p = next;
    }
    return p;
}
