#pragma force_active on
typedef unsigned char u8;

extern "C" u8 fn_8015E05C(void* self) {
    void* p = *(void**)((u8*)self + 0x14);
    return *(u8*)((u8*)p + 0x16);
}
