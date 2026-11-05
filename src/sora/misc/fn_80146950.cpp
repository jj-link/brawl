#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern "C" {
extern OSMutex lbl_8049EC30;
extern char lbl_8045F1D8[];
extern int gUnk805a03d8;
extern int g_NtMatchingStatus;
extern int lbl_805A03E8;
extern void* lbl_805A0390;
extern void* lbl_805A0434;
extern void* g_muWifiInterfaceTask;

s32 fn_801DEDC4(OSMutex* m);
void fn_8014A828(void* param);
void fn_8014B9B4(void* p);
int fn_801400EC(void* p);
int fn_80149910(void* p);
void fn_80146574(void* p);
int fn_80146878(void* p, int v);
void fn_8004A914(void* p, int v);
void* getInstance__8ipSwitchFv(void);
void netReport__FPCce(const char*, ...);
void fn_800C8F68(const char*, ...);
void fn_800CD340(void* p);
unsigned char fn_800C851C(void);

void fn_80146950(void* arg0) {
    char* base = lbl_8045F1D8;
    if (gUnk805a03d8 != 0 && fn_801DEDC4(&lbl_8049EC30) != 0) {
        fn_8014A828(lbl_805A0434);
        if (lbl_805A03E8 != 0 && *(int*)getInstance__8ipSwitchFv() == 1) {
            fn_8004A914(getInstance__8ipSwitchFv(), 0);
        }
        switch (gUnk805a03d8) {
        case 2:
            if (g_NtMatchingStatus >= 5) gUnk805a03d8 = 3;
            break;
        case 4: {
            fn_8014B9B4(lbl_805A0434);
            fn_801400EC(lbl_805A0390);
            if (lbl_805A03E8 == 0) {
                char* addr = (char*)lbl_805A0434 + 0x34ac;
                unsigned char c = *addr;
                *addr = c & 0xFFFFFF00;
                if (c != 0) {
                    netReport__FPCce(base + 0x1a0);
                    fn_80146878(arg0, 1);
                }
            }
            break;
        }
        case 6: {
            fn_8014B9B4(lbl_805A0434);
            fn_801400EC(lbl_805A0390);
            if (lbl_805A03E8 == 0 && g_NtMatchingStatus == 5) {
                gUnk805a03d8 = 3;
                netReport__FPCce(base + 0x1b4);
                fn_800C8F68(base + 0x1c8);
                if (*(unsigned char*)((char*)arg0 + 0x28) != 0) {
                    *(unsigned char*)((char*)arg0 + 0x28) = 0;
                    netReport__FPCce(base + 0x1dc);
                    *(int*)((char*)arg0 + 0x2c) = 0x78;
                    gUnk805a03d8 = 5;
                } else {
                    char* task = (char*)g_muWifiInterfaceTask;
                    unsigned char idx = fn_800C851C();
                    if (idx == 0xFF) idx = 4;
                    char* q = task + idx * 0x218;
                    q[0xc5] = 0;
                }
            }
            break;
        }
        case 5: {
            int v = *(int*)((char*)arg0 + 0x2c) - 1;
            *(int*)((char*)arg0 + 0x2c) = v;
            if (v <= 0) {
                fn_800C8F68(base + 0x1ec);
                gUnk805a03d8 = 3;
                fn_800CD340(g_muWifiInterfaceTask);
            }
            break;
        }
        case 7:
            if (fn_80149910(lbl_805A0434) != 0) {
                fn_80146574(arg0);
                gUnk805a03d8 = 0;
            }
            break;
        }
        OSUnlockMutex(&lbl_8049EC30);
    }
}
}
