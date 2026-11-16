#include <gf/gf_task.h>
#include <stdio.h>
#include <string.h>
#pragma force_active on
extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, gfTask::Category, int, int, bool);
extern char lbl_19_data_130[];
extern char lbl_19_data_4CC[];
}
struct DataFirst { char first; };
#pragma push
#pragma opt_propagation off
extern "C" char* fn_19_630(char* self) {
    char* p = lbl_19_data_130;
    {
        char DataFirst::*first = &DataFirst::first;
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, &(((DataFirst*)p)->*first), gfTask::Category_Menu, 15, 8, true);
    }
    *(int*)(self + 0x40) = 0;
    *(char**)(self + 0x3c) = lbl_19_data_4CC;
    *(int*)(self + 0x44) = 0;
    int index = 0;
    memset(self + 0x4c, 0, 0x960);
    sprintf(self + 0x4c + index++ * 0x30, p + 0xc);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x24);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x3c);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x54);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x68);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x80);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x98);
    sprintf(self + 0x4c + index++ * 0x30, p + 0xb0);
    sprintf(self + 0x4c + index++ * 0x30, p + 0xc4);
    sprintf(self + 0x4c + index++ * 0x30, p + 0xdc);
    sprintf(self + 0x4c + index++ * 0x30, p + 0xf4);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x10c);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x120);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x138);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x150);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x150);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x168);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x184);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x19c);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x1b8);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x1d0);
    sprintf(self + 0x4c + index++ * 0x30, p + 0xc);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x1e8);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x204);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x218);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x234);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x24c);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x264);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x27c);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x27c);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x27c);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x27c);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x290);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x2a8);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x2c0);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x2d4);
    sprintf(self + 0x4c + index++ * 0x30, p + 0xc);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x2ec);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x304);
    sprintf(self + 0x4c + index++ * 0x30, p + 0xc);
    sprintf(self + 0x4c + index++ * 0x30, p + 0xc);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x320);
    sprintf(self + 0x4c + index++ * 0x30, p + 0xc);
    sprintf(self + 0x4c + index++ * 0x30, p + 0xc);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x338);
    sprintf(self + 0x4c + index++ * 0x30, p + 0xc);
    sprintf(self + 0x4c + index++ * 0x30, p + 0x34c);
    sprintf(self + 0x4c + index * 0x30, p + 0x364);
    *(int*)(self + 0x48) = 0;
    *(int*)(self + 0x9ac) = 0;
    *(int*)(self + 0x9b8) = 0;
    *(int*)(self + 0x9bc) = 0;
    return self;
}
#pragma pop
