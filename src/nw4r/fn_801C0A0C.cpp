#pragma force_active on
typedef unsigned int u32;

extern "C" u32 OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(u32 level);

extern "C" u32 fn_801C0A0C(u32* arg0) {
    u32 level = OSDisableInterrupts();
    u32 ptr = *arg0;
    if (!ptr) {
        OSRestoreInterrupts(level);
        return 0;
    }
    *arg0 = *(u32*)ptr;
    OSRestoreInterrupts(level);
    return ptr;
}
