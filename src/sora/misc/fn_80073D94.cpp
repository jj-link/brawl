#pragma force_active on
extern "C" void fn_8007AA48(void*);

extern "C" void fn_80073D94(void* self, int param) {
    if (param < 0)
        return;
    void** ptr = *(void***)((char*)self + 0x2d0);
    if (ptr)
        fn_8007AA48(ptr);
}
