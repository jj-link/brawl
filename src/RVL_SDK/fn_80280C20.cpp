#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual s32 slot3(void* buf, s32 size);
};

extern "C" {
s32 fn_80280C20(Object_vptr_0* obj, s32 count) {
    char buf[0x200];
    s32 remaining = count;

    while (remaining != 0) {
        s32 n = remaining > 0x200 ? 0x200 : remaining;
        s32 result = obj->slot3(buf, n);
        if (result == 0) {
            break;
        }
        remaining -= result;
    }

    return count - remaining;
}
}
