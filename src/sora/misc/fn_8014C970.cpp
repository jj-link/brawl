#pragma force_active on
extern "C" {
void OSUnlockMutex(void* mutex);
extern char lbl_8049ECA0[];
void fn_8014C970(void);
}

extern "C" void fn_8014C970(void) {
    OSUnlockMutex(lbl_8049ECA0);
}
