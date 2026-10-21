#pragma force_active on
extern "C" unsigned char fn_8015E404(void* arg0) {
    void* p = *(void**)((char*)arg0 + 0x14);
    return *(unsigned char*)((char*)p + 0x7);
}
