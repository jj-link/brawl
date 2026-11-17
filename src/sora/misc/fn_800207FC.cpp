#include <types.h>
#pragma force_active on

extern "C" {
void OSReport(const char* fmt, ...);
void OSSleepTicks(u64 ticks);
void fn_8001B8E0(int, int);
void fn_8001B9EC(void* dest, const char* src);
s32 fn_8020A870(void* p);
extern char lbl_804215C8[];
}

extern "C" s32 fn_800207FC(u8* arg0) {
    char buf[0x74];
    s32 retry;
    s32 status;
    const char** list;
    s32 result = 0;
    u32 count;
    u32 i = 0;

    count = *(u32*)(arg0 + 0x8);
    list = *(const char***)(arg0 + 0xC);

    for (; i < count; i++) {
        fn_8001B9EC(buf, *list);
        do {
            status = fn_8020A870(buf);
            retry = 0;
            if ((u32)(status + 3) <= 1) {
                OSSleepTicks((u64)((*(u32*)0x800000F8 >> 2) / 1000) << 4);
                retry = 1;
            } else if (status != -0xC) {
                fn_8001B8E0(status, 0);
            }
        } while (retry != 0);

        if (status == 0) {
            result = 0;
        } else {
            OSReport(lbl_804215C8, status);
        }
        list++;
    }
    return result;
}
