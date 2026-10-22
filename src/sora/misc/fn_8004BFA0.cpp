#pragma force_active on
extern "C" {
void* memcpy(void*, const void*, unsigned long);
void* memset(void*, int, unsigned long);

int fn_8004BFA0(int self, char* dst, unsigned char* src) {
    if (src == 0) {
        return 0;
    }
    memset(dst, 0, 0x10);
    if ((*src & 0xF) == 0) {
        return 0;
    }
    unsigned char* p = src + 1;
    unsigned int i = 0;
    do {
        if (*src & (1 << (unsigned char)i)) {
            memcpy(dst + (((unsigned char)i) << 2 & 0x3FC), p, 4);
            p += 4;
        }
        i++;
    } while (i < 4);
    return 1;
}
}
