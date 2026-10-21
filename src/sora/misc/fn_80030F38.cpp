#pragma force_active on
extern "C" int fn_80032F38(unsigned int p0, unsigned int p1, unsigned int p2);

extern "C" int fn_80030F38(unsigned int p0, unsigned int p1) {
    if (p1 >= 0x33) {
        return 0;
    }
    return fn_80032F38(p0, 1, p1);
}
