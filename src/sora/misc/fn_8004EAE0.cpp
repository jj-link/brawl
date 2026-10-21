#pragma force_active on
extern "C" void fn_8004EAE0(void** a, unsigned char b) {
    void* p = *a;
    *(unsigned char*)((char*)p + 0x10) = b;
}
