#pragma force_active on
extern "C" int fn_27_CAB98(void* p) {
    unsigned int x = *(unsigned int*)((char*)p + 8);
    return (int)((x << 6) & 0xFE000000) >> 26;
}
