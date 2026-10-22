#pragma force_active on
extern void* fn_80259EE0(void* a, void* b, void* c);

int fn_80256C34(void* a, void* b, void* c) {
    void* ptr = fn_80259EE0(a, b, c);
    if (ptr == 0) {
        return 0;
    }
    *(unsigned char*)((char*)ptr + 0x474) = 0;
    *(void**)((char*)ptr + 0x410) = b;
    *(void**)((char*)ptr + 0x414) = c;
    return 1;
}
