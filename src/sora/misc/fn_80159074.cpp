#pragma force_active on
extern "C" unsigned int fn_80159074(unsigned int *arg0, unsigned int arg1) {
    unsigned int ptr = *arg0;
    unsigned int off = (arg1 >> 3) & 0x1FFFFFFC;
    unsigned int v = *(unsigned int *)((char *)ptr + off) & (1u << (arg1 & 0x1F));
    return v != 0;
}
