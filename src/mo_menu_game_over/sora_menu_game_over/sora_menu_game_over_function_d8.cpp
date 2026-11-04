#pragma force_active on
#include <gf/gf_task.h>
#include <string.h>

extern "C" {
extern char lbl_12_data_0[];
extern unsigned char lbl_12_data_98[];
gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(gfTask*, const char*, gfTask::Category, int, int, bool);
void fn_800B96E8(void*, int);
}

extern "C" void* fn_12_D8(void* p)
{
    unsigned char* self = (unsigned char*)p;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib((gfTask*)p, lbl_12_data_0, gfTask::Category_Menu, 15, 8, true);
    *(void**)(self + 0x3C) = lbl_12_data_98;
    *(int*)(self + 0x44) = 1;
    *(int*)(self + 0x48) = 7;
    *(int*)(self + 0x4C) = 0;
    *(int*)(self + 0x50) = 0;
    *(int*)(self + 0x54) = 0;
    *(int*)(self + 0x58) = 0;
    *(int*)(self + 0x5C) = 0;
    *(int*)(self + 0x60) = 0;
    *(int*)(self + 0x64) = 0;
    self[0x68] = 0;
    *(int*)(self + 0x6C) = -1;
    fn_800B96E8(self + 0x70, 255);
    *(int*)(self + 0x118) = 0;
    *(int*)(self + 0x11C) = 0;
    *(int*)(self + 0x120) = 0;
    self[0x124] = 0;
    *(int*)(self + 0x128) = 0;
    *(int*)(self + 0x12C) = 0;
    self[0x2C] &= ~2;
    *(int*)(self + 0x40) = 0;
    *(int*)(self + 0x4C) = 0;
    memset(self + 0x58, 0, 0x18);
    return p;
}
