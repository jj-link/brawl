#pragma force_active on
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);

void fn_80204B90(void *arg0, int arg1) {
    char *p = (char *)arg0;
    void *node;
    int tmp;

    if (*(int *)(p + 0x38) & 4) {
        OSLockMutex(p + 0x20);
    }

    if (arg1 & 1) {
        tmp = *(int *)(p + 0x18);
        *(int *)(p + 0x44) = 0;
        *(int *)(p + 0x3C) = tmp;
    }

    if (arg1 & 2) {
        node = *(void **)(p + 0x44);
        while (node) {
            *(int *)((char *)node + 8) = *(int *)(p + 0x1C);
            node = *(void **)((char *)node + 0xC);
        }
        *(int *)(p + 0x40) = *(int *)(p + 0x1C);
    }

    if (*(int *)(p + 0x38) & 4) {
        OSUnlockMutex(p + 0x20);
    }
}
