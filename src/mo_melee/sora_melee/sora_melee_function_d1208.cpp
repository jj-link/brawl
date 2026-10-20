#pragma force_active on
extern "C" int fn_27_D1208(unsigned int *p) {
    unsigned int x = p[2];
    return (int)((x << 16) & 0xFF800000) >> 24;
}
