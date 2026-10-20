#pragma force_active on
extern "C" int fn_40_30C08(void* p) {
    unsigned int x = *(unsigned int*)((char*)p + 8);
    return (int)(((x >> 16) & 0x3F) << 26) >> 27;
}
