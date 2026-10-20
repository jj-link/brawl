#pragma force_active on
extern "C" int fn_27_19CDB0(void *p) {
    unsigned int x = *(unsigned int *)((char *)p + 8);
    return ((int)((x << 6) & 0xF0000000u)) >> 29;
}
