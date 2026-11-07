#pragma force_active on
extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSSleepTicks(int, unsigned int);
void netReport__FPCce(const char*, ...);
void fn_80147F10(void*, int, int);
void* getInstance__12ntFriendInfoFv();
void fn_8014CB1C(void*, int);
extern unsigned char lbl_805A03D0;
extern void* lbl_805A0434;
extern int gUnk805a03d8;
extern char lbl_8045FA50[];
extern unsigned char lbl_8049EC30[];
}

extern "C" void fn_801482C8(int arg0, int arg1) {
    while (lbl_805A03D0 != 0 && *(unsigned char*)((char*)lbl_805A0434 + 0x33CC) == 0) {
        OSSleepTicks(0, (*(unsigned int*)0x800000F8 >> 2) / 1000);
    }
    if (gUnk805a03d8 != 7) {
        netReport__FPCce(lbl_8045FA50, arg1, arg0);
        OSLockMutex(lbl_8049EC30);
        fn_80147F10(lbl_805A0434, arg0, 0);
        fn_8014CB1C(getInstance__12ntFriendInfoFv(), 1);
        OSUnlockMutex(lbl_8049EC30);
    }
}
