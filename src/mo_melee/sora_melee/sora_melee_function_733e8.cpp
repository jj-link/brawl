#include <types.h>
#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual u32& slot1(s32 index);
    virtual void slot2();
    virtual s32 slot3();
};
extern "C" void fn_27_733E8(Object_vptr_0* self, s32 start, const u32* src, u32 count) {
    s32 n = (s32)count;
    if (n + start >= self->slot3()) {
        n = self->slot3() - start;
    }
    for (s32 i = 0; i < n; ++i) {
        self->slot1(start + i) = *src;
    }
}