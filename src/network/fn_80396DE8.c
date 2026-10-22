#pragma force_active on
typedef struct SyncData {
    int initialized;
    char mutex[0x18];
    char cond[0x14];
    char rest[0x0C];
} SyncData;

extern void OSInitCond(void *);
extern void OSInitMutex(void *);
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern void fn_801DEE84(void *, void *);
extern SyncData lbl_805365E0;

void fn_80396DE8(char *arg0) {
    SyncData *base = &lbl_805365E0;
    if (base->initialized == 0) {
        OSInitMutex(base->mutex);
        OSInitCond(base->cond);
        base->initialized = 1;
    }
    OSLockMutex(base->mutex);
    while (*(int *)(arg0 + 0xC) != 0) {
        fn_801DEE84(base->cond, base->mutex);
    }
    OSUnlockMutex(base->mutex);
}
