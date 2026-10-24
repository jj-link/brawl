#pragma force_active on
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);

int fn_80204D7C(void *arg0, int arg1) {
    char *p = (char *)arg0;
    void *node;
    int result;
    unsigned int arg1u = (unsigned int)arg1;

    if (*(int *)(p + 0x38) & 4) {
        OSLockMutex(p + 0x20);
    }

    node = *(void **)(p + 0x44);
    if (arg1 != 0) {
        while (node) {
            if (*(unsigned int *)node == arg1u) {
                break;
            }
            node = *(void **)((char *)node + 0xC);
        }
    }

    if (!node) {
        result = 0;
    } else {
        result = 1;
        *(int *)(p + 0x3C) = *(int *)((char *)node + 4);
        *(int *)(p + 0x40) = *(int *)((char *)node + 8);
        *(void **)(p + 0x44) = *(void **)((char *)node + 0xC);
    }

    if (*(int *)(p + 0x38) & 4) {
        OSUnlockMutex(p + 0x20);
    }
    return result;
}
