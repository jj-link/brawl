#include <types.h>
#pragma force_active on
extern "C" {
void* getInstance__15gfTaskSchedulerFv(void);
void fn_80110A40(void* p);
}

extern "C" void fn_801109AC(void* arg0) {
    unsigned char* p = (unsigned char*)arg0;
    s32 flag;
    s32 v;
    if ((((u8)p[0x2C] >> 7) & 1) != 0) {
        flag = 0;
        p[0x2D] &= 0xFFFFFFBF;
        v = *(s32*)getInstance__15gfTaskSchedulerFv();
        if (((s32)(v >> 0x18) == 1) && ((s32)((s32)((v << 8) & 0xFF800000) >> 0x18) < 6))
            flag = 1;
        if (flag != 0) {
            p[0x2C] |= 0x20;
            return;
        }
        fn_80110A40(arg0);
    }
}
