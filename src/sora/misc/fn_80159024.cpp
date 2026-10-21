#pragma force_active on
extern "C" {
void fn_80159024(unsigned long* arg0, unsigned long arg1, unsigned long arg2) {
    unsigned long idx = arg1 >> 5;
    unsigned long bit = arg1 & 0x1F;
    unsigned long* p;
    if (arg2 == 1) {
        p = (unsigned long*)*arg0;
        p[idx] |= 1UL << bit;
    } else {
        p = (unsigned long*)*arg0;
        p[idx] &= ~(1UL << bit);
    }
}
}
