#include <string.h>
#pragma force_active on

extern "C" {
extern const char lbl_79_data_0[];
extern const char lbl_79_data_F8[];
extern const float lbl_79_rodata_0;
void* fn_79_178(void*);
void* fn_79_198(void*, int);
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void __construct_array(void*, void* (*)(void*), void (*)(void*), unsigned long, int);
void __ct__9gfArchiveFv(void*);

void* fn_79_A4(void* this_ptr) {
    char* p = (char*)this_ptr;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(this_ptr, lbl_79_data_0, 0x2d);
    *(const char**)(p + 0x3C) = lbl_79_data_F8;
    __construct_array(p + 0x6A4, fn_79_178, (void (*)(void*))fn_79_198, 0xC, 6);
    __ct__9gfArchiveFv(p + 0x6F8);
    __ct__9gfArchiveFv(p + 0x778);
    memset(p + 0x1D8, 0, 0x18);
    memset(p + 0x1F4, 0, 0x348);
    memset(p + 0x53C, 0, 0x168);
    *(unsigned char*)(p + 0x6EC) = 1;
    *(float*)(p + 0x1F0) = lbl_79_rodata_0;
    *(int*)(p + 0x6F0) = 0;
    *(int*)(p + 0x6F4) = 0;
    *(int*)(p + 0x7F8) = 0;
    *(int*)(p + 0x7FC) = 0;
    *(int*)(p + 0x800) = 0;
    return this_ptr;
}
}
