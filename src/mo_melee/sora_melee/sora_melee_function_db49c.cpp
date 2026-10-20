#pragma force_active on
extern "C" int fn_27_DB49C(void* p) {
    unsigned int w = *(unsigned int*)((char*)p + 8);
    return (int)((w << 8) & 0xF8000000u) >> 28;
}
