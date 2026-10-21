#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_117678(void* p, u32 arg);

struct Inner {
    virtual ~Inner();
    virtual void* setIdx(s32 idx);
    virtual void v4();
    virtual s32 getCount();
};

struct Outer {
    u8 pad[8];
    Inner inner;
};

struct Holder {
    u8 pad[0x154];
    Outer* outer;
};

void fn_27_10D4A4(Holder* self, u32 arg) {
    s32 n = self->outer->inner.getCount();
    for (s32 i = 0; i < n; i++) {
        fn_27_117678(*(void**)self->outer->inner.setIdx(i), arg);
    }
}
}
