#include <types.h>
#pragma force_active on
extern "C" s32 fn_27_C8388(void*, s32, s32);
struct Entry {
    s32 f0;
    s32 f1;
    s16 f2;
    s16 f3;
};
struct Slot {
    Entry e;
    s32 pad[2];
};
class Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 v3();
    s32 pad[2];
    Slot arr[1];
};
extern "C" void fn_27_C7CA0(Base* self, const Entry* value) {
    s32 idx = fn_27_C8388(self, self->v3() - 1, -1);
    if (idx >= 0) {
        self->arr[idx].e = *value;
    }
}
