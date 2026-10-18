#include <stddef.h>
#pragma force_active on

extern "C" {
    unsigned int GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void*);
    unsigned int fn_88_447C(const void* self) {
        const char* base = (const char*)self;
        if (*(const int*)(base + 0x40)) {
            return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(base + 0x40);
        }
        return 0;
    }
}
