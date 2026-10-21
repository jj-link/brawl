#pragma force_active on
extern "C" unsigned int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(unsigned int status);
extern "C" void fn_801E187C(void* p);
extern "C" void fn_8015D29C(void* arg);
extern int lbl_805A0498;

extern "C" void fn_8015D6A8(void* arg0) {
    unsigned int status = OSDisableInterrupts();
    *(unsigned char*)((char*)arg0 + 0x6F) = 1;
    fn_801E187C(&lbl_805A0498);
    OSRestoreInterrupts(status);
    fn_8015D29C(arg0);
}
