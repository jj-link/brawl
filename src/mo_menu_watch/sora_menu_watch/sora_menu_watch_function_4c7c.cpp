#include <string.h>
#include <stdio.h>
#include <gf/gf_task.h>
#include <ms/ms_message.h>
#pragma force_active on

extern "C" gfTask* fn_800BEEB8(int, void*, int, int, int, int, int, int, int, int, int, int);
extern "C" int fn_800C9B00(int);
extern "C" int fn_800C9B14(int);
extern "C" void fn_800BF928(gfTask*, const char*);
extern "C" char lbl_15_data_2AC[];

extern "C" void fn_15_4C7C(char* self) {
    unsigned long size;
    char* data;
    int a, b;
    
    if (*(int*)(self + 0x4F0) == 0) {
        a = 4;
        b = 1;
        data = (char*)*(void**)(*(char**)(self + 0x24C) + 4);
    } else {
        data = (char*)(*(void**)(self + 0x544));
        a = fn_800C9B00(*(int*)(self + 0x4F0));
        b = fn_800C9B14(*(int*)(self + 0x4F0));
    }
    
    *(gfTask**)(self + 0x540) = fn_800BEEB8(0, (void*)data, a, *(int*)(self + 0x53C), *(int*)(self + 0x1A0), 0x1a, 0x1e, 0x2a, 0x2b, 0, 0, 0xf0);
    
    if (b != 0) {
        char buf[0x80];
        Message::getPrintIndexData(*(void**)(self + 0x544), 0x13, &data, &size);
        memcpy(buf, data, size);
        size += sprintf(buf + size, lbl_15_data_2AC, *(int*)(self + 0x4F4));
        fn_800BF928(*(gfTask**)(self + 0x540), buf);
    }
}