#include <types.h>
#pragma force_active on
extern "C" s32 strlen(const char*);
extern "C" s32 fn_8006BAB0(char* out, const char* src, s32 char_count, s32 byte_limit) {
    s32 limit = byte_limit;
    s32 count = char_count;
    const char* srcp = src;
    unsigned char c;
    out += strlen(out);
    while ((s8)(c = *srcp) != 0 && count > 0) {
        if ((c & 0x80) == 0) { --count; ++srcp; }
        else if ((c & 0xE0) == 0xC0) { --count; srcp += 2; }
        else if ((c & 0xF0) == 0xE0) { --count; srcp += 3; }
    }
    if ((s8)c == 0) return 0;
    while (limit > 0) {
        unsigned char ch = (unsigned char)*srcp;
        if ((ch & 0x80) == 0) {
            if ((s8)ch == 0) { *out = 0; return 0; }
            *out++ = (char)ch;
            --limit;
            ++srcp;
        } else if ((ch & 0xE0) == 0xC0) {
            char second = srcp[1];
            --limit;
            out[0] = (char)ch;
            srcp += 2;
            out[1] = second;
            out += 2;
        } else if ((ch & 0xF0) == 0xE0) {
            out[0] = (char)ch;
            out[1] = srcp[1];
            out[2] = srcp[2];
            out += 3;
            srcp += 3;
            --limit;
        }
    }
    *out = 0;
    return 1;
}