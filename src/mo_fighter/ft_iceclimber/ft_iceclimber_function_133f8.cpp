#pragma force_active on
extern "C" int fn_105_133F8(float f) {
    int r = 1;
    unsigned int e = (*(unsigned int*)&f >> 23) & 0xff;
    if (e == 0xff) {
        r = 0;
    }
    return r;
}
