#pragma force_active on
extern "C" unsigned short fn_8015C418(unsigned char** arg0) {
    unsigned char* p = *static_cast<unsigned char* const*>(arg0);
    unsigned short c = p[0];
    if (!(c & 0x80)) {
        *arg0 += 1;
    } else if ((c & 0xE0) == 0xC0) {
        unsigned char c2 = p[1];
        c = ((c & 0x1F) << 6) | (c2 & 0x3F);
        *arg0 += 2;
    } else {
        unsigned char c2 = p[1];
        unsigned char c3 = p[2];
        c = ((c & 0x1F) << 12) | ((c2 & 0x3F) << 6) | (c3 & 0x3F);
        *arg0 += 3;
    }
    return c;
}
