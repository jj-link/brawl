#include <types.h>
#pragma force_active on

extern "C" {
void fn_800B6C38(float* out, s32 val, char* str);
void fn_800E1AFC(void* self, s32 idx, s32 param);
int sprintf(char* buf, const char* fmt, ...);
extern char lbl_8059E260[8];
}

extern "C" s32 fn_800E1E28(void* arg0, void* arg1) {
    char buf[8];
    float data[3];
    u32 v = *(u32*)((char*)arg0 + 0x20);

    if (v == 0) {
        return 0;
    }

    sprintf(buf, lbl_8059E260, (v > 5 ? 0 : v - 1) + 2);
    fn_800B6C38(data, *(s32*)((char*)arg0 + 0x88), buf);

    float* out = (float*)arg1;
    out[0] = data[0];
    out[1] = data[1];
    out[2] = data[2];

    fn_800E1AFC(arg0, *(s32*)((char*)arg0 + 0x20) - 1, 0);
    return 1;
}
