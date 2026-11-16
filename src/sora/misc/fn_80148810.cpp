#pragma force_active on
extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSSleepTicks(int, unsigned int);
void netReport__FPCce(const char*, ...);
void fn_8033A50C(void*, int);
void fn_8034E57C(void*);
void fn_80148664();
void fn_801489D4();
void* getInstance__12ntFriendInfoFv();
void fn_8014CB40();
unsigned long long fn_80351964();
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_80157200(void*, int);
void fn_801578C4();
void fn_80146FCC(int);
void* fn_8014C180();
void fn_8014C26C(void*, int, int);
void fn_800D221C(int, int);
extern unsigned char lbl_805A03D0;
extern void* lbl_805A0434;
extern int gUnk805a03d8;
extern int g_muWifiInterfaceTask;
extern char lbl_8045F7A8[];
extern unsigned char lbl_8049EC30[];
extern int lbl_805A0430;
}

extern "C" void fn_80148810(int arg0, int arg1) {
    char* base = lbl_8045F7A8;
    while (lbl_805A03D0 != 0 && *(unsigned char*)((char*)lbl_805A0434 + 0x33CC) == 0) {
        OSSleepTicks(0, (*(unsigned int*)0x800000F8 >> 2) / 1000);
    }
    if (gUnk805a03d8 != 7) {
        OSLockMutex(lbl_8049EC30);
        netReport__FPCce(base + 0x408, arg0);
        if (arg0 == 0) {
            netReport__FPCce(base + 0x420, arg1);
            *(int*)((char*)lbl_805A0434 + 0x3448) = arg1;
            fn_8033A50C((void*)fn_80148664, 0);
            fn_8034E57C((void*)fn_801489D4);
            unsigned long long* obj = (unsigned long long*)((char*)lbl_805A0434 + 0x3440);
            getInstance__12ntFriendInfoFv();
            fn_8014CB40();
            unsigned long long v = fn_80351964();
            *obj = v;
            netReport__FPCce(base + 0x440, (unsigned int)v, (unsigned int)(v >> 32), (unsigned int)v);
            void* p = __nw__FUlQ25Heaps8HeapType(0x380, 6);
            if (p != 0) {
                p = fn_80157200(p, 6);
            }
            lbl_805A0430 = (int)p;
            fn_801578C4();
            fn_80146FCC(4);
            if (*(unsigned char*)((char*)lbl_805A0434 + 0x343C) != 0) {
                int w = gUnk805a03d8;
                int flag = 0;
                if (w >= 3 && w <= 6) {
                    flag = 1;
                }
                if (flag != 0) {
                    void* q = __nw__FUlQ25Heaps8HeapType(0x48, 6);
                    if (q != 0) {
                        q = fn_8014C180();
                    }
                    if (q != 0) {
                        fn_8014C26C(q, 6, 1);
                    }
                }
            }
            fn_800D221C(g_muWifiInterfaceTask, 1);
        } else {
            netReport__FPCce(base + 0x45C);
        }
        OSUnlockMutex(lbl_8049EC30);
    }
}
