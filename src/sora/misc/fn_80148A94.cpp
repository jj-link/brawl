#include <types.h>
#include <revolution/OS/OSMutex.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" {
void fn_80146FCC(int);
void fn_800CFEB8(void*);
void fn_800D53D4(void*, unsigned char);
void fn_800D54DC(void*);
void fn_80143D80(int, unsigned char);
void fn_80145B78(int);
void fn_80145B88(int);
int fn_8033A77C(void*);
int fn_8033A798(void*);
int fn_8033A7DC(void);
unsigned char fn_8033AA14(void);
unsigned char fn_800C851C(void);
void fn_8034E50C(int, void*, int);
void* memcpy(void*, const void*, unsigned long);
int DWC_GetLastErrorEx(int*, int*);
void DWC_ClearError(void);

extern int gUnk805a03d8;
extern int g_NtAIDBitmap;
extern int g_NtMatchingStatus;
extern int lbl_805A03A8;
extern char lbl_8045F7A8[];
extern OSMutex lbl_8049EC30;
extern unsigned char lbl_805A03D0;
extern unsigned char lbl_805A0414;
extern unsigned char lbl_805A0410;
extern void* lbl_805A0434;
extern unsigned char lbl_8059E742;
extern unsigned char lbl_8059E743;
extern unsigned char lbl_8059E744;
extern unsigned char lbl_8059E745;
}

struct Bits7C {
    unsigned char hi : 2;
    unsigned char mid : 4;
    unsigned char lo : 2;
};

struct BitsFCC {
    unsigned int high : 8;
    unsigned int low : 24;
};

extern "C" void fn_80148A94(int arg0, int arg1, int arg2, int arg3) {
    unsigned char lowBits;
    char* base = lbl_8045F7A8;
    int sp10, spC;
    void* buf;

    while (lbl_805A03D0 != 0 &&
           *(unsigned char*)((char*)lbl_805A0434 + 0x33CC) == 0) {
        OSSleepTicks((s64)((*(unsigned int*)0x800000F8 >> 2) / 1000));
    }

    if (gUnk805a03d8 != 7) {
        netReport(base + 0x494);
        *(unsigned char*)((char*)lbl_805A0434 + 0x3413) = 0;
        OSLockMutex(&lbl_8049EC30);

        if (arg0 == 0) {
            int len = fn_8033A798(&buf);
            unsigned char oldFlag = lbl_805A0414;
            lbl_805A0414 = (unsigned char)len;
            memcpy(&lbl_805A0410, buf, (unsigned long)len);

            int bitmap = fn_8033A7DC();
            g_NtAIDBitmap = bitmap;
            unsigned char* initialTask = (unsigned char*)g_muWifiInterfaceTask;
            lowBits = bitmap;
            unsigned char idx = fn_800C851C();
            if (idx == 0xFF) {
                idx = 4;
            }
            unsigned char* obj = initialTask + idx * 0x218;
            ((Bits7C*)(obj + 0xC7))->mid = lowBits;
            lbl_8059E742 = fn_8033A77C(obj);

            netReport(base + 0x2E0, lbl_805A0414, g_NtAIDBitmap);
            if (oldFlag > lbl_805A0414 && lbl_805A0414 == 1) {
                netReport(base + 0x304);
            }

            if (arg1 == 1) {
                if (arg2 == 1) {
                    if (arg3 == 1) {
                        netReport(base + 0x4B0);
                    } else {
                        netReport(base + 0x4E8);
                    }
                    fn_80146FCC(5);
                } else if (arg3 == 1) {
                    netReport(base + 0x52C);
                } else {
                    netReport(base + 0x568);
                }
                OSUnlockMutex(&lbl_8049EC30);
                return;
            }

            unsigned char* ptr;
            int offset;
            int i;
            i = 0;
            ptr = &lbl_805A0410;
            offset = 0;
            for (; i < (int)lbl_805A0414; i++) {
                unsigned char val = *ptr;
                if (val >= 4) {
                    netReport(base + 0x598, 4);
                    OSUnlockMutex(&lbl_8049EC30);
                    return;
                }
                if (val != lbl_8059E742) {
                    fn_8034E50C(
                        val,
                        (void*)(*(int*)((char*)lbl_805A0434 + 0x33C8) + offset),
                        0x2000);
                }
                ptr++;
                offset += 0x2000;
            }

            int diff;
            int newVal = fn_8033A7DC();
            int oldVal = *(int*)((char*)lbl_805A0434 + 0x3404);
            diff = newVal & (oldVal ^ newVal);
            int mask = 1 << lbl_8059E742;
            netReport(base + 0x5C8, newVal, diff, mask);
            int remaining = diff & ~(1 << lbl_8059E742);
            *(int*)((char*)lbl_805A0434 + 0x3404) = newVal;
            unsigned char* task = (unsigned char*)g_muWifiInterfaceTask;
            fn_800CFEB8(task);

            for (unsigned int j = 0; j < 4; j++) {
                if ((1 << (unsigned char)j) & remaining) {
                    netReport(base + 0x5E4, (unsigned char)j);
                    fn_80143D80(lbl_805A03A8, (unsigned char)j);

                    if (arg2 != 0) {
                        unsigned char result = fn_8033AA14();
                        lbl_8059E744 = result;
                        if (result == 0xFF) {
                            lbl_8059E744 = 0xFF;
                            netReport(base + 0x600, lbl_8059E745);
                        } else {
                            netReport(base + 0x630, result);
                        }
                        lbl_8059E745 = lbl_8059E744;
                        lbl_8059E743 = lbl_8059E744;
                        netReport(base + 0x644);
                        if ((task[0xFC9] >> 7) & 1) {
                            fn_80145B88(lbl_805A03A8);
                            fn_80145B78(lbl_805A03A8);
                        }
                        fn_800D54DC(task);
                    } else {
                        if (lbl_805A0414 == 2) {
                            unsigned char result = fn_8033AA14();
                            lbl_8059E744 = result;
                            if (result == 0xFF) {
                                lbl_8059E744 = 0xFF;
                                lbl_8059E743 = 0xFF;
                                netReport(base + 0x600, lbl_8059E745);
                            } else {
                                lbl_8059E745 = result;
                                lbl_8059E743 = result;
                                netReport(base + 0x67C, result);
                                if (!((task[0xFC9] >> 7) & 1)) {
                                    ((BitsFCC*)(task + 0xFCC))->high = 4;
                                }
                            }
                        }
                        if ((task[0xFC9] >> 7) & 1) {
                            netReport(base + 0x6A4);
                            fn_80145B88(lbl_805A03A8);
                            fn_80145B78(lbl_805A03A8);
                        } else {
                            fn_800D53D4(task, (unsigned char)j);
                        }
                    }
                }
            }
            if (g_NtMatchingStatus == 7) {
                fn_80146FCC(8);
            }
        } else if (arg0 == 18) {
            int err = DWC_GetLastErrorEx(&sp10, &spC);
            netReport(base + 0x6D8);
            netReport(base + 0x700, err, sp10, spC);
            netReport(base + 0x73C);
            DWC_ClearError();
            fn_80146FCC(5);
        } else if (arg0 == 11) {
            netReport(base + 0x758);
        } else {
            netReport(base + 0x780, arg0);
        }
        OSUnlockMutex(&lbl_8049EC30);
    }
}
