#pragma force_active on
extern "C" void OSDisableInterrupts();
extern "C" void OSRestoreInterrupts();

extern "C" void fn_801CCA58(int* arg0) {
    OSDisableInterrupts();
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    OSRestoreInterrupts();
}
