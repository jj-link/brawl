#include <stdio.h>
#pragma force_active on

extern "C" {
extern char lbl_2_data_1398[];
extern char* lbl_2_data_878[];

int fn_2_10EC0(void* self, char* out, unsigned int value, int width) {
    char buffer[128];
    const char* formats = lbl_2_data_1398;
    int digits;
    unsigned int place;
    int result;
    unsigned int i;
    unsigned int count;
    result = 0;
    place = 1;

    sprintf(out, formats + 0x408);
    digits = 0;

loop:
    if (value >= place) {
        unsigned int next = place * 10;
        result = sprintf(buffer, formats + 0x40c,
                         lbl_2_data_878[(value % next) / place], out);
        sprintf(out, formats + 0x414, buffer);
        place = next;
        digits++;
        goto loop;
    }

    if (digits < width) {
        count = width - digits;
        for (i = 0; i < count; i++) {
            result = sprintf(buffer, formats + 0x40c, lbl_2_data_878[11], out);
            sprintf(out, formats + 0x414, buffer);
        }
    }

    return result;
}
}
