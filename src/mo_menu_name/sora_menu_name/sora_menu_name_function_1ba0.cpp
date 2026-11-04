#include <types.h>
#include <string.h>
#include <ms/ms_message.h>
#pragma force_active on

extern "C" int fn_8006CEEC(const char*, int);
extern "C" void fn_8006BAB0(char*, const char*, int, int);

extern "C" int fn_16_1BA0(const char* text, const char* prefix, int digits, int minimum, int maximum) {
    int prefixLength = fn_8006CEEC(prefix, 0x7FFF);
    if (prefixLength + digits == fn_8006CEEC(text, 0x7FFF) &&
        strncmp(prefix, text, strlen(prefix)) == 0) {
        int value = 0;
        int i = 0;
        char character[4];
        wchar_t wide[2];
        for (; i < digits; ++i) {
            character[0] = 0;
            fn_8006BAB0(character, text, prefixLength + i, 1);
            Message::utf8to16(wide, character);
            if (wide[0] < 0xFF10 || wide[0] > 0xFF19)
                break;
            value *= 10;
            value += wide[0] - 0xFF10;
        }
        if (i >= digits && value >= minimum && value <= maximum)
            return 0;
    }
    return 1;
}
