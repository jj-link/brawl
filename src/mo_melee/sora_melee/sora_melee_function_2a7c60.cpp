#include <types.h>
#pragma force_active on
struct Item { u8 pad[0x8C8]; u32 id; };
class Inner {
public:
    virtual void v0();
    virtual Item** get(s32 index);
    virtual void v2();
    virtual s32 count();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void erase(s32 index);
};
struct Outer { u8 pad[0x6D8]; Inner inner; };
extern "C" void fn_27_2A7970(void*, Item*, s32, s32);
extern "C" void fn_27_2A7C60(Outer* self, u32 id) {
    if (id != 0xFFFFFFFF) {
        for (s32 i = 0; i < self->inner.count(); i++) {
            Item** slot = self->inner.get(i);
            if (*slot != NULL && id == (*slot)->id) {
                self->inner.erase(i);
                fn_27_2A7970(self, *slot, 0, 1);
                i--;
            }
        }
    }
}