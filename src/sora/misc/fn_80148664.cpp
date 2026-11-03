#pragma force_active on
extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSSleepTicks(int, unsigned int);
void netReport__FPCce(const char*, ...);
int fn_8033A7DC(void);
int fn_8033A798(void*, void*);
unsigned char fn_800C851C(void);
unsigned char fn_8033A77C(void*);
void* memcpy(void*, const void*, unsigned long);
extern int gUnk805a03d8;
extern int g_NtAIDBitmap;
extern int g_muWifiInterfaceTask;
extern char lbl_8045F7A8[];
extern unsigned char lbl_8049EC30[];
extern unsigned char lbl_805A03D0;
extern void* lbl_805A0434;
extern unsigned char lbl_805A0414;
extern unsigned char lbl_805A0410;
extern signed char lbl_8059E742;
}

struct Bits7C {
    unsigned char hi : 2;
    unsigned char mid : 4;
    unsigned char lo : 2;
};

extern "C" void fn_80148664(int arg0, int arg1, int arg2, int arg3, int arg4) {
    unsigned char lowBits;
    unsigned char oldFlag;
    void* buf;
    char* base = lbl_8045F7A8;

    while (lbl_805A03D0 != 0 && *(unsigned char*)((char*)lbl_805A0434 + 0x33CC) == 0) {
        OSSleepTicks(0, (*(unsigned int*)0x800000F8 >> 2) / 1000);
    }
    if (gUnk805a03d8 != 7) {
        if (arg1 != 0) {
            netReport__FPCce(base + 0x380, arg3);
        } else {
            netReport__FPCce(base + 0x3B0, arg3, arg4);
        }
        if (arg0 != 0) {
            netReport__FPCce(base + 0x3F0);
        }
        OSLockMutex(lbl_8049EC30);
        int v = fn_8033A7DC();
        void* p = lbl_805A0434;
        *(int*)((char*)p + 0x3404) = v;
        int len = fn_8033A798(&buf, p);
        oldFlag = lbl_805A0414;
        lbl_805A0414 = len;
        memcpy(&lbl_805A0410, buf, len);
        int bitmap = fn_8033A7DC();
        g_NtAIDBitmap = bitmap;
        lowBits = bitmap;
        int task = g_muWifiInterfaceTask;
        unsigned char idx = fn_800C851C();
        if (idx == 0xFF) {
            idx = 4;
        }
        unsigned char* obj = (unsigned char*)(task + idx * 0x218);
        ((Bits7C*)(obj + 0xC7))->mid = lowBits;
        lbl_8059E742 = fn_8033A77C(obj);
        netReport__FPCce(base + 0x2E0, lbl_805A0414, g_NtAIDBitmap);
        if (oldFlag > lbl_805A0414 && lbl_805A0414 == 1) {
            netReport__FPCce(base + 0x304);
        }
        *(unsigned char*)((char*)lbl_805A0434 + 0x34AA) |= 1 << arg3;
        OSUnlockMutex(lbl_8049EC30);
    }
}
