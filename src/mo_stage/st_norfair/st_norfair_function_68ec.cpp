#pragma force_active on
extern "C" void fn_54_68EC(void *param) {
    unsigned int *p = (unsigned int *)((char *)param + 8);
    *p &= 0xFFF7FFFF;
}
