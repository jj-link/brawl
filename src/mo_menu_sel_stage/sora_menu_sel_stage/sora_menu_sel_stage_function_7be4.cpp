#include <cstring>
#pragma force_active on
extern "C" int fn_8003A210(int);
extern "C" int fn_11_7BE4(void* self, int type, unsigned int count, const char* strings) {
    char* base = (char*)self + type * 16;
    int offset;
    char* entry;
    int accepted;
    unsigned int i;
    int found;
    accepted = 0;
    found = 0;
    i = 0;
    offset = 0;
    while (i < count && accepted < 1000) {
        int len = strlen(strings);
        if (len <= 22) {
            entry = *(char**)(base + 0x54) + offset;
            strcpy(entry, strings);
            entry[0x17] &= ~0x80;
            if (type == 0 && found == 0 && strcmp(strings, (const char*)fn_8003A210(3)) == 0) {
                found = 1;
                entry[0x17] |= 0x80;
            }
            offset += 24;
            accepted++;
        }
        i++;
        strings += len + 1;
    }
    return accepted;
}