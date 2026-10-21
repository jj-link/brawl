#pragma force_active on
extern "C" {
    int OSDisableInterrupts();
    void OSRestoreInterrupts(int level);
    void fn_801E187C(void* p);
}

extern "C" void fn_801D0130(char* arg0) {
    int level = OSDisableInterrupts();
    arg0[0x28] = 1;
    fn_801E187C(arg0 + 0x2C);
    OSRestoreInterrupts(level);
}
