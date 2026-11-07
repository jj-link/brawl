#pragma force_active on
extern "C" int fn_8018C3FC(unsigned int* p, unsigned int n) {
    if (n != 0xff) return 1;
    if (p && (p[0] != 0xffffffffU || p[1] != 0xffffffffU || p[2] != 0xffffffffU || p[3] != 0xffffffffU)) return 1;
    return 0;
}