#include <types.h>
#include <string.h>
#pragma force_active on

extern "C" void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
extern const char lbl_14_data_410[];

extern "C" void fn_14_3C50(void* self) {
    char* base = (char*)self;
    int i;
    unsigned offset = 0;
    unsigned len = strlen(base + 0x2500);
    i = 0;

    for (; i < 3 && offset < len; i++) {
        char buf[4];
        int j = 0;
        while (j < 4 && offset < len) {
            buf[j] = (base + offset)[0x2500];
            j++;
            offset++;
        }
        buf[j] = 0;
        printf__5MuMsgFUlPCce(*(void**)(base + 0x24CC), i + 0x18, buf);
    }

    for (; i < 3; i++) {
        printf__5MuMsgFUlPCce(*(void**)(base + 0x24CC), i + 0x18, lbl_14_data_410);
    }
}