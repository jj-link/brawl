#include <types.h>
#pragma force_active on

struct FtToonTriple {
    u32 a;
    u32 b;
    u32 c;
};

extern "C" FtToonTriple fn_121_B4D0(void* self, void* arg);

extern "C" const FtToonTriple& fn_121_B5FC(void* self, void* arg) {
    // Preserve the original reference to the local temporary result.
    return fn_121_B4D0(self, arg);
}
