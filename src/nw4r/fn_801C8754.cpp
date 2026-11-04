#pragma force_active on
#include <revolution/OS/OSMutex.h>
extern "C" {
extern char lbl_80466B78[];
extern char lbl_80466BB8[];
extern char lbl_80466BA8[];
extern char lbl_804669B8[];
extern char lbl_804669D8[];
void* fn_801BE7BC(void);
void fn_801BE8A0(char*, void*);
void* fn_801C8754(void* arg0) {
    char* self = (char*)arg0;
    char* vtbl1 = lbl_80466B78;
    char* vtbl2 = lbl_80466BB8;
    char* vtbl3 = lbl_80466BA8;
    char* p40 = self + 0x40;
    *(int*)p40 = 0;
    *(int*)(p40 + 4) = 0;
    *(int*)(self + 0x0) = 0;
    *(int*)(self + 0x4) = 0;
    *(char**)(self + 0x8) = vtbl1;
    *(char**)(self + 0xc) = vtbl1 + 0x14;
    *(int*)(self + 0x10) = 0;
    *(int*)(self + 0x14) = 0;
    *(int*)(self + 0x18) = 0;
    *(char**)(self + 0x20) = vtbl2;
    *(char**)(self + 0x24) = self;
    *(char**)(self + 0x28) = vtbl3;
    *(char**)(self + 0x2c) = self;
    *(int*)(self + 0x30) = 0;
    *(int*)(self + 0x34) = 0;
    *(int*)(self + 0x38) = 0;
    *(int*)(self + 0x3c) = 0;
    *(char**)(self + 0x40) = p40;
    *(char**)(self + 0x44) = p40;
    OSInitMutex((OSMutex*)(self + 0x48));
    *(int*)(self + 0x68) = 0;
    int* p68 = (int*)(self + 0x68);
    *(int*)(self + 0x6c) = 0;
    *(int*)(self + 0x60) = 0;
    *(int*)(self + 0x64) = 0;
    *(int*)p68 = (int)p68;
    *(int*)(p68 + 1) = (int)p68;
    OSInitMutex((OSMutex*)(self + 0x70));
    *(int*)(self + 0x90) = 0;
    int* p90 = (int*)(self + 0x90);
    *(int*)(self + 0x94) = 0;
    *(int*)(self + 0x88) = 0;
    *(int*)(self + 0x8c) = 0;
    *(int*)p90 = (int)p90;
    *(int*)(p90 + 1) = (int)p90;
    OSInitMutex((OSMutex*)(self + 0x98));
    *(char**)(self + 0xb0) = lbl_804669D8;
    *(char**)(self + 0xb4) = self + 0xd4;
    *(int*)(self + 0xb8) = 0;
    *(char**)(self + 0xd4) = lbl_804669B8;
    *(int*)(self + 0xd8) = 0;
    *(int*)(self + 0xdc) = 0;
    fn_801BE8A0((char*)fn_801BE7BC(), self);
    return arg0;
}
}