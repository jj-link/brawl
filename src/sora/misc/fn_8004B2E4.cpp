#include <types.h>
#pragma force_active on

extern "C" {
void* memcpy(void* dst, const void* src, unsigned long n);

void fn_8004B2E4(void* base, const void* src, long count) {
    if (count == 0) {
        return;
    }
    if ((unsigned long)count > 4) {
        return;
    }
    memcpy(static_cast<char*>(base) + 0x4c, src, count << 2);
}
}
