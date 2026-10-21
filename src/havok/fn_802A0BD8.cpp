#pragma force_active on
extern "C" {
unsigned int fn_802A0BD8(unsigned char* p) {
    int x = (signed char)*p;
    return ((unsigned int)(-x | x)) >> 31;
}
}
