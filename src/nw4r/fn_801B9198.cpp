#pragma force_active on
extern "C" {
    int OSDisableInterrupts();
    void OSRestoreInterrupts(int level);
    void* fn_801BB188();
    void fn_801BB9AC(void* a, void* b);
}

extern "C" void fn_801B9198(char* arg0) {
    char* base = arg0;
    int level = OSDisableInterrupts();
    int* obj = *(int**)(base + 0x14);
    obj[0] = 0;
    obj[1] = 0;
    void* r = fn_801BB188();
    fn_801BB9AC(r, obj);
    OSRestoreInterrupts(level);
}
