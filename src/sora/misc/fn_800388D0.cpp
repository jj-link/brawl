#pragma force_active on
extern "C" {
struct Mutex;
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSSleepTicks(int, unsigned);
extern char lbl_80497740[];
void fn_8003C4E4(int, int, void*, int);
int isReady__14gfFileIOHandleCFv(void*);
void __dt__14gfFileIOHandleFv(void*, int);

void fn_800388D0(char* self) {
    if (*(int*)(self + 0x340) != 0) {
        OSLockMutex(lbl_80497740);
        int h = 0;
        fn_8003C4E4(*(int*)(self + 0x340), 0, &h, 1);
        while (!isReady__14gfFileIOHandleCFv(&h)) {
            OSSleepTicks(0, (*(unsigned*)0x800000F8 / 4) / 1000);
        }
        __dt__14gfFileIOHandleFv(&h, -1);
        OSUnlockMutex(lbl_80497740);
    }
}
}
