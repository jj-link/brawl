#include <types.h>
#pragma force_active on

extern "C" int strcmp(const char*, const char*);

class gfModuleManager {
public:
    int isLoaded(const char* name);
};

int gfModuleManager::isLoaded(const char* name) {
    u8* base = (u8*)this;
    u8* p = base + 8;
    int ret = 0;
    u32 i = 0;
    do {
        if (strcmp((const char*)(p + 0x1A), name) == 0) {
            ret = (base[i * 0x3C + 0x21] >> 4) & 1;
            break;
        }
        p += 0x3C;
        i++;
    } while (i < 0x10);
    return ret;
}
