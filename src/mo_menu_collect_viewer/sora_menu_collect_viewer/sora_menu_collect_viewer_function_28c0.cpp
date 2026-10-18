#pragma force_active on
extern "C" {
void* fn_800C3538(void*, void*);
}

extern "C" void* fn_6_28C0(void* unused, void* b) {
    char* p = (char*)*(void**)((char*)b + 0x1ac);
    unsigned int idx = *(unsigned int*)(p + 0x1a0);
    char* q = p + (idx << 4);
    void* r = *(void**)(q + 0x1ac);
    return fn_800C3538(unused, r);
}
