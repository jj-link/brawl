#pragma force_active on

unsigned int fn_8020983C(void) {
    unsigned int hi = *(unsigned short *)0xCC005004;
    unsigned int lo = *(unsigned short *)0xCC005006;
    return (hi << 16) | lo;
}
