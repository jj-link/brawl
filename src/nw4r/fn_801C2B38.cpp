#pragma force_active on
extern "C" void* fn_801D6E1C(void*);
extern "C" unsigned int OSDisableInterrupts(void);
extern "C" unsigned int OSRestoreInterrupts(unsigned int status);

extern "C" void fn_801C2B38(void* arg0) {
    unsigned int status = OSDisableInterrupts();
    void* p = fn_801D6E1C(arg0);
    ((unsigned char*)p)[6] = 1;
    ((unsigned char*)p)[7] = 0;
    OSRestoreInterrupts(status);
}
