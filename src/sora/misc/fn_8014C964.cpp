#pragma force_active on
extern "C" {
void OSLockMutex(void* mutex);
extern char lbl_8049ECA0[];

void fn_8014C964(void) {
    OSLockMutex(lbl_8049ECA0);
}
}
