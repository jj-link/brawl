#pragma force_active on
struct Rec {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};

extern "C" void fn_802EA824(Rec* dst, Rec* src) {
    int r5 = src->m8;
    if (dst->m8 > r5) {
        r5 = dst->m8;
    }
    dst->m8 = r5;
    int r0 = src->mC;
    if (r5 > r0) {
        r0 = r5;
    }
    dst->m8 = r0;
    dst->mC += src->mC;
    dst->m10 += src->m10;
    dst->m14 += src->m14;
}
