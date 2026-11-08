#include <gf/gf_task.h>
#include <stdio.h>
#include <string.h>
#pragma force_active on
extern "C" {
extern char lbl_31_data_340[];
extern char lbl_31_data_C90[];
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, gfTask::Category, int, int, bool);
}
struct DataFirst { char first; };
#pragma push
#pragma opt_propagation off
extern "C" char* fn_31_2E70(char* self) {
    DataFirst* p = (DataFirst*)lbl_31_data_340;
    char DataFirst::*first = &DataFirst::first;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, &(p->*first), gfTask::Category_Menu, 15, 8, true);
    *(int*)(self + 0x40) = 0;
    *(char**)(self + 0x3c) = lbl_31_data_C90;
    *(int*)(self + 0x44) = 0;
    *(int*)(self + 0x48) = 0;
    *(int*)(self + 0x4c) = 0;
    *(int*)(self + 0x50) = 0;
    *(int*)(self + 0xcdc) = 0;
    *(int*)(self + 0xce0) = 0;
    *(int*)(self + 0xce4) = 0;
    memset(self + 0x54, 0, 0xc80);
    sprintf(self + 0x54, (char*)p + 0xc);
    sprintf(self + 0x94, (char*)p + 0x38);
    sprintf(self + 0xd4, (char*)p + 0x64);
    sprintf(self + 0x114, (char*)p + 0x90);
    sprintf(self + 0x154, (char*)p + 0xbc);
    sprintf(self + 0x194, (char*)p + 0xe8);
    sprintf(self + 0x1d4, (char*)p + 0x114);
    sprintf(self + 0x214, (char*)p + 0x140);
    sprintf(self + 0x254, (char*)p + 0x16c);
    sprintf(self + 0x294, (char*)p + 0x198);
    sprintf(self + 0x2d4, (char*)p + 0x1c4);
    sprintf(self + 0x314, (char*)p + 0x1f0);
    sprintf(self + 0x354, (char*)p + 0x21c);
    sprintf(self + 0x394, (char*)p + 0x248);
    sprintf(self + 0x3d4, (char*)p + 0x274);
    sprintf(self + 0x414, (char*)p + 0x2a0);
    sprintf(self + 0x454, (char*)p + 0x2cc);
    sprintf(self + 0x494, (char*)p + 0x2f8);
    sprintf(self + 0x4d4, (char*)p + 0x324);
    sprintf(self + 0x514, (char*)p + 0x350);
    sprintf(self + 0x554, (char*)p + 0x37c);
    sprintf(self + 0x594, (char*)p + 0x3a8);
    sprintf(self + 0x5d4, (char*)p + 0x3d4);
    sprintf(self + 0x614, (char*)p + 0x400);
    sprintf(self + 0x654, (char*)p + 0x42c);
    sprintf(self + 0x694, (char*)p + 0x458);
    sprintf(self + 0x6d4, (char*)p + 0x484);
    sprintf(self + 0x714, (char*)p + 0x4b0);
    sprintf(self + 0x754, (char*)p + 0x4dc);
    sprintf(self + 0x794, (char*)p + 0x508);
    sprintf(self + 0x7d4, (char*)p + 0x534);
    sprintf(self + 0x814, (char*)p + 0x560);
    sprintf(self + 0x854, (char*)p + 0x58c);
    sprintf(self + 0x894, (char*)p + 0x5b8);
    sprintf(self + 0x8d4, (char*)p + 0x5e4);
    sprintf(self + 0x914, (char*)p + 0x610);
    sprintf(self + 0x954, (char*)p + 0x63c);
    sprintf(self + 0x994, (char*)p + 0x668);
    sprintf(self + 0x9d4, (char*)p + 0x694);
    sprintf(self + 0xa14, (char*)p + 0x6c0);
    sprintf(self + 0xa54, (char*)p + 0x6ec);
    sprintf(self + 0xa94, (char*)p + 0x718);
    sprintf(self + 0xad4, (char*)p + 0x744);
    sprintf(self + 0xb14, (char*)p + 0x770);
    sprintf(self + 0xb54, (char*)p + 0x79c);
    sprintf(self + 0xb94, (char*)p + 0x7c8);
    sprintf(self + 0xbd4, (char*)p + 0x7f4);
    sprintf(self + 0xc14, (char*)p + 0x820);
    *(int*)(self + 0xce8) = 0;
    *(int*)(self + 0xcec) = 0;
    return self;
}
#pragma pop
