#pragma force_active on
extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSSleepTicks(int, unsigned int);
void fn_8014113C(void*, void*, void*);
extern unsigned char lbl_805A03D0;
extern void* lbl_805A0434;
extern unsigned char lbl_8049EC30[];
}

extern "C" void fn_801489D4(void* arg0, void* arg1, void* arg2) {
    while (lbl_805A03D0 != 0 && *(unsigned char*)((char*)lbl_805A0434 + 0x33CC) == 0) {
        OSSleepTicks(0, (*(unsigned int*)0x800000F8 >> 2) / 1000);
    }
    OSLockMutex(lbl_8049EC30);
    fn_8014113C(arg0, arg1, arg2);
    OSUnlockMutex(lbl_8049EC30);
}
