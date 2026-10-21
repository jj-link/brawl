#pragma force_active on
extern "C" void OSDisableInterrupts();
extern "C" void OSRestoreInterrupts();

extern "C" void fn_801C0A68(void** a, void** b) {
    OSDisableInterrupts();
    *b = *a;
    *a = b;
    OSRestoreInterrupts();
}
