#pragma force_active on
extern void OSInitMutex(void *);
extern void OSInitCond(void *);
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern void fn_801DEF60(void *);

struct SyncData {
    int initialized;
    char mutex[0x18];
    char cond[0x24];
};

extern struct SyncData lbl_805365E0;

void fn_80396E70(void *arg0) {
    struct SyncData *base = &lbl_805365E0;

    if (lbl_805365E0.initialized == 0) {
        OSInitMutex(base->mutex);
        OSInitCond(base->cond);
        base->initialized = 1;
    }

    OSLockMutex(base->mutex);
    *(int *)((char *)arg0 + 0xC) = 0;
    fn_801DEF60(base->cond);
    OSUnlockMutex(base->mutex);
}
