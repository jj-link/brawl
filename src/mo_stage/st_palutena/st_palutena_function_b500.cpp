#include <string.h>
#include <stdio.h>
#pragma force_active on

extern "C" {
void* setNode__9grGimmickFv(void* self);
void getNodeIndex__6GroundFPUlUlPCc(void* self, unsigned long* out, unsigned long flag, const char* name);
extern char lbl_67_data_2A10[];
extern char lbl_67_data_2A14[];

void* fn_67_B500(void* self) {
    void* ret = setNode__9grGimmickFv(self);
    char name[0x100];
    for (unsigned int i = 0; i < 0x17; i++) {
        strcpy(name, lbl_67_data_2A10);
        sprintf(name, lbl_67_data_2A14, i + 1);
        getNodeIndex__6GroundFPUlUlPCc(self, *(unsigned long**)((char*)self + 0x168) + i, 0, name);
    }
    return ret;
}
}
