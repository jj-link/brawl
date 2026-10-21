#pragma force_active on
extern "C" int fn_40_3EC48(int x, unsigned char *a, unsigned char *b, unsigned char *c)
{
    if ((unsigned int)(x - 0x1b) <= 3) {
        if (*a != 0) {
            return 0x28;
        }
        *a = 1;
        return 0x1b;
    }
    if ((unsigned int)(x - 0xe) <= 1) {
        if (*b != 0) {
            return 0x28;
        }
        *b = 1;
        return 0xe;
    }
    if ((unsigned int)(x - 0x3) <= 1) {
        if (*c != 0) {
            return 0x28;
        }
        *c = 1;
        return 0x3;
    }
    return x;
}
