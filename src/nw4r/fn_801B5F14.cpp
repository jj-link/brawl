#pragma force_active on
extern "C" void fn_801F4448(void* a1, void* a2, int a3);

extern "C" void fn_801B5F14(void** ptr, void* a2, short a3, int a4) {
    void* p = *ptr;
    if (p) {
        *(short*)((char*)p + 0x1a) = a3;
        fn_801F4448((char*)p + 0x1c, a2, a4);
    }
}
