#pragma force_active on
typedef unsigned char u8;

extern "C" u8 fn_800DCE48(void* arg0) {
    void* p = *(void**)((u8*)arg0 + 0x78);
    return *(u8*)((u8*)p + 0x2f4);
}
