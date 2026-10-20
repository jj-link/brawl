#pragma force_active on
extern "C" int fn_27_CA4CC(void* p) {
    unsigned int x = *(unsigned int*)((char*)p + 8);
    return ((int)((x << 5) & 0xFC000000u)) >> 27;
}
