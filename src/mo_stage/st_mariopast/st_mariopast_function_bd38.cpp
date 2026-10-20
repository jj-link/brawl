#pragma force_active on
extern "C" unsigned int fn_48_BD38(const void *this_) {
    unsigned int val = *(const unsigned int *)((const unsigned char *)this_ + 8);
    return (val >> 13) & 1;
}