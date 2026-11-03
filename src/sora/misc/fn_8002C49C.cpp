#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern "C" void fn_8002C49C(void* arg) {
    char* base = (char*)arg;
    for (s32 i = 0; i < 8; i++) {
        BOOL enabled = OSDisableInterrupts();
        void* node = *(void**)(base + 0x8C);
        while (node != 0) {
            void* next = *(void**)node;
            *(unsigned char*)((char*)node + 9) = 0;
            node = next;
        }
        OSRestoreInterrupts(enabled);
        base += 0xC;
    }
}
