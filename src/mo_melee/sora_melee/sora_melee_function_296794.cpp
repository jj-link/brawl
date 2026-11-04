#include <types.h>

#pragma force_active on

class Class_33868 {
public:
    virtual void fn_27_1B5500();
    virtual u32& fn_27_1B4EA4(s32 index);
    virtual void fn_27_1B4EB4();
    virtual s32 fn_27_1A6ED0();
};

extern "C" void fn_27_296794(Class_33868* self, s32 start, const u32* src, u32 count) {
    s32 n = (s32)count;
    if (n + start >= self->fn_27_1A6ED0()) {
        n = self->fn_27_1A6ED0() - start;
    }
    for (s32 i = 0; i < n; ++i) {
        self->fn_27_1B4EA4(start + i) = *src;
    }
}
