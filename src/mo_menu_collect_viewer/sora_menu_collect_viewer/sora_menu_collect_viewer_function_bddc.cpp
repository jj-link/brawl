#include <gf/gf_task.h>
#include <ms/ms_message.h>
#include <string.h>
#include <stdio.h>
#pragma force_active on

extern "C" gfTask* fn_800BEEB8(int, void*, int, int, int, int, int, int, int, int, int, int);
extern "C" int fn_800C9B14(int);
extern "C" void fn_800BF928(gfTask*, const char*);
extern "C" char lbl_6_data_8E8[];

extern "C" void fn_6_BDDC(void* p) {
    char* self = (char*)p;
    gfTask* task = *(gfTask**)(self + 0x140);
    if (task) {
        task->exit();
        *(gfTask**)(self + 0x140) = 0;
    }
    void* msg;
    if (*(int*)(self + 0x158) == 1)
        msg = *(void**)(self + 0x7c);
    else
        msg = *(void**)(*(char**)(self + 0x78) + 4);
    *(gfTask**)(self + 0x140) = fn_800BEEB8(0, msg, *(int*)(self + 0x154), *(int*)(self + 0x144), *(int*)(self + 0x74), *(int*)(self + 0x148) + 7, 0, 0x2a, 0x2b, 0, 0, 0xf0);
    int mode = *(int*)(self + 0x158);
    if ((unsigned)(mode - 1) <= 1) {
        if (mode == 1 ? fn_800C9B14(*(int*)(self + 0x15c)) : 1) {
            unsigned long size;
            char* data;
            char buffer[128];
            Message::getPrintIndexData(*(void**)(self + 0x7c), 0x13, &data, &size);
            memcpy(buffer, data, size);
            size += sprintf(buffer + size, lbl_6_data_8E8, *(int*)(self + 0x160));
            fn_800BF928(*(gfTask**)(self + 0x140), buffer);
        }
    }
}