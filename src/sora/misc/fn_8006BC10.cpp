#pragma force_active on
struct Message {
    static int utf8to16(wchar_t* out, const char* in);
};

int Message::utf8to16(wchar_t* out, const char* in) {
    int count = 0;
    unsigned char c;
    while ((c = *(unsigned char*)in) != 0) {
        if (c <= 0x7F) {
            *out = (unsigned char)*in++;
            out += 1;
        } else if ((c >> 5) == 6) {
            unsigned char c2 = *(unsigned char*)(in + 2);
            unsigned char c1 = *(unsigned char*)(in + 1);
            in += 2;
            *out = (unsigned short)(((c & 0x1F) << 6) | (c1 & 0x3F));
            out += 1;
        } else if ((c >> 4) == 0xE) {
            unsigned char c2 = *(unsigned char*)(in + 2);
            unsigned char c1 = *(unsigned char*)(in + 1);
            in += 3;
            *out = (unsigned short)(((c & 0xF) << 12) | ((c1 & 0x3F) << 6) | (c2 & 0x3F));
            out += 1;
        }
        count++;
    }
    *out = 0;
    return count;
}
