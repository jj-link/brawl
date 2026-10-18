#pragma force_active on
struct Word4 {
    unsigned int w[4];
};

extern "C" void fn_111_DC30(Word4* out, const Word4* a, const Word4* b) {
    const float* af = (const float*)a;
    const float* bf = (const float*)b;
    Word4 local = *a;
    float* lf = (float*)&local;
    if (lf[2] < bf[2]) {
        lf[2] = bf[2];
    }
    if (lf[3] > bf[3]) {
        lf[3] = bf[3];
    }
    if (lf[0] > bf[0]) {
        lf[0] = bf[0];
    }
    if (lf[1] < bf[1]) {
        lf[1] = bf[1];
    }
    *out = local;
}
