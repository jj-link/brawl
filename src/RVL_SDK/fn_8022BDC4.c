#pragma force_active on
extern void fn_8022E928(const char* fmt, ...);
extern char lbl_8047ED84[];
extern char lbl_804FB4A0[];
extern int fn_8022BC78(int a, int b, int c, int d);
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int enabled);

int fn_8022BDC4(void) {
    int result;
    void* ptr;
    int enabled;
    fn_8022E928(lbl_8047ED84);
    result = fn_8022BC78(1, -1, 0, 1);
    enabled = OSDisableInterrupts();
    ptr = *(void**)(lbl_804FB4A0 + 4);
    OSRestoreInterrupts(enabled);
    if (result == 0 && ptr != 0) {
        ((void (*)(int, int))ptr)(-1, 0);
    }
    return result;
}
