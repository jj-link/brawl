#pragma force_active on
extern "C" int fn_8006CEEC(unsigned char *p, int length) {
    unsigned char c;
    int count;
    unsigned char *end = p + length;
    count = 0;
    while (p < end) {
        c = *p;
        if (!(c & 0x80)) {
            if ((signed char)c == 0) break;
            count++;
            p++;
        } else if ((c & 0xE0) == 0xC0) {
            count++;
            p += 2;
        } else if ((c & 0xF0) == 0xE0) {
            count++;
            p += 3;
        }
    }
    return count;
}