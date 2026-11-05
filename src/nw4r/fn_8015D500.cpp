#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on
extern "C" {
extern OSMutex lbl_8049ED58;
extern int lbl_805A0498;
int fn_801DEDC4(OSMutex*);
void fn_801E1790(int*);
void fn_801E187C(int*);
int fn_8015D05C(unsigned char*, void*, int);
}
static inline bool acquire(unsigned char* self) {
    BOOL enabled = OSDisableInterrupts();
    while (!fn_801DEDC4(&lbl_8049ED58)) {
        fn_801E1790(&lbl_805A0498);
        if (self[0x6f]) {
            OSRestoreInterrupts(enabled);
            return false;
        }
    }
    OSRestoreInterrupts(enabled);
    return true;
}
static inline void release() {
    BOOL enabled = OSDisableInterrupts();
    OSUnlockMutex(&lbl_8049ED58);
    fn_801E187C(&lbl_805A0498);
    OSRestoreInterrupts(enabled);
}
extern "C" int fn_8015D500(unsigned char* self, void* buf, int len) {
    if (!acquire(self)) return -3;
    int result = fn_8015D05C(self, buf, len);
    release();
    return result;
}