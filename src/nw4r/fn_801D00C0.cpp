#pragma force_active on
extern "C" {
int OSDisableInterrupts();
void OSRestoreInterrupts(int);
int fn_801CFD64(void*);
void fn_801E1790(void*);
}
extern "C" void fn_801D00C0(unsigned char* arg0) {
    int level = OSDisableInterrupts();
    arg0[0x28] = 0;
    while (fn_801CFD64(arg0) == 0 && arg0[0x28] == 0) {
        fn_801E1790(arg0 + 0x2C);
    }
    OSRestoreInterrupts(level);
}
