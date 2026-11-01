#include <types.h>
#pragma force_active on
class B {
public:
    virtual ~B();
    virtual u32& vf3(s32 index);
    virtual void vf4();
    virtual s32 vf5();
};
extern "C" void fn_27_1BA2A4(B* self, s32 start, const u32* src, u32 count) {
    s32 n = (s32)count;
    if (n + start >= self->vf5()) {
        n = self->vf5() - start;
    }
    for (s32 i = 0; i < n; ++i) {
        self->vf3(start + i) = *src;
    }
}
