#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_28_rodata_94;
extern char lbl_28_data_1A4[];
extern char lbl_28_data_1A8[];
void setUpdateRate__16gfModelAnimationFf(void* anim, float rate);
void printIndex__5MuMsgFUlUlPv(void* msg, u32 a, u32 b, void* c);
void printf__5MuMsgFUlPCce(void* msg, u32 index, const char* fmt, ...);
void changeNodeAnimNIf__8MuObjectFPCc(void* obj, const char* name);

void fn_28_25B8(char* self) {
    setUpdateRate__16gfModelAnimationFf(*(void**)(*(char**)(self + 0x148) + 0x14), lbl_28_rodata_94);
    printIndex__5MuMsgFUlUlPv(*(void**)(self + 0x12c), 0xc, 2, 0);
    printf__5MuMsgFUlPCce(*(void**)(self + 0x12c), 0xd, lbl_28_data_1A4);
    *(u32*)(self + 0x48) = 0;
    *(u32*)(self + 0x220) = 0;
    *(u32*)(self + 0x2d8) = 0;
    changeNodeAnimNIf__8MuObjectFPCc(*(void**)(self + 0x14c), lbl_28_data_1A8);
}
}
