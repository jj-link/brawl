#pragma force_active on
extern const float lbl_805A37D8;

unsigned short fn_801F172C(unsigned int arg0, float farg0) {
    unsigned int divisor;
    unsigned int result;

    divisor = (unsigned int)(lbl_805A37D8 / farg0) & 0x1FF;
    result = (((arg0 - 1) << 8) / divisor) + 1;

    if (divisor > 0x80 && divisor < 0x100) {
        while (!(divisor & 1)) {
            divisor >>= 1;
        }
        if (arg0 % divisor == 0) {
            result += 1;
        }
    }

    if (result > 0x400) {
        result = 0x400;
    }

    return (unsigned short)result;
}
