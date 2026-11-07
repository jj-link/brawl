#include <ms/ms_message.h>
#include <string.h>
#include <stdio.h>
#pragma force_active on
extern "C" {
void fn_80030B68(void*, int, int*, int*, int);
unsigned long fn_8006A470(char*);
void* fn_800BEEB8(int, void*, int, int, int, int, int, int, int, int, int, int);
void* fn_800BF048(int, char*, unsigned long, int, int, int, int, int, int, int, int, int);
extern char lbl_8059E198[3];
}
extern "C" void fn_800DB020(char* self) {
    char buffer[0x100];
    int a, b;
    unsigned long size;
    char* text;
    if (*(int*)(self + 0x68) == 0) {
        if (*(int*)(self + 0x5c) == 0) {
            *(void**)(self + 0x5c) = fn_800BEEB8(0, *(void**)(self + 0x4c), 0x2d, *(int*)(self + 0x40), *(int*)(self + 0x44), *(int*)(self + 0x58), 0, 0x2a, 0x2b, 0, 0, 0xf0);
        }
    } else {
        fn_80030B68(*(void**)(self + 0x60), 2, &a, &b, 1);
        int value = b;
        if (*(int*)(self + 0x5c) == 0) {
            unsigned long start = fn_8006A470(buffer);
            Message::getPrintIndexData(*(void**)(self + 0x4c), 0x2e, &text, &size);
            memcpy(buffer + start, text, size);
            unsigned long pos = start + size;
            pos += sprintf(buffer + pos, lbl_8059E198, value);
            Message::getPrintIndexData(*(void**)(self + 0x4c), 0x2f, &text, &size);
            memcpy(buffer + pos, text, size);
            pos += size;
            buffer[pos] = 0;
            *(void**)(self + 0x5c) = fn_800BF048(0, buffer, pos + 1, *(int*)(self + 0x40), *(int*)(self + 0x44), *(int*)(self + 0x58), 0, 0x2a, 0x2b, 0, 0, 0xf0);
        }
    }
}