#include <types.h>
#pragma force_active on

extern "C" {
BOOL OSDisableInterrupts();
void OSRestoreInterrupts(BOOL status);

void fn_8002C1B0(void* arg0) {
    char* base = (char*)arg0;
    char* node = base + 0x84;
    for (int i = 0; i < 8; i++) {
        BOOL enabled = OSDisableInterrupts();
        void* current = *(void**)(node + 8);
        if (current != NULL) {
            while (current != NULL) {
                void* next = *(void**)current;
                char* prev = node + 8;
                while (*(void**)prev != current) {
                    prev = (char*)*(void**)prev;
                }
                *(void**)prev = next;
                *(u16*)(node + 4) = *(u16*)(node + 4) - 1;
                *(void**)current = *(void**)(base + 0xE8);
                *(void**)(base + 0xE8) = current;
                current = next;
            }
        }
        OSRestoreInterrupts(enabled);
        node += 0xC;
    }
}
}
