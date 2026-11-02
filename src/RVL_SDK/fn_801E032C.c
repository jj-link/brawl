#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern void fn_801E1790(int *);

int fn_801E032C(char *arg0) {
    int level;
    int count;
    const int *countp;

    countp = (const int *)arg0;
    level = OSDisableInterrupts();
    goto check;
    do {
        fn_801E1790((int *)(arg0 + 4));
    check:
        count = *countp;
    } while (count <= 0);
    *(int *)arg0 = *(int *)arg0 - 1;
    OSRestoreInterrupts(level);
    return count;
}
