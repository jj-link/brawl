#include <string.h>
#pragma force_active on
#pragma opt_propagation off

extern "C" {
extern const char lbl_50_data_0[];
extern const char lbl_50_data_4B0[];
extern const float lbl_50_rodata_0;

void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);

void* fn_50_A4(void* this_ptr) {
    char* p = (char*)this_ptr;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(this_ptr, lbl_50_data_0, 7);
    *(const char**)(p + 0x3C) = lbl_50_data_4B0;
    memset(p + 0x1D8, 0, 0x204);
    memset(p + 0x3DC, 0, 0x18);
    *(int*)(p + 0x3F4) = 0;
    *(unsigned char*)(p + 0x3F8) = 6;
    *(unsigned char*)(p + 0x408) = 0;
    *(float*)(p + 0x40C) = lbl_50_rodata_0;
    *(float*)(p + 0x410) = lbl_50_rodata_0;
    *(unsigned char*)(p + 0x414) = 6;
    *(unsigned char*)(p + 0x415) = 6;
    *(unsigned char*)(p + 0x416) = 0;
    *(unsigned char*)(p + 0x3F9) = 6;
    *(unsigned char*)(p + 0x3FA) = 6;
    *(unsigned char*)(p + 0x3FB) = 6;
    *(unsigned char*)(p + 0x3FC) = 6;
    *(unsigned char*)(p + 0x3FD) = 6;
    *(int*)(p + 0x400) = 0;
    *(int*)(p + 0x404) = 0;
    *(int*)(p + 0x418) = -1;
    *(int*)(p + 0x41C) = -1;
    *(int*)(p + 0x420) = -1;
    return this_ptr;
}
}
