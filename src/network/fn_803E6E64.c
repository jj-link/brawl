#pragma force_active on
extern unsigned int fn_803D6480();

unsigned int fn_803E6E64(void) {
    unsigned int x = fn_803D6480();
    return (-x | x) >> 31;
}
