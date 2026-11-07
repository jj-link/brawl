#include <gf/gf_task.h>
#include <ms/ms_message.h>
#include <string.h>
#include <stdio.h>
#pragma force_active on

struct Entry6A0 {
    unsigned char key;
    int value;
};

extern "C" gfTask* fn_800BEEB8(int, void*, int, int, int, int, int, int, int, int, int, int);
extern "C" void fn_800BF928(gfTask*, const char*);
extern "C" const Entry6A0 lbl_6_rodata_6A0[5];
extern "C" char lbl_6_data_6E4[];

static inline int lookupId(int kind) {
    int id = 0x59;
    for (int i = 0; i < 5; i++) {
        if (kind == lbl_6_rodata_6A0[i].key) {
            id = lbl_6_rodata_6A0[i].value;
            break;
        }
    }
    return id;
}

extern "C" void fn_6_A1B4(void* p) {
    char* self = (char*)p;
    gfTask* task = *(gfTask**)(self + 0x750);
    if (task) {
        task->exit();
        *(gfTask**)(self + 0x750) = 0;
    }
    *(gfTask**)(self + 0x750) = fn_800BEEB8(0, *(void**)(self + 0x78), lookupId(*(int*)(self + 0x77c)), *(int*)(self + 0x754), *(int*)(self + 0x70), *(int*)(self + 0x758) + 3, 0, 0x2a, 0x2b, 0, 0, 0xf0);
    if (*(int*)(self + 0x780)) {
        unsigned long size;
        char* data;
        char buffer[128];
        Message::getPrintIndexData(*(void**)(self + 0x78), 0x13, &data, &size);
        memcpy(buffer, data, size);
        size += sprintf(buffer + size, lbl_6_data_6E4, *(int*)(self + 0x780));
        fn_800BF928(*(gfTask**)(self + 0x750), buffer);
    }
}
