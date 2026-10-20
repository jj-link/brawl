#pragma force_active on
typedef unsigned char u8;
typedef void* ptr_t;

extern "C" u8 fn_27_10C7F0(u8* self) {
    ptr_t p = *(ptr_t*)(self + 0x154);
    return *(u8*)((u8*)p + 0x3c);
}
