#pragma force_active on
extern "C" {
unsigned int OSDisableInterrupts(void);
unsigned int OSRestoreInterrupts(unsigned int status);

int fn_801C09BC(void* p) {
    unsigned int status = OSDisableInterrupts();
    void* node = *(void**)p;
    int count = 0;
    while (node) {
        node = *(void**)node;
        count++;
    }
    OSRestoreInterrupts(status);
    return count;
}
}
