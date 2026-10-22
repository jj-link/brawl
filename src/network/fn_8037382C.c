#include <types.h>
#pragma force_active on

typedef struct {
    u8* unk0;
    s32 unk4;
    s32 unk8;
} fnStrBuf;

extern void* memcpy(void* dst, const void* src, u32 n);
extern u32 strlen(const char* s);

void fn_8037382C(fnStrBuf* arg0, const char* arg1, s32 arg2) {
    s32 var_r31;

    var_r31 = arg2;
    if (arg1 == 0 || arg2 == 0) {
        return;
    }
    if (arg2 == -1) {
        var_r31 = strlen(arg1);
    }
    memcpy(arg0->unk0 + arg0->unk8, arg1, var_r31);
    arg0->unk8 = arg0->unk8 + var_r31;
}
