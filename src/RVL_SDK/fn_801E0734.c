#include <types.h>
#pragma force_active on

int OSIsThreadTerminated(void* thread) {
    u16 state = *(u16*)((char*)thread + 0x2C8);
    int result = 1;
    if (state != 8 && state != 0) {
        result = 0;
    }
    return result != 0;
}
