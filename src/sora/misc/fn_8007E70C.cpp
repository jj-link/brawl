#include <types.h>
#pragma force_active on

extern "C" {
extern int OSReceiveMessage(void* queue, void* msg, int flags);
extern int OSSendMessage(void* queue, void* msg, int flags);
extern void OSReport(const char* fmt, ...);
extern void OSSuspendThread(void* thread);
void PrepareReady__Fb(bool flag);
s32 fn_8025C138(s32, s32, s32, s32, s32);
extern char g_thpObject[];
extern char lbl_804546D0[];
extern char* lbl_805A0208;
}

extern "C" s32 fn_8007E70C(u32* arg0) {
    u8* flagp;
    u32* m;
    u32 i;
    void* msg;
    s32 ret;
    u32* sizes = (u32*)((u8*)arg0[0] + 8);
    u8* data = (u8*)arg0[0] + *(u32*)(g_thpObject + 0x6C) * 4 + 8;
    ret = 0;
    OSReceiveMessage(lbl_805A0208 + 0x1320, &msg, 1);
    m = (u32*)msg;
    flagp = (u8*)g_thpObject;
    i = 0;
    while (i < *(u32*)(g_thpObject + 0x6C)) {
        switch (flagp[0x70]) {
        default:
            break;
        case 0: {
            s32 r = fn_8025C138((s32)data, m[0], m[1], m[2], *(s32*)(g_thpObject + 0x9C));
            *(s32*)(g_thpObject + 0xAC) = r;
            if (r != 0) {
                OSReport(lbl_804546D0, r);
                if (*(s32*)(lbl_805A0208 + 0x1378) != 0) {
                    PrepareReady__Fb(0);
                    *(s32*)(lbl_805A0208 + 0x1378) = 0;
                }
                OSSuspendThread(lbl_805A0208 + 8);
            }
            m[3] = arg0[1];
            OSSendMessage(lbl_805A0208 + 0x1340, m, 1);
            ret = (*(s32*)(g_thpObject + 0xD8) < *(s32*)(g_thpObject + 0xE0) + 1)
                      ? (*(s32*)(g_thpObject + 0xE0) + 1 - *(s32*)(g_thpObject + 0xD8))
                      : 0;
            (*(s32*)(g_thpObject + 0xD8))++;
        }
        }
        data += *sizes;
        sizes++;
        flagp++;
        i++;
    }
    if (*(s32*)(lbl_805A0208 + 0x1378) != 0) {
        PrepareReady__Fb(1);
        *(s32*)(lbl_805A0208 + 0x1378) = 0;
    }
    return ret;
}
