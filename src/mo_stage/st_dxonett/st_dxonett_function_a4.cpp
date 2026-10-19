#pragma force_active on
#include <string.h>

extern "C" {
extern const char lbl_78_data_0[];
extern const char lbl_78_data_1D0[];
extern const float lbl_78_rodata_0;

void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void fn_8009ED40(void*, int, int);
void fn_8009F1FC(void*);

struct FlagWord {
    unsigned int mode : 3;
    unsigned int rest : 29;
};

void* fn_78_A4(void* this_ptr) {
    char* p = (char*)this_ptr;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(this_ptr, lbl_78_data_0, 0x2c);
    *(const char**)(p + 0x3C) = lbl_78_data_1D0;
    fn_8009ED40(p + 0x260, 0, 1);
    memset(p + 0x1D8, 0, 0x60);
    memset(p + 0x238, 0, 0x18);
    *(unsigned char*)(p + 0x258) = 4;
    *(unsigned char*)(p + 0x250) = 0;
    *(float*)(p + 0x254) = lbl_78_rodata_0;
    *(unsigned char*)(p + 0x259) = 4;
    *(unsigned char*)(p + 0x25A) = 4;
    *(unsigned char*)(p + 0x25B) = 2;
    *(unsigned char*)(p + 0x25C) = 2;
    fn_8009F1FC(p + 0x260);
    ((FlagWord*)(p + 0x268))->mode = 1;
    *(unsigned char*)(p + 0x2E4) = 2;
    *(unsigned char*)(p + 0x2E5) = 0;
    *(float*)(p + 0x2E8) = lbl_78_rodata_0;
    *(unsigned char*)(p + 0x2EC) = 0;
    *(unsigned char*)(p + 0x2ED) = 0;
    *(unsigned char*)(p + 0x2EE) = 0;
    *(unsigned int*)(p + 0x2F0) = 0;
    *(unsigned int*)(p + 0x2F4) = 0;
    *(unsigned int*)(p + 0x2F8) = 0;
    *(unsigned int*)(p + 0x2FC) = 0;
    return this_ptr;
}
}
