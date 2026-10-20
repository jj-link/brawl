#pragma force_active on
extern "C" int fn_79_5944(void* p) {
    unsigned int x = ((unsigned int*)p)[2];
    return (int)((x << 12) & 0xFE000000u) >> 26;
}
