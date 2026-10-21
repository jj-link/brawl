#pragma force_active on
typedef unsigned char u8;

extern "C" u8 fn_8015E050(void* arg0) {
    u8* p = *(u8**)((u8*)arg0 + 0x14);
    return *(p + 0x14);
}
