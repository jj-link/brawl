#pragma force_active on
extern "C" int fn_27_CE09C(void* p) {
    unsigned int x = ((unsigned int*)p)[2];
    return (int)(((x << 16) | (x >> 16)) & 0xFF800000u) >> 24;
}
