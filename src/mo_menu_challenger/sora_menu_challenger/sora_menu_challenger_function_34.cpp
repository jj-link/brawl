#include <gf/gf_task.h>
#include <stdio.h>
#include <string.h>

#pragma force_active on

struct Section4First {
    char first;
};

extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    void*, const char*, gfTask::Category, int, int, bool);
extern char lbl_23_section4_0[0x1A4];
extern unsigned char lbl_23_section4_22C[0x64];
}

#pragma push
#pragma opt_propagation off
extern "C" char* fn_23_34(char* self) {
    Section4First* p = (Section4First*)&lbl_23_section4_0;
    char Section4First::*first = &Section4First::first;

    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
        self, &(p->*first),
        gfTask::Category_Menu, 0xF, 8, true);

    *(int*)(self + 0x40) = 0;
    *(unsigned char**)(self + 0x3C) = lbl_23_section4_22C;
    *(int*)(self + 0x44) = 0;

    memset(self + 0x5C, 0, 0x380);
    sprintf(self + 0x5C, (char*)p + 0x14);
    sprintf(self + 0x9C, (char*)p + 0x2C);
    sprintf(self + 0xDC, (char*)p + 0x44);
    sprintf(self + 0x11C, (char*)p + 0x5C);
    sprintf(self + 0x15C, (char*)p + 0x74);
    sprintf(self + 0x19C, (char*)p + 0x8C);
    sprintf(self + 0x1DC, (char*)p + 0xA4);
    sprintf(self + 0x21C, (char*)p + 0xBC);
    sprintf(self + 0x25C, (char*)p + 0xD4);
    sprintf(self + 0x29C, (char*)p + 0xEC);
    sprintf(self + 0x2DC, (char*)p + 0x104);
    sprintf(self + 0x31C, (char*)p + 0x11C);
    sprintf(self + 0x35C, (char*)p + 0x134);
    sprintf(self + 0x39C, (char*)p + 0x14C);

    *(int*)(self + 0x48) = 0;
    *(int*)(self + 0x4C) = 0;
    *(int*)(self + 0x50) = 0;
    *(int*)(self + 0x3DC) = 0;
    *(int*)(self + 0x3E0) = 0;
    return self;
}
#pragma pop
