#pragma force_active on
extern void fn_801D6E1C();
extern void OSResumeThread();

void fn_801E1A5C(void) {
    fn_801D6E1C();
    OSResumeThread();
}
