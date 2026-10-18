#include <types.h>
#pragma force_active on

class ftEntryManager {
public:
    u8* getEntity(u32 id);
};

extern "C" s32 fn_27_11957C(void*, u32, u32);

extern "C" {
void fn_27_10C788(void* self, s32 flag, s32 unused, u32 arg) {
    if (flag == 0) {
        s32 id = fn_27_11957C(*reinterpret_cast<void**>(reinterpret_cast<u8*>(self) + 0x154), arg, 0);
        if (id != -1) {
            u8* entity = reinterpret_cast<ftEntryManager*>(*reinterpret_cast<void**>(reinterpret_cast<u8*>(self) + 0x154))->getEntity(id);
            entity[0x11] |= 0x80;
        }
    }
}
}
