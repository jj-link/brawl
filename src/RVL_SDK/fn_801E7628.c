#pragma force_active on
typedef struct {
    int usingDebugger;
    unsigned int exceptionMask;
    void* exceptionHook;
    void* exceptionHookLR;
} OSDebugInterface;

extern OSDebugInterface* __DBInterface;

unsigned int fn_801E7628(unsigned char exc) {
    return __DBInterface->exceptionMask & (1 << exc);
}
