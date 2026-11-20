#pragma force_active on
extern "C" unsigned int fn_8015C3A4(void *arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned char *b = (unsigned char *)arg0;
    if (*(unsigned int *)(b + 0x0) != arg1) {
        return 0;
    }
    if (*(unsigned short *)(b + 0x4) != 0xFEFF) {
        return 0;
    }
    if (*(unsigned short *)(b + 0x6) != arg2) {
        return 0;
    }
    if (*(unsigned int *)(b + 0x8) < ((arg3 * 8) & 0x7FFF8) + 0x10) {
        return 0;
    }
    return arg3 <= *(unsigned short *)(b + 0xE);
}