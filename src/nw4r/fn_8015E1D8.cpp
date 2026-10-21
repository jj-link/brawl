#pragma force_active on
extern "C" void fn_8015E1D8(void* arg0, unsigned char arg1) {
    void* p = *(void**)((char*)arg0 + 0x14);
    *(unsigned char*)((char*)p + 1) = arg1;
}
